#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>

#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QWidget* getCurrentTabWidget();

public slots:
    void updateStatusText();
    void updateLogText();
    void updateBranchText();
    void testIfDoUpdate();

private:
    void connectWidget();

    Ui::MainWindow *m_ui;
};

#endif // MAINWINDOW_H
