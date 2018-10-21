#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>

#include <QString>
#include <QDir>

#include "git/git.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	// setter
	void setGitDirectory(const QString& pathDirGit);
	void setGitDirectory(const QDir& dirGit);

	// getter
	QWidget* currentTabWidget() const;
	QDir gitDirectory() const;

public slots:

	// ========== Update Slot ========== //

	void updateStatusTab();
	void updateLogTab();
	void updateBranchTab();
	void updateCommitTab();

	void updateLabelBranch();

	void update();

	// ========== Add Tab ==========

	// buttons
	void onChooseFileAddButtonClicked();

	void updateChooseFileAddLabelColor();

	void onAddFileInGitIndex();

	// ========== Slot add tab ========== //

	void updateListFileCommitTab();

private:
	void connectWidgets();

	void connectWidgetsAddTab();

	void changeGitDirectory();

	Ui::MainWindow *m_ui;

	QDir m_gitDirectory;

	Git m_git;
};

#endif // MAINWINDOW_H
