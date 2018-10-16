#include "command_executor.h"

#include <QDir>
#include "git.h"

#include <iostream>

CommandExecutor::CommandExecutor(Git *git) :
    m_git(git)
{
}

CommandExecutor::~CommandExecutor()
{

}

void CommandExecutor::executeCommand(QString command)
{

    QString dirChange("cd ");
    dirChange += m_git->gitDir().path();
    std::system(dirChange.toStdString().c_str());

    command += " > ";
    command += QDir::currentPath();
    command += "/";
    command += NAME_REPONSE_COMMAND_FILE;

    std::system(command.toStdString().c_str());
}
