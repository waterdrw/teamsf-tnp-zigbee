LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := zigBee
LOCAL_SRC_FILES := Zigbee.cpp

include $(BUILD_SHARED_LIBRARY)
