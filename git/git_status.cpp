#include "git_status.h"

#include "command_executor.h"

#include <fstream>
#include <iostream>
#include <string>

GitStatus::GitStatus():
    m_command("cd /home/antonin/Documents/Qt/GitGui && git status")
{

}

GitStatus::~GitStatus()
{

}

void GitStatus::runStatusCommand()
{
    executeCommand(m_command);
}

QString GitStatus::getBrutStatus()
{
    runStatusCommand();
    std::ifstream statutFileReader(NAME_REPONSE_COMMAND_FILE);

    QString fileString = "";
    std::string line = "";

    while (std::getline(statutFileReader, line)) {
        fileString += line.c_str();
        fileString += "\n";
    }

    return fileString;
}
