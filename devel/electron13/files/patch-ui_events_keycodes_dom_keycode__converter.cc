--- work/electron-13.6.3/src/ui/events/keycodes/dom/keycode_converter.cc.orig	2021-07-15 15:14:08.000000000 -0400
+++ work/electron-13.6.3/src/ui/events/keycodes/dom/keycode_converter.cc	2022-05-30 17:15:46.431115000 -0400
@@ -13,6 +13,8 @@
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS)
 #include <linux/input.h>
+#elif defined(OS_BSD)
+#include <linux/input-event-codes.h>
 #endif
 
 namespace ui {
@@ -24,7 +26,7 @@
 #if defined(OS_WIN)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, win, code }
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, xkb, code }
 #elif defined(OS_APPLE)
@@ -67,7 +69,7 @@
 #undef DOM_KEY_MAP
 #undef DOM_KEY_UNI
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // The offset between XKB Keycode and evdev code.
 constexpr int kXkbKeycodeOffset = 8;
@@ -148,7 +150,7 @@
   return UsbKeycodeToNativeKeycode(static_cast<uint32_t>(code));
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // static
 DomCode KeycodeConverter::XkbKeycodeToDomCode(uint32_t xkb_keycode) {
   // Currently XKB keycode is the native keycode.
