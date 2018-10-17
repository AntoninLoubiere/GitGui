#include "git_branch.h"

#include "command_executor.h"

#include <iostream>
#include <fstream>

GitBranch::GitBranch(Git *git) :
    CommandExecutor (git)
{
}

GitBranch::~GitBranch()
{
}

QString GitBranch::getBrutBranch() const
{
    executeCommand(BRUT_BRANCH_COMMAND);

    std::ifstream branchFileReader(NAME_REPONSE_COMMAND_FILE);

    QString fileString = "";
    std::string line = "";

    while (std::getline(branchFileReader, line)) {
        fileString += line.c_str();
        fileString += "\n";
    }

    return fileString;
}

