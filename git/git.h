#ifndef GIT_H
#define GIT_H

#include "log_getter.h"
#include "status_getter.h"
#include "branch_getter.h"

class Git
{
public:
    Git();
private:

    LogGetter m_logGetter;
    StatusGetter m_statusGetter;
    BranchGetter m_branchGetter;
};

#endif // GIT_H
