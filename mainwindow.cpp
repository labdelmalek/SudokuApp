#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "QPixmap"
#include "qpixmap.h"
#include  "qpainter.h"
#include "qlabel.h"
#include "QLabel"
#include "levelselect.h"
#include "global.h"
#include <QStyle>
#include <QDesktopWidget>
int saved = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(QSize(996, 718));

    ui->setupUi(this);
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );
    QPixmap background(":/resource/main1.png");
    ui->label->setPixmap(background.scaled(996,718,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{

    delete ui;
}



void MainWindow::on_Newgame_clicked()
{
    this->hide();
    levelss=new levelselect(this);
    levelss->show();
    saved=0;

}

void MainWindow::on_exit_clicked()
{
    this->close();
}

void MainWindow::on_saved_clicked()
{
    this->hide();
    saved=1;

    levelss=new levelselect(this);
    levelss->show();
}


void MainWindow::on_Howtoplay_clicked()
{
    this->hide();
    guide=new howtoplay(this);
    guide->show();
}
