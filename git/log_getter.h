#ifndef LOG_GETTER_H
#define LOG_GETTER_H

#include <QString>

#include "command_executor.h"

class LogGetter : CommandExecutor
{
public:
    LogGetter();
    virtual ~LogGetter();

    QString getBrutLog();

private:
    void runLogCommand();

    QString m_command;
};

#endif // LOG_GETTER_H
