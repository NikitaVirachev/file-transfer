#include "filemanager.h"

FileManager::FileManager() {}

void FileManager::copyFile(QString pathA, QString pathB, QString pathC) {
  QDir directory(pathA);
  QStringList files = directory.entryList();
  foreach (QString filename, files) {
    if (!QFile::copy(pathA + filename, pathB + filename)) {
      qDebug() << "Failed to copy file " + filename + " in folder A";
    };
    if (!QFile::copy(pathA + filename, pathC + filename)) {
      qDebug() << "Failed to copy file " + filename + " in folder C";
    };
    QFile::remove(pathA + filename);
  }
}

void FileManager::hello() { qDebug() << "Hello"; }
