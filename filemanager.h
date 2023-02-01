#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QDebug>
#include <QDir>
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

public:
  FileManager(QString pathA, QString pathB, QString pathC);
  void run();
  void stop();

public slots:
  void copyFile();
};

#endif // FILEMANAGER_H
