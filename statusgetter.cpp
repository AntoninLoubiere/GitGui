#include "statusgetter.h"

StatusGetter::StatusGetter():
    m_command("cd /home/antonin/Documents/Qt/GitGui && git status")
{

}

StatusGetter::~StatusGetter()
{

}

void StatusGetter::runStatusCommand()
{
    executeCommand(m_command);
}
