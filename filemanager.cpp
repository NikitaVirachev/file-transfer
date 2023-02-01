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

  QObject::connect(&this->timerDeleteFiles, SIGNAL(timeout()), this,
                   SLOT(deleteOldFiles()));
  this->timerDeleteFiles.start(10000);
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

void FileManager::deleteOldFiles() {
  auto lambda = [](QString pathB) -> void {
    QDir directory(pathB);
    QStringList files = directory.entryList();
    foreach (QString filename, files) {
      QDateTime currentDate = QDateTime::currentDateTime();
      QFileInfo fileInfo = QFileInfo(pathB + filename);
      QDateTime birthFileDate = fileInfo.birthTime();
      if (birthFileDate.daysTo(currentDate) > 14)
        QFile::remove(pathB + filename);
    }
  };
  QFuture<void> future = QtConcurrent::run(lambda, pathB);
}
