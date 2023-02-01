#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QFuture>
#include <QThread>
#include <QTimer>
#include <QtConcurrent/QtConcurrent>

class FileManager : public QObject {
  Q_OBJECT

private:
  QString pathA;
  QString pathB;
  QString pathC;
  QTimer timerCopyFiles;
  QTimer timerDeleteFiles;

public:
  FileManager(QString pathA, QString pathB, QString pathC);
  void run();
  void stop();

public slots:
  void copyFile();
  void deleteOldFiles();
};

#endif // FILEMANAGER_H
