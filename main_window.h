#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>

#include <QString>
#include <QDir>

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
    QWidget* getCurrentTabWidget() const;
    QDir getGitDirectory() const;

public slots:
    void updateStatusText();
    void updateLogText();
    void updateBranchText();

    void testIfDoUpdate();

    // buttons
    void  onChooseFileAddButtonClicked();

    void updateChooseFileAddLabelColor();

private:
    void connectWidget();

    void updateGitDirectory();

    Ui::MainWindow *m_ui;

    QDir m_gitDirectory;
};

#endif // MAINWINDOW_H
