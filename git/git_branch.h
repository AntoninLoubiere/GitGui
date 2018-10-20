#ifndef BRANCH_GETTER_H
#define BRANCH_GETTER_H

#include <QString>

#include "command_executor.h"

#define BRUT_BRANCH_COMMAND "git branch"

class GitBranch : public CommandExecutor
{
public:
	GitBranch(Git *git);
	virtual ~GitBranch();

	QString getBrutBranch() const;

	QString getCurrentBranch() const;
};

#endif // BRANCH_GETTER_H
