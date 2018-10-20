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
	void updateStatusText();
	void updateLogText();
	void updateBranchText();

	void updateLabelBranch();

	void update();

	// ========== Add Tab ==========

	// buttons
	void onChooseFileAddButtonClicked();

	void updateChooseFileAddLabelColor();

	void onAddFileInGitIndex();

private:
	void connectWidget();

	void connectWidgetAddTab();

	void updateGitDirectory();

	Ui::MainWindow *m_ui;

	QDir m_gitDirectory;

	Git m_git;
};

#endif // MAINWINDOW_H
