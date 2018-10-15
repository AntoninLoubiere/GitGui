#ifndef BRANCH_GETTER_H
#define BRANCH_GETTER_H

#include "command_executor.h"

#include <QString>

class GitBranch : public CommandExecutor
{
public:
    GitBranch();
    virtual ~GitBranch();

    QString getBrutBranch();

private:
    void runBranchCommand();

    QString m_command;
};

#endif // BRANCH_GETTER_H
