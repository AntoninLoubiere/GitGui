#include "log_getter.h"

#include "command_executor.h"

#include <iostream>
#include <fstream>

LogGetter::LogGetter() :
    m_command("cd /home/antonin/Documents/Qt/GitGui && git log")
{
}

LogGetter::~LogGetter()
{
}

QString LogGetter::getBrutLog()
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

void LogGetter::runLogCommand()
{
    executeCommand(m_command);
}
