#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include <QString>
class Git; // To remove cyclique inclusion

#define NAME_REPONSE_COMMAND_FILE "reponse.txt"

class CommandExecutor
{
public:
    CommandExecutor(Git *git);
    virtual ~CommandExecutor();

protected:
    virtual void executeCommand(QString command);
};

#endif // COMMANDEXECUTOR_H
