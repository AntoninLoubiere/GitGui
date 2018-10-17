#include "git_log.h"

#include <iostream>
#include <fstream>

GitLog::GitLog(Git *git):
	CommandExecutor(git)
{
}

GitLog::~GitLog()
{
}

QString GitLog::getBrutLog() const
{
	executeCommand(BRUT_LOG_COMMAND);

	std::ifstream logFileReader(NAME_REPONSE_COMMAND_FILE);

	QString fileString = "";
	std::string line = "";

	while (std::getline(logFileReader, line)) {
		fileString += line.c_str();
		fileString += "\n";
	}

	return fileString;
}

