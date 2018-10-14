#include "git.h"

#include "log_getter.h"
#include "status_getter.h"
#include "branch_getter.h"

#include <QDir>



Git::Git() :
    m_logGetter(),
    m_statusGetter(),
    m_branchGetter()
{
}

QString Git::getBrutLog()
{
    return m_logGetter.getBrutLog();
}

QString Git::getBrutStatus()
{
    return m_statusGetter.getBrutStatus();
}

QString Git::getBrutBranch()
{
    return m_branchGetter.getBrutBranch();
}

// setter

void Git::setDir(const QDir &gitDir)
{
    m_gitDir = gitDir;
}

void Git::setDir(const QString& pathGitDir)
{
    m_gitDir = QDir(pathGitDir);
}

// getter

LogGetter* Git::logGetter()
{
    return &m_logGetter;
}

StatusGetter* Git::statusGetter()
{
    return  &m_statusGetter;
}

BranchGetter* Git::branchGetter()
{
    return  &m_branchGetter;
}

QDir Git::gitDir()
{
    return m_gitDir;
}
