#ifndef GIT_H
#define GIT_H

#include <QString>
#include <QDir>

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

    void addFileInGitIndex(QString relativeFilePath);

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
