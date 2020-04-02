package com.wuuklabs.android.playjni;

import android.util.Log;

import java.nio.ByteBuffer;

public class NativeUtil {
    private static final String TAG = "NativeUtil";
    private NativeCallback callback;

    static {
        System.loadLibrary("native-lib");
    }

    public native String testString(String data);

    public native byte[] testByteArray(byte[] data);

    public native int testNativeCallJava(String data);

    public native int testDirectBuff(ByteBuffer buffer , int size);

    public int callBack(String data) {
        Log.d(TAG, "-------callBack " + data);
        if (callback != null) {
            callback.onAudioData(data);
        }
        return 0;
    }

    public void setCallback(NativeCallback callback) {
        this.callback = callback;
    }

    public interface NativeCallback {
        void onAudioData(String data);
    }
}
