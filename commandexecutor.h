#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include <QString>

class CommandExecutor
{
public:
    CommandExecutor();
    virtual ~CommandExecutor();

protected:
    virtual void executeCommand(QString command);
};

#endif // COMMANDEXECUTOR_H
