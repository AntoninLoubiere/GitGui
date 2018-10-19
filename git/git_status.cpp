#include "git_status.h"

#include "command_executor.h"
#include "git.h"

#include <fstream>
#include <iostream>
#include <string>

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

QMap<QString, QString> GitStatus::getListFile() const
{
	QString reponse = getBrutStatus(), QStringLine, fileName, modifFile;
	QMap<QString, QString> returnMap;
	std::string line;

	unsigned long max = std::string(" ").find(':');

	std::ifstream fileReader(NAME_REPONSE_COMMAND_FILE);

	while (std::getline(fileReader, line))
	{
		QStringLine = QStringLine.fromStdString(line);

		if (line.find(':') != max) {
			int separationPosition = int (line.find(':'));

			modifFile = QStringLine.left(separationPosition - 2).simplified();

			fileName = QStringLine.right(QStringLine.size() - separationPosition).simplified();

			if (m_git->isFileInDir(fileName)) {
				returnMap.insert(fileName, modifFile);
			}

		}
	}

	return returnMap;
}
