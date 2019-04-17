#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFile>
#include <QTextStream>

class FileManager
{
public:
    FileManager();
    ~FileManager();

    void createFile( QString &filepath);
    void saveFile(QString &filepath, QString &text);
    QString openFile(QString filepath);

    QString fileName; // Я думаю это понадобится для компиляции файла
    QString currentPath;
};

#endif // FILEMANAGER_H
