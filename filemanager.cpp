#include "filemanager.h"

FileManager::FileManager(QString pathA, QString pathB, QString pathC) {
  this->pathA = pathA;
  this->pathB = pathB;
  this->pathC = pathC;
}

void FileManager::run() {
  QObject::connect(&this->timerCopyFiles, SIGNAL(timeout()), this,
                   SLOT(copyFile()));
  this->timerCopyFiles.start(10000);
}

void FileManager::stop() { this->timerCopyFiles.stop(); }

void FileManager::copyFile() {
  auto lambda = [](QString pathA, QString pathB, QString pathC) -> void {
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
  };
  QFuture<void> future = QtConcurrent::run(lambda, pathA, pathB, pathC);
}
