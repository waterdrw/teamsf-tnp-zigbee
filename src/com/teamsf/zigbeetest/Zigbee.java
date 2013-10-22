package com.teamsf.zigbeetest;

public class Zigbee 
{
	static
	{
		System.loadLibrary("zigBee");
	}
	
	public static native void onLEDNative(char dest);
	public static native void offLEDNative(char dest);
	public static native void upDimNative(char dest);
	public static native void downDimNative(char dest);
}