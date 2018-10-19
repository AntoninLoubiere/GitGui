#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include <QString>

#define NAME_REPONSE_COMMAND_FILE "reponse.txt"

class Git;
class CommandExecutor
{
public:
	explicit CommandExecutor(Git *git);
	virtual ~CommandExecutor();
protected:
	virtual int executeCommand(QString command) const;

	Git *m_git;

};

#endif // COMMANDEXECUTOR_H
