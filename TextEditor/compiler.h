#ifndef COMPILER_H
#define COMPILER_H

#include <QProcess>

class Compiler
{
public:
  Compiler();

  void runTest(QString filename);

  QProcess *process;
};

#endif // COMPILER_H
