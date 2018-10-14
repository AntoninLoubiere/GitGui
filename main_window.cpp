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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_git()
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

    // buttons
    connect(m_ui->chooseFileAddButton, SIGNAL(clicked()), this, SLOT(onChooseFileAddButtonClicked()));

    connect(m_ui->chooseFileAddLineEdit, SIGNAL(textChanged(QString)), this, SLOT(updateChooseFileAddLabelColor()));
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
    return m_gitDirectory;
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
    m_ui->statusPlainTextEdit->document()->setPlainText(m_git.getBrutStatus());
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

    if (filePath != "" && !filePath.contains(m_gitDirectory.path())) {
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
        m_ui->chooseFileAddLineEdit->setStyleSheet("color: #000000");
        m_ui->addFileAddButton->setEnabled(true);
    } else {
        m_ui->chooseFileAddLineEdit->setStyleSheet("color: #CC0000");
        m_ui->addFileAddButton->setEnabled(false);
    }
}
