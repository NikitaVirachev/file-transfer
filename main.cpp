#include <QCoreApplication>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QString pathA("D:/test/A/");
  QString pathB("D:/test/B/");
  QString pathC("D:/test/C/");

  QDir directory(pathA);
  QStringList files = directory.entryList();
  foreach(QString filename, files) {
    if (!QFile::copy(pathA + filename, pathB + filename)) {
      qDebug() << "Failed to copy file " + filename + " in folder A";
    };
    if (!QFile::copy(pathA + filename, pathC + filename)) {
      qDebug() << "Failed to copy file " + filename + " in folder C";
    };
    QFile::remove(pathA + filename);
  }

  return a.exec();
}
