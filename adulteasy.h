#ifndef ADULTEASY_H
#define ADULTEASY_H
#include "QFont"
#include "classsudoku.h"
#include <QMainWindow>
#include <fstream>
namespace Ui {
class adulteasy;
}

class adulteasy : public QMainWindow
{
    Q_OBJECT

public:
    explicit adulteasy(QWidget *parent = nullptr);
    ~adulteasy();
    int click_abs=99;
    int click_ord=99;
    int filled[9][9];
    int ind=0; //pour distinguer le debut de la partie et le reset si =0 c'est new game et pour reset =1
    int indsolved=0;
    ofstream easy;
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
    void on_solveit_clicked();


    void UpdateTime();


    void on_menu_clicked();

    void on_erase_clicked();

    void on_indication_clicked();


    void on_save_clicked();

    void on_reload_clicked();


private:
    Ui::adulteasy *ui;
    sudoku test;
    QTimer *timer_s;
    int  counter;



};

#endif // ADULTEASY_H
