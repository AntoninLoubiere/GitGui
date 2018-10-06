#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

public slots:

    //void onChooseFileTextChanged(QString);

private:
    //void updateFileChooseAddCompleter(QString path);

    Ui::MainWindow *m_ui;
};

#endif // MAINWINDOW_H
