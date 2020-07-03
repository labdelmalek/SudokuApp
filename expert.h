#ifndef expert_H
#define expert_H
#include "classsudoku.h"
#include <QMainWindow>
#include <fstream>
namespace Ui {
class expert;
}

class expert : public QMainWindow
{
    Q_OBJECT

public:
    explicit expert(QWidget *parent = nullptr);
    ~expert();
    int click_abs=99;
    int click_ord=99;
    int filled[9][9];
    int ind=0;
    int indsolved=0;

    ofstream hard;
    int indsave=0;

private slots:


    void on_newgame_clicked();

    void on_mytable1_cellClicked(int row, int column);

    void on_number1_clicked();
    void on_number2_clicked();
    void on_number3_clicked();
    void on_number4_clicked();
    void on_number5_clicked();
    void on_number6_clicked();
    void on_number7_clicked();
    void on_number8_clicked();
    void on_number9_clicked();
    void on_solveit_clicked();

    void UpdateTime();

    void on_menu_clicked();

    void on_erase_clicked();

    void on_indication_clicked();

    void on_savegame_clicked();

    void on_reload_clicked();

private:
    Ui::expert *ui;
    sudoku test;
    QTimer *timer_s;
    int  counter;

};

#endif // expert_H
