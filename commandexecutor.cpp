#include "commandexecutor.h"

#include <iostream>

CommandExecutor::CommandExecutor()
{
}

CommandExecutor::~CommandExecutor()
{

}

void CommandExecutor::executeCommand(QString command)
{
    command += " > reponse.txt";
    std::system(command.toStdString().c_str());
}
