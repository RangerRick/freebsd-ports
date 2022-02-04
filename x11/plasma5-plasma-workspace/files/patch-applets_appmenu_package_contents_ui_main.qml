--- applets/appmenu/package/contents/ui/main.qml.orig	2022-02-03 19:27:15 UTC
+++ applets/appmenu/package/contents/ui/main.qml
@@ -108,7 +108,7 @@ Item {
 
                 Layout.fillWidth: root.vertical
                 Layout.fillHeight: !root.vertical
-                text: activeMenu
+                text: appMenuModel.isBoldAction(activeMenu) ? '<b>'+activeMenu+'</b>' : activeMenu
                 Kirigami.MnemonicData.active: {
                     try {
                         return keystateSource.data.Alt && keystateSource.data.Alt.Pressed
