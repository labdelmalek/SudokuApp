#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "levelselect.h"
#include "howtoplay.h"

extern int saved;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_Newgame_clicked();

    void on_exit_clicked();

    void on_saved_clicked();

    void on_Howtoplay_clicked();

private:
    Ui::MainWindow *ui;
    levelselect *levelss;
    howtoplay *guide;

};

#endif // MAINWINDOW_H
