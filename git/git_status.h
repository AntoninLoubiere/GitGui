#ifndef STATUSGETTER_H
#define STATUSGETTER_H

#include <QString>

#include "command_executor.h"

#define STATUS_COMMAND "git status"
#define ADD_COMMAND "git add " // + file path

class GitStatus : CommandExecutor
{
public:
    GitStatus(Git *git);
    virtual ~GitStatus();

    void addFileInGitIndex(QString relativeFilePath);

    QString getBrutStatus();
};

#endif // STATUSGETTER_H
