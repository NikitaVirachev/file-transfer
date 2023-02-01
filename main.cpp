#include "filemanager.h"
#include <QCoreApplication>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  QString pathA("D:/test/A/");
  QString pathB("D:/test/B/");
  QString pathC("D:/test/C/");

  FileManager *fileManager = new FileManager(pathA, pathB, pathC);
  fileManager->run();

  //  QThread *thread = new QThread();
  //  FileManager *fileManager = new FileManager;
  //  fileManager->moveToThread(thread);
  //  QObject::connect(thread, SIGNAL(started()), fileManager,
  //  SLOT(copyFile())); thread->start();

  return a.exec();
}
