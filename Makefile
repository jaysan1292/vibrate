ARCHS = armv7 armv7s arm64
TARGET = iphone:clang:latest:7.0
THEOS_BUILD_DIR = Build
THEOS_PACKAGE_DIR_NAME = Packages

include theos/makefiles/common.mk

TOOL_NAME = vibrate
vibrate_FILES = main.c
vibrate_FRAMEWORKS = CoreFoundation AudioToolbox

include $(THEOS_MAKE_PATH)/tool.mk
