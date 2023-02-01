#include "filemanager.h"
#include <QCoreApplication>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  QString pathA("D:/test/A/");
  QString pathB("D:/test/B/");
  QString pathC("D:/test/C/");

  //  QThread *thread = new QThread();
  //  FileManager *fileManager = new FileManager;
  //  fileManager->moveToThread(thread);
  //  QObject::connect(thread, SIGNAL(started()), fileManager,
  //  SLOT(copyFile())); thread->start();

  QFuture<void> future =
      QtConcurrent::run(FileManager::copyFile, pathA, pathB, pathC);

  return a.exec();
}
