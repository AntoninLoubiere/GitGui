#include "main_window.h"
#include "ui_main_window.h"

#include "git/git.h"

#include <system_error>
#include <string>

#include <QWidget>
#include <QTableWidget>
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

	connectWidget();

	setGitDirectory("/home/antonin/Documents/Qt/GitGui");
}

MainWindow::~MainWindow()
{
	delete m_ui;
}

void MainWindow::connectWidget()
{
	connect(m_ui->updateStatusButton, SIGNAL(clicked()), this, SLOT(updateStatusText()));
	connect(m_ui->updateLogButton, SIGNAL(clicked()), this, SLOT(updateLogText()));
	connect(m_ui->updateBranchButton, SIGNAL(clicked()), this, SLOT(updateBranchText()));

	connect(m_ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(testIfDoUpdate()));

	connectWidgetAddTab();
}

void MainWindow::connectWidgetAddTab()
{
	connect(m_ui->chooseFileAddButton, SIGNAL(clicked()), this, SLOT(onChooseFileAddButtonClicked()));
	connect(m_ui->chooseFileAddLineEdit, SIGNAL(textChanged(QString)), this, SLOT(updateChooseFileAddLabelColor()));
	connect(m_ui->addFileAddButton, SIGNAL(clicked()), this, SLOT(onAddFileInGitIndex()));
}

void MainWindow::updateGitDirectory()
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

	updateGitDirectory();
}

void MainWindow::setGitDirectory(const QDir& gitDir)
{
	m_gitDirectory = gitDir;

	updateGitDirectory();
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

void MainWindow::testIfDoUpdate()
{
	if (currentTabWidget() == m_ui->tabWidget->widget(2)) { // test if the current widget is the 2 widget (status)
		updateStatusText();
	} else if (currentTabWidget() == m_ui->tabWidget->widget(3)) { // idem but 3 is log
		updateLogText();
	} else if (currentTabWidget() == m_ui->tabWidget->widget((4))) { // idem but 4 is branch
		updateBranchText();
	}
}

void MainWindow::updateStatusText()
{
	// m_ui->statusPlainTextEdit->document()->setPlainText(m_git.getBrutStatus());

	QMap<QString, QString> statusMap = m_git.gitStatus()->getListFile();

	m_ui->statusPlainTextEdit->document()->setPlainText(""); // reset the text

	for (QMap<QString, QString>::Iterator it = statusMap.begin(); it != statusMap.end(); it++) {
		m_ui->statusPlainTextEdit->insertPlainText(it.key());
		m_ui->statusPlainTextEdit->insertPlainText(" -> ");
		m_ui->statusPlainTextEdit->insertPlainText(it.value());
		m_ui->statusPlainTextEdit->insertPlainText("\n");
	}
}

void MainWindow::updateLogText()
{
	m_ui->logPlainTextEdit->document()->setPlainText(m_git.getBrutLog());
}

void MainWindow::updateBranchText()
{
	m_ui->branchPlainTextEdit->document()->setPlainText(m_git.getBrutBranch());
}

void MainWindow::onChooseFileAddButtonClicked()
{
	QString filePath(QFileDialog::getOpenFileName(this, QString(), m_gitDirectory.path()));
	std::string filePathString(filePath.toStdString());

	if (filePath != "" && !m_git.isFileInDir(filePath)) {
		QString errorMessage;
		errorMessage = "Le fichier: ";
		errorMessage += QFileInfo(filePath).baseName();
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
	QFileInfo fileChoose(m_gitDirectory.path() + "/" + text);

	if (text != "" && fileChoose.exists()) {
		// file name is incorrect
		m_ui->chooseFileAddLineEdit->setStyleSheet("color: #000000"); // black
		m_ui->addFileAddButton->setEnabled(true);
	} else {
		// file name is correct
		m_ui->chooseFileAddLineEdit->setStyleSheet("color: #CC0000"); // red
		m_ui->addFileAddButton->setEnabled(false);
	}
}

// ========== Slot add tab ========== //

void MainWindow::onAddFileInGitIndex()
{
	QString fileName = m_ui->chooseFileAddLineEdit->text();

	int reponse = m_git.addFileInGitIndex(fileName);

	if (reponse == 0) {
		m_ui->statusBar->showMessage("Le fichier " + fileName + " a corectement été ajouté", 5000);
	}

	m_ui->chooseFileAddLineEdit->setText("");
}
