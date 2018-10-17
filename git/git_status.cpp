#include "git_status.h"

#include "command_executor.h"

#include <fstream>
#include <iostream>
#include <string>

#include <QDebug>

GitStatus::GitStatus(Git *git):
    CommandExecutor (git)
{
}

GitStatus::~GitStatus()
{

}

QString GitStatus::getBrutStatus() const
{
    executeCommand(BRUT_STATUS_COMMAND);
    std::ifstream statutFileReader(NAME_REPONSE_COMMAND_FILE);

    QString fileString = "";
    std::string line = "";

    while (std::getline(statutFileReader, line)) {
        fileString += line.c_str();
        fileString += "\n";
    }

    return fileString;
}

void GitStatus::addFileInGitIndex(QString relativeFilePath) const
{
    executeCommand(ADD_COMMAND + relativeFilePath);
}
