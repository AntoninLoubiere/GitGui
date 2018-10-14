#include "git.h"

#include "log_getter.h"
#include "status_getter.h"
#include "branch_getter.h"

Git::Git() :
    m_logGetter(),
    m_statusGetter(),
    m_branchGetter()
{

}
