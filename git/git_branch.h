#ifndef BRANCH_GETTER_H
#define BRANCH_GETTER_H

#include <QString>

#include "command_executor.h"
class GitBranch : public CommandExecutor
{
public:
    GitBranch(Git *git);
    virtual ~GitBranch();

    QString getBrutBranch();

private:
    void runBranchCommand();

    QString m_command;
};

#endif // BRANCH_GETTER_H
