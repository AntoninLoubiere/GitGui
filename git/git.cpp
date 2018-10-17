#include "git.h"

#include "git_log.h"
#include "git_status.h"
#include "git_branch.h"

#include <QDir>
#include <QString>



Git::Git() :
	m_gitLog(this),
	m_gitStatus(this),
	m_gitBranch(this),
	m_gitDir()
{
}

Git::Git(QString pathGitDir) :
	m_gitLog(this),
	m_gitStatus(this),
	m_gitBranch(this),
	m_gitDir(pathGitDir)
{
}

Git::Git(QDir dir) :
	m_gitLog(this),
	m_gitStatus(this),
	m_gitBranch(this),
	m_gitDir(dir)
{
}

QString Git::getBrutLog() const
{
	return m_gitLog.getBrutLog();
}

QString Git::getBrutStatus() const
{
	return m_gitStatus.getBrutStatus();
}

QString Git::getBrutBranch() const
{
	return m_gitBranch.getBrutBranch();
}

void Git::addFileInGitIndex(QString relativePath) const
{
	m_gitStatus.addFileInGitIndex(relativePath);
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

QDir Git::gitDir() const
{
	return m_gitDir;
}
