--- applets/appmenu/plugin/appmenumodel.h.orig	2022-02-04 02:59:24 UTC
+++ applets/appmenu/plugin/appmenumodel.h
@@ -51,6 +51,7 @@ class AppMenuModel : public QAbstractListModel (public
     QRect screenGeometry() const;
     void setScreenGeometry(QRect geometry);
     QList<QAction *> flatActionList();
+    Q_INVOKABLE bool isBoldAction(const QString &text);
 
 Q_SIGNALS:
     void requestActivateIndex(int index);
