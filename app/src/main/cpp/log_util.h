//
// Created by hyjfine on 2020-03-10.
//
#include <android/log.h>

#ifndef WUUK_FFMPEG_LOG_UTIL_H
#define WUUK_FFMPEG_LOG_UTIL_H
#define LOG_TAG "JNI Call media"
#define DEBUG 1
#if DEBUG
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#else
#define LOGI(...)
#define LOGD(...)
#define LOGW(...)
#endif
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#endif //WUUK_FFMPEG_LOG_UTIL_H

char *concatString(char *a, char *b) {
    char *newString = (char *) malloc(sizeof(a) + sizeof(b) + 1);
    strcpy(newString, a);
    strcat(newString, b);
    LOGD("------concatString a %s b %s new %s", a, b, newString);
    return newString;
}
