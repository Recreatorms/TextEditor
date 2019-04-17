#include "filemanager.h"


FileManager::FileManager()
{
    fileName = "sampleText";
}

FileManager::~FileManager()
{

}

QString FileManager::openFile(QString filepath)
{
    QFile file(filepath);
    QTextStream fstream(&file);
    file.open(QIODevice::ReadOnly);
    QString text = fstream.readAll();
    fileName = file.fileName();
    file.close();
    return text;
}

void FileManager::createFile( QString &filepath)
{
    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    fileName = file.fileName();
    file.close();
}

void FileManager::saveFile(QString &filepath, QString& text)
{
    QFile file(filepath);
    QTextStream fstream(&file);
    file.open(QIODevice::WriteOnly);
    fileName = file.fileName();
    fstream << text;
    file.flush();
    file.close();
}


