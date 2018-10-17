#ifndef LOG_GETTER_H
#define LOG_GETTER_H

#include <QString>

#include "command_executor.h"

#define BRUT_LOG_COMMAND "git log"

class GitLog : public CommandExecutor{
public:
    GitLog(Git* git);
    virtual ~GitLog();

    QString getBrutLog() const;
};

#endif // LOG_GETTER_H
