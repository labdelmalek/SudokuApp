#ifndef LEVELSELECT_H
#define LEVELSELECT_H
#include "levelkids.h"
#include "sudokuadult.h"
#include "adulteasy.h"
#include "expert.h"
#include "classe1616.h"
#include "sudoku1212.h"
#include <QMainWindow>
namespace Ui {
class levelselect;
}

class levelselect : public QMainWindow
{
    Q_OBJECT

public:
    explicit levelselect(QWidget *parent = nullptr);
    ~levelselect();

private slots:

    void on_kidlevel_clicked();

    void on_easy_clicked();

    void on_medium_clicked();

    void on_expert_clicked();

    void on_back_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::levelselect *ui;
    levelkids *kids;
   adulteasy *easy;
   sudokuadult *medium;
   expert *hard;
   classe1616 *su1616;
   sudoku1212 *su1212;
int level;


};

#endif // LEVELSELECT_H
