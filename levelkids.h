#ifndef LEVELKIDS_H
#define LEVELKIDS_H

#include <QMainWindow>
#include "kidscode.h"
namespace Ui {
class levelkids;
}

class levelkids : public QMainWindow
{
    Q_OBJECT

public:
    explicit levelkids(QWidget *parent = nullptr);
    ~levelkids();
    int click_abs=0;
    int click_ord=99;
    int filled[4][4];
private slots:
        void on_NEWGAME_clicked();

        void on_mytable_cellClicked(int row, int column);

        void on_number1_clicked();

        void on_number2_clicked();

        void on_number3_clicked();

        void on_number4_clicked();

        void on_menu_clicked();

        void on_Solve_it_clicked();

        void on_reset_clicked();

private:
    Ui::levelkids *ui;
    kids kidsgrille;
};

#endif // LEVELKIDS_H
