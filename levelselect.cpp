#include "levelselect.h"
#include "ui_levelselect.h"
#include <QPainter>
#include "QPixmap"
#include "qpixmap.h"
#include  "qpainter.h"
#include "qlabel.h"
#include "QLabel"
#include "mainwindow.h"
#include "qwidget.h"
#include "sudokuadult.h"
#include <QStyle>
#include <QDesktopWidget>
levelselect::levelselect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::levelselect)
{
    ui->setupUi(this);
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );
    if(saved==1){this->setFixedSize(QSize(996, 718));
        QPixmap background(":/resource/savedlevel.png");
        ui->label->setPixmap(background.scaled(996,718,Qt::KeepAspectRatio));
    ui->kidlevel->setEnabled(false);}
    if(saved==0){
this->setFixedSize(QSize(996, 718));
    QPixmap background(":/resource/levelselect.png");

    ui->label->setPixmap(background.scaled(996,718,Qt::KeepAspectRatio));
    ui->kidlevel->setEnabled(true);
    }

}

levelselect::~levelselect()
{
    delete ui;
}


void levelselect::on_kidlevel_clicked()
{
    this->hide();
    kids=new levelkids(this);
    kids->show();
}

void levelselect::on_easy_clicked()
{

    this->hide();
    easy= new adulteasy(this);
    easy->show();
 }

void levelselect::on_medium_clicked()
{

    this->hide();
    medium= new sudokuadult(this);
    medium->show();

}

void levelselect::on_expert_clicked()
{
    this->hide();
    hard= new expert(this);
    hard->show();

}

void levelselect::on_back_clicked()
{
    this->hide();
this->parentWidget()->show();
    saved=0;
}

void levelselect::on_pushButton_clicked()
{
    this->hide();
    su1616= new classe1616(this);
    su1616->show();

}

void levelselect::on_pushButton_2_clicked()
{
    this->hide();
    su1212= new sudoku1212(this);
    su1212->show();

}
