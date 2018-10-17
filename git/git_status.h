#ifndef STATUSGETTER_H
#define STATUSGETTER_H

#include <QString>

#include "command_executor.h"

#define BRUT_STATUS_COMMAND "git status"
#define ADD_COMMAND "git add " // + file path

class GitStatus : CommandExecutor
{
public:
    GitStatus(Git *git);
    virtual ~GitStatus();

    void addFileInGitIndex(QString relativeFilePath) const;

    QString getBrutStatus() const
    ;
};

#endif // STATUSGETTER_H
