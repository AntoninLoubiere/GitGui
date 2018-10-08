#ifndef STATUSGETTER_H
#define STATUSGETTER_H

#include <QString>
#include <command_executor.h>

class StatusGetter : CommandExecutor
{
public:
    StatusGetter();
    ~StatusGetter();

    QString getBrutStatus();

private:
    void runStatusCommand();

    const QString m_command;
};

#endif // STATUSGETTER_H
