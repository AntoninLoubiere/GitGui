#include "git_log.h"

#include <iostream>
#include <fstream>

GitLog::GitLog(Git *git):
    CommandExecutor(git),
    m_command("git log")
{
}

GitLog::~GitLog()
{
}

QString GitLog::getBrutLog()
{
    runLogCommand();
    std::ifstream logFileReader(NAME_REPONSE_COMMAND_FILE);

    QString fileString = "";
    std::string line = "";

    while (std::getline(logFileReader, line)) {
        fileString += line.c_str();
        fileString += "\n";
    }

    return fileString;
}

void GitLog::runLogCommand()
{
    executeCommand(m_command);
}
