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
};

#endif // FILEMANAGER_H
