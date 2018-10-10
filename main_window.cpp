#include "main_window.h"
#include "ui_main_window.h"

#include "status_getter.h"
#include "log_getter.h"
#include "branch_getter.h"

#include <QWidget>
#include <QTableWidget>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    connectWidget();
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

QWidget* MainWindow::getCurrentTabWidget()
{
    return m_ui->tabWidget->currentWidget();
}


void MainWindow::connectWidget()
{
    connect(m_ui->updateStatusButton, SIGNAL(clicked()), this, SLOT(updateStatusText()));
    connect(m_ui->updateLogButton, SIGNAL(clicked()), this, SLOT(updateLogText()));
    connect(m_ui->updateBranchButton, SIGNAL(clicked()), this, SLOT(updateBranchText()));

    connect(m_ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(testIfDoUpdate()));
}

// slot

void MainWindow::testIfDoUpdate()
{
    if (getCurrentTabWidget() == m_ui->tabWidget->widget(2)) { // test if the current widget is the 2 widget (status)
        updateStatusText();
    } else if (getCurrentTabWidget() == m_ui->tabWidget->widget(3)) { // idem but 3 is log
        updateLogText();
    } else if (getCurrentTabWidget() == m_ui->tabWidget->widget((4))) { // idem but 4 is branch
        updateBranchText();
    }
}

void MainWindow::updateStatusText()
{
    StatusGetter statutGetter;

    m_ui->statusPlainTextEdit->document()->setPlainText(statutGetter.getBrutStatus());
}

void MainWindow::updateLogText()
{
    LogGetter logGetter;

    m_ui->logPlainTextEdit->document()->setPlainText(logGetter.getBrutLog());
}

void MainWindow::updateBranchText()
{
    BranchGetter branchGetter;

    m_ui->branchPlainTextEdit->document()->setPlainText(branchGetter.getBrutBranch());
}
