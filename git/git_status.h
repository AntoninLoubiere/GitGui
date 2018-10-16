#ifndef STATUSGETTER_H
#define STATUSGETTER_H

#include <QString>

#include "command_executor.h"

class GitStatus : CommandExecutor
{
public:
    GitStatus(Git *git);
    virtual ~GitStatus();

    QString getBrutStatus();

private:
    void runStatusCommand();

    const QString m_command;
};

#endif // STATUSGETTER_H
