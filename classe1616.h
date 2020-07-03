#ifndef CLASSE1616_H
#define CLASSE1616_H

#include <QMainWindow>
#include "code16.h"
#include <fstream>

namespace Ui {
class classe1616;
}

class classe1616 : public QMainWindow
{
    Q_OBJECT

public:
    explicit classe1616(QWidget *parent = nullptr);
    ~classe1616();
    int click_abs=99;
    int click_ord=99;
    int filled[16][16];
    int ind=0;
    int indsolved=0;

    ofstream save1616;
    int indsave=0;

private:
    Ui::classe1616 *ui;
    code16 test;
    QTimer *timer_s;
    int  counter;
    code16 su16;



private slots:


    void on_newgame_clicked();

    void on_mytable_cellClicked(int row, int column);

    void on_number1_clicked();
    void on_number2_clicked();
    void on_number3_clicked();
    void on_number4_clicked();
    void on_number5_clicked();
    void on_number6_clicked();
    void on_number7_clicked();
    void on_number8_clicked();
    void on_number9_clicked();
    void on_number10_clicked();
    void on_number11_clicked();
    void on_number12_clicked();
    void on_number13_clicked();
    void on_number14_clicked();
    void on_number15_clicked();
    void on_number16_clicked();
    void on_solveit_clicked();

    void UpdateTime();

    void on_menu_clicked();

    void on_erase_clicked();

    void on_indication_clicked();


    void on_save_clicked();
    void on_reload_clicked();
};

#endif // CLASSE1616_H
