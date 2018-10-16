#include "git_branch.h"

#include "command_executor.h"

#include <iostream>
#include <fstream>

GitBranch::GitBranch(Git *git) :
    CommandExecutor (git),
    m_command("git branch")
{
}

GitBranch::~GitBranch()
{
}

QString GitBranch::getBrutBranch()
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

void GitBranch::runBranchCommand()
{
    executeCommand(m_command);
}
