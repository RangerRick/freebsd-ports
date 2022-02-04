--- applets/appmenu/plugin/appmenumodel.cpp.orig	2022-02-04 02:59:50 UTC
+++ applets/appmenu/plugin/appmenumodel.cpp
@@ -260,6 +260,16 @@ QVariant AppMenuModel::data(const QModelIndex &index, 
     return QVariant();
 }
 
+bool AppMenuModel::isBoldAction(const QString &text)
+{
+    for(auto action : m_menu->actions()) {
+        if(action->text() == text) {
+            return (action->menuRole() == QAction::ApplicationSpecificRole);
+        }
+    }
+    return false;
+}
+
 void AppMenuModel::updateApplicationMenu(const QString &serviceName, const QString &menuObjectPath)
 {
     if (m_serviceName == serviceName && m_menuObjectPath == menuObjectPath) {
@@ -290,6 +300,11 @@ void AppMenuModel::updateApplicationMenu(const QString
         // cache first layer of sub menus, which we'll be popping up
         const auto actions = m_menu->actions();
         for (QAction *a : actions) {
+            QString text(a->text());
+            if(text.length() > 0 && text.front() == QChar('!')) {
+                a->setText(text.right(text.length() - 1));
+                a->setMenuRole(QAction::ApplicationSpecificRole);
+            }
             // signal dataChanged when the action changes
             connect(a, &QAction::changed, this, [this, a] {
                 if (m_menuAvailable && m_menu) {
