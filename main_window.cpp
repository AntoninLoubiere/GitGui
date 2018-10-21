#include "main_window.h"
#include "ui_main_window.h"

#include "git/git.h"

#include "checkbox_file_status.h"

#include <system_error>
#include <string>

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QPalette>
#include <QColor>

#include <QApplication>

#include <QMap>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	m_ui(new Ui::MainWindow),
	m_git("/home/antonin/Documents/Qt/GitGui")
{
	m_ui->setupUi(this);

	connectWidgets();

	setGitDirectory("/home/antonin/Documents/Qt/GitGui");

	update();
}

MainWindow::~MainWindow()
{
	delete m_ui;
}

// connect

void MainWindow::connectWidgets()
{
	connect(m_ui->updateStatusButton, SIGNAL(clicked()), this, SLOT(updateStatusTab()));
	connect(m_ui->updateLogButton, SIGNAL(clicked()), this, SLOT(updateLogTab()));
	connect(m_ui->updateBranchButton, SIGNAL(clicked()), this, SLOT(updateBranchTab()));

	connect(m_ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(update()));

	connectWidgetsAddTab();
}

void MainWindow::connectWidgetsAddTab()
{
	connect(m_ui->chooseFileAddButton, SIGNAL(clicked()), this, SLOT(onChooseFileAddButtonClicked()));
	connect(m_ui->chooseFileAddLineEdit, SIGNAL(textChanged(QString)), this, SLOT(updateChooseFileAddLabelColor()));
	connect(m_ui->addFileAddButton, SIGNAL(clicked()), this, SLOT(onAddFileInGitIndex()));
}

void MainWindow::changeGitDirectory()
{
	if (!m_gitDirectory.exists()) {
		QString errorMessage;
		errorMessage = "The directory ";
		errorMessage += m_gitDirectory.path();
		errorMessage += " doesn't exist";

		throw std::invalid_argument(errorMessage.toStdString());
	}

	m_ui->chooseFileAddLabel->setText(m_gitDirectory.path() + "/");
}

// setter

void MainWindow::setGitDirectory(const QString& pathGitDir)
{
	m_gitDirectory = QDir(pathGitDir);

	changeGitDirectory();
}

void MainWindow::setGitDirectory(const QDir& gitDir)
{
	m_gitDirectory = gitDir;

	changeGitDirectory();
}

// getter

QWidget* MainWindow::currentTabWidget() const
{
	return m_ui->tabWidget->currentWidget();
}

QDir MainWindow::gitDirectory() const
{
	return m_git.gitDir();
}

// slot

void MainWindow::update()
{
	if (currentTabWidget() == m_ui->tabWidget->widget(2)) { // test if the current widget is the 2 widget (status)
		updateStatusTab();
	} else if (currentTabWidget() == m_ui->tabWidget->widget(3)) { // idem but 3 is log
		updateLogTab();
	} else if (currentTabWidget() == m_ui->tabWidget->widget((4))) { // idem but 4 is branch
		updateBranchTab();
	} else if (currentTabWidget() == m_ui->tabWidget->widget(1)) { // idem but 1 is commit tab
		updateCommitTab();
	}

	updateLabelBranch();
}

// ========== Update Slot ========== //

void MainWindow::updateStatusTab()
{
	// set text status
	m_ui->statusPlainTextEdit->document()->setPlainText(m_git.getBrutStatus());
}

void MainWindow::updateLogTab()
{

	// set text log
	m_ui->logPlainTextEdit->document()->setPlainText(m_git.getBrutLog());
}

void MainWindow::updateBranchTab()
{
	// set text log
	m_ui->branchPlainTextEdit->document()->setPlainText(m_git.getBrutBranch());
}

void MainWindow::updateCommitTab()
{
	// remove all checkbox in the layout
	for (CheckBoxFileStatus *checkBoxCurrent : m_listCheckboxCommit) {
		delete checkBoxCurrent;
	}
	m_ui->listFileToCommit->update();
	m_listCheckboxCommit.clear();

	QMap<QString, QString> statusMap = m_git.gitStatus()->getListFile();

	int currentLine = 0;

	for (QMap<QString, QString>::Iterator it = statusMap.begin(); it != statusMap.end(); it++) {
		QString textQCheckBox;
		textQCheckBox += it.key();
		textQCheckBox += " (";
		textQCheckBox += it.value();
		textQCheckBox += ")";

		CheckBoxFileStatus* checkBox = new CheckBoxFileStatus(it.key(), textQCheckBox ,m_ui->listFileToCommit->widget());

		m_listCheckboxCommit.push_back(checkBox);
		m_ui->listFileToCommit->addWidget(checkBox);

		currentLine++;
	}
}

void MainWindow::updateLabelBranch()
{
	m_ui->branchLabel->setText(m_git.getCurrentBranch());
}

// ========== Slot add tab ========== //*

void MainWindow::onChooseFileAddButtonClicked()
{
	QString filePath(QFileDialog::getOpenFileName(this, QString(), m_gitDirectory.path()));
	QFileInfo fileInfo(filePath);

	if (filePath != "" && !filePath.contains(m_git.gitDir().path())) { // test if path of git
																	  // is in the path of file
		QString errorMessage;
		errorMessage = "Le fichier: ";
		errorMessage += fileInfo.baseName();
		errorMessage += " n'est pas dans le dossier du projet (";
		errorMessage += m_gitDirectory.path();
		errorMessage += ") !";
		errorMessage += "\n";
		errorMessage += "Merci de bien vouloir reselectioner un fichier dans le répertoire du projet";
		QMessageBox::critical(this, "Erreur", errorMessage);
	} else {
		m_ui->chooseFileAddLineEdit->setText(filePath.right(filePath.size() - (m_gitDirectory.path().size() + 1)));
	}
}

void MainWindow::updateChooseFileAddLabelColor()
{
	QString text = m_ui->chooseFileAddLineEdit->text();

	if (text != "" && m_git.isFileInDir(text)) {
		// file name is correct
		m_ui->chooseFileAddLineEdit->setStyleSheet("color: #000000"); // black
		m_ui->addFileAddButton->setEnabled(true);
	} else {
		// file name is incorrect
		m_ui->chooseFileAddLineEdit->setStyleSheet("color: #CC0000"); // red
		m_ui->addFileAddButton->setEnabled(false);
	}
}

void MainWindow::onAddFileInGitIndex()
{
	QString fileName = m_ui->chooseFileAddLineEdit->text();

	int reponse = m_git.addFileInGitIndex(fileName);

	if (reponse == 0) {
		m_ui->statusBar->showMessage("Le fichier \"" + fileName + "\" a corectement été ajouté", 5000);
	}

	m_ui->chooseFileAddLineEdit->setText("");
}

// ========== Slot commit tab ========== //

void MainWindow::updateListFileCommitTab()
{

}
