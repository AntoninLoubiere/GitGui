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

    command += " > ";
    command += QDir::currentPath();
    command += "/";
    command += NAME_REPONSE_COMMAND_FILE;

    command = dirChange + " && " + command;

    std::system(command.toStdString().c_str());
}
