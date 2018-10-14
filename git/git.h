#ifndef GIT_H
#define GIT_H

#include "log_getter.h"
#include "status_getter.h"
#include "branch_getter.h"

#include <QString>

class Git
{
public:
    Git();

    QString getBrutLog();
    QString getBrutStatus();
    QString getBrutBranch();



    // getter
    LogGetter* logGetter();
    StatusGetter* statusGetter();
    BranchGetter* branchGetter();

private:

    LogGetter m_logGetter;
    StatusGetter m_statusGetter;
    BranchGetter m_branchGetter;

    QDir gitPath;
};

#endif // GIT_H
