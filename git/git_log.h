#ifndef LOG_GETTER_H
#define LOG_GETTER_H

#include <QString>

#include "command_executor.h"

class GitLog : public CommandExecutor{
public:
    GitLog(Git* git);
    virtual ~GitLog();

    QString getBrutLog();

private:
    void runLogCommand();

    QString m_command;
};

#endif // LOG_GETTER_H
