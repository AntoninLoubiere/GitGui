#include "main_window.h"
#include "ui_mainwindow.h"

#include "status_getter.h"

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
    connect(m_ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(testIfDoUpdate()));
}

// slot

void MainWindow::updateStatusText()
{
    StatusGetter statutGetter;

    m_ui->statusPlainTextEdit->document()->setPlainText(statutGetter.getBrutStatus());
}

void MainWindow::testIfDoUpdate()
{
    if (getCurrentTabWidget() == m_ui->tabWidget->widget(2)) {
        updateStatusText();
    }
}
