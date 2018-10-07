#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "statusgetter.h"

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

void MainWindow::connectWidget()
{
    connect(m_ui->updateStatusButton, SIGNAL(clicked()), this, SLOT(onUpdateStatutButtonClicked()));
}

void MainWindow::onUpdateStatutButtonClicked()
{
    StatusGetter statutGetter;

    m_ui->statusPlainTextEdit->document()->setPlainText(statutGetter.getBrutStatus());
}
