#ifndef GIT_INCLUDE_H
#define GIT_INCLUDE_H

#include <QString>
#include <QDir>

class Git;
class GitBranch;
class GitLog;
class GitStatus;

#include "command_executor.h"

#include "git_log.h"
#include "git_status.h"
#include "git_branch.h"
class Git
{
public:
    Git();
    Git(QDir pathGitDir);

    QString getBrutLog();
    QString getBrutStatus();
    QString getBrutBranch();

    // setter
    void setDir(const QDir &gitDir);
    void setDir(const QString& pathGitDir);

    // getter
    GitLog* gitLog();
    GitStatus* gitStatus();
    GitBranch* gitBranch();

    QDir gitDir();

private:    
    GitLog m_gitLog;
    GitStatus m_gitStatus;
    GitBranch m_gitBranch;

    QDir m_gitDir;
};

#endif // GIT_H
