#include <jni.h>
#include <string>
#include "log_util.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_wuuklabs_android_playjni_NativeUtil_testString(JNIEnv *env, jobject thiz, jstring data) {
    const char *inData = env->GetStringUTFChars(data, 0);
    LOGD("-----testString %s", inData);
    const char *outData = "hi from native";
    char *stringA = const_cast<char *>("hello");
    char *stringB = const_cast<char *>("world");
    char *newString = concatString(stringA, stringB);
    LOGD("-----testString new String %s", newString);
    free(newString);
    return env->NewStringUTF(outData);
}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_wuuklabs_android_playjni_NativeUtil_testByteArray(JNIEnv *env, jobject thiz,
                                                           jbyteArray data) {

    int size = env->GetArrayLength(data);
    jbyte *buf = (jbyte *) malloc(static_cast<size_t>(size));
    memset(buf, 0, static_cast<size_t>(size));
    env->GetByteArrayRegion(data, 0, size, buf);
    LOGD("------testByteArray size %d data[0] %d", size, buf[0]);
    free(buf); // 有malloc就要记得free

    size_t sizeReturn = 8;
    int8_t *bufRet = static_cast<int8_t *>(malloc(sizeReturn));
    memset(bufRet, 8, sizeReturn);
    jbyteArray retArray = env->NewByteArray(sizeReturn);
    env->SetByteArrayRegion(retArray, 0, sizeReturn, bufRet);
    free(bufRet);

    return retArray;
}

static void callback(JNIEnv *envJNI, jobject thiz) {
    const char *methodName = "callBack";
    const char *className = "com/wuuklabs/android/playjni/NativeUtil";
    jclass clazz = envJNI->FindClass(className);

    jmethodID callBack = envJNI->GetMethodID(clazz, methodName, "(Ljava/lang/String;)I");
    const char *retString = "call back form native";

    jint result = envJNI->CallIntMethod(thiz, callBack, envJNI->NewStringUTF(retString));
    LOGD("-----callback %d", result);

}

extern "C"
JNIEXPORT jint JNICALL
Java_com_wuuklabs_android_playjni_NativeUtil_testNativeCallJava(JNIEnv *env, jobject thiz,
                                                                jstring data) {
    callback(env, thiz);
    LOGD("------testCallJava");
    return EXIT_SUCCESS;
}