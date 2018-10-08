#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include <QString>

#define NAME_REPONSE_COMMAND_FILE "reponse.txt"

class CommandExecutor
{
public:
    CommandExecutor();
    virtual ~CommandExecutor();

protected:
    virtual void executeCommand(QString command);
};

#endif // COMMANDEXECUTOR_H
