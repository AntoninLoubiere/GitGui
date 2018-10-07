#include "statusgetter.h"

#include <commandexecutor.h>

#include <fstream>
#include <iostream>
#include <string>

StatusGetter::StatusGetter():
    m_command("cd /home/antonin/Documents/Qt/GitGui && git status")
{

}

StatusGetter::~StatusGetter()
{

}

void StatusGetter::runStatusCommand()
{
    executeCommand(m_command);
}

QString StatusGetter::getBrutStatus()
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
