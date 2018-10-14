#include "branch_getter.h"

#include "command_executor.h"

#include <iostream>
#include <fstream>

BranchGetter::BranchGetter() :
    m_command("cd /home/antonin/Documents/Qt/GitGui && git branch")
{
}

BranchGetter::~BranchGetter()
{
}

QString BranchGetter::getBrutBranch()
{
    runBranchCommand();
    std::ifstream branchFileReader(NAME_REPONSE_COMMAND_FILE);

    QString fileString = "";
    std::string line = "";

    while (std::getline(branchFileReader, line)) {
        fileString += line.c_str();
        fileString += "\n";
    }

    return fileString;
}

void BranchGetter::runBranchCommand()
{
    executeCommand(m_command);
}
