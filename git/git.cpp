#include "git.h"

#include "git_log.h"
#include "git_status.h"
#include "git_branch.h"

#include <QDir>



Git::Git() :
    m_gitLog(),
    m_gitStatus(),
    m_gitBranch()
{
}

QString Git::getBrutLog()
{
    return m_gitLog.getBrutLog();
}

QString Git::getBrutStatus()
{
    return m_gitStatus.getBrutStatus();
}

QString Git::getBrutBranch()
{
    return m_gitBranch.getBrutBranch();
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

GitLog* Git::gitLog()
{
    return &m_gitLog;
}

GitStatus* Git::gitStatus()
{
    return  &m_gitStatus;
}

GitBranch* Git::gitBranch()
{
    return  &m_gitBranch;
}

QDir Git::gitDir()
{
    return m_gitDir;
}
