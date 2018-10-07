#include "commandexecutor.h"

#include <QDir>

#include <iostream>

CommandExecutor::CommandExecutor()
{
}

CommandExecutor::~CommandExecutor()
{

}

void CommandExecutor::executeCommand(QString command)
{
    command += " > ";
    command += QDir::currentPath();
    command += "/";
    command += NAME_REPONSE_COMMAND_FILE;

    std::system(command.toStdString().c_str());
}
