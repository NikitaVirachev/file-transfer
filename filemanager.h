#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QDebug>
#include <QDir>
#include <QThread>

class FileManager : public QObject {
  Q_OBJECT

public:
  FileManager();

public slots:
  static void copyFile(QString pathA, QString pathB, QString pathC);
  static void hello();
};

#endif // FILEMANAGER_H
