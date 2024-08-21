package com.example.myapp;

public class NativeFunctions {
    static {
        System.loadLibrary("native-lib");
    }

    public native void intense();
    public native void memoryRop();
    public native void diskMain();
    public native void networkInterference(String ip, int port);
}
