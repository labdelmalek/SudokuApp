#ifndef SUDOKU1212_H
#define SUDOKU1212_H

#include "code12.h"
#include <fstream>

#include <QMainWindow>

namespace Ui {
class sudoku1212;
}

class sudoku1212 : public QMainWindow
{
    Q_OBJECT

public:
    explicit sudoku1212(QWidget *parent = nullptr);
    ~sudoku1212();
    int click_abs=99;
    int click_ord=99;
    int filled[12][12];
    int ind=0;
    int indsolved=0;
    ofstream save1212;
    int indsave=0;

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
    void on_solveit_clicked();

    void UpdateTime();

    void on_menu_clicked();

    void on_erase_clicked();

    void on_indication_clicked();


    void on_savegame_clicked();

    void on_reload_clicked();

private:
    Ui::sudoku1212 *ui;
    sudoku12 test;
    QTimer *timer_s;
    int  counter;
    sudoku12 su12;


};

#endif // SUDOKU1212_H
