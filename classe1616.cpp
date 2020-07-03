#include "classe1616.h"
#include "ui_classe1616.h"
#include "code16.h"


#include "qstring.h"
#include "QString"
#include "levelselect.h"
#include<QMainWindow>
#include "QFont"
#include "QPalette"
#include "QColor"
#include"QWidget"
#include "mainwindow.h"
#include <QStyle>
#include <QDesktopWidget>
#include "QTableWidgetItem"
#include "QMessageBox"
#include "QLabel"
#include "time.h"
#include"QTimer"
#include "QTime"
classe1616::classe1616(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::classe1616)
{this->setFixedSize(QSize(996, 718));
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );
    ui->setupUi(this);
    QPixmap back(":/resource/BACK.png");
    QIcon backk(back);
    ui->menu->setIcon(backk);
    QPixmap background (":/resource/16x16_background.png");
    ui->background->setPixmap(background);
    QPixmap clock (":/resource/time1.png");
    ui->clocklabel->setScaledContents(true);
    ui->clocklabel->setPixmap(clock);

    ui->newgame->click();
}

classe1616::~classe1616()
{
    delete ui;
}




void classe1616::on_newgame_clicked()
{
    counter = 0;


    QFont font("Helvetica", 20, QFont::Bold);
    ui->indication->setEnabled(true);

    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
                    QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);

            celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter) ;
            celll->setFont(font);
                celll->setText(" ");
 ui->mytable->setItem(i,j,celll);
 filled[i][j]=0;
        }
    }
    int value;
    if(ind==0){
test.clear_grille();
ui->newgame->setText("Reset");
timer_s = new QTimer(this);
QObject::connect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
timer_s->start(1000);
ind=1;}
    else{test.reset_grille();  counter=0;}
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            value=test.element_read(i,j);
                    QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
            celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            celll->setFont(font);
                celll->setText(QString::number(value));
            if(value!=0){
 ui->mytable->setItem(i,j,celll);
 ui->mytable->item(i,j)->setBackgroundColor(Qt::lightGray);
 filled[i][j]=1;}}}
    if(saved==1 && indsave==0){
ui->reload->click();
if(test.indication==0){ui->indication->setStyleSheet("background :transparent");
    ui->indication->setText(" ");}
    int value;
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            value=test.element_read(i,j);
            if(value!=0 && filled[i][j]!=1){
            if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
            else{

                ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
            }}
        }}
    indsave=1;}

}

void classe1616::on_mytable_cellClicked(int row, int column)
{
    click_abs=row;
    click_ord=column;
}
void classe1616::on_number1_clicked()
{if(click_abs!=99){
    QFont font("Helvetica", 20, QFont::Bold);
    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,1);

            celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                celll->setText(QString::number(1));
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=99;
                j=99;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }

 if (test.goodrow(1,click_abs,click_ord)==1 && test.goodcolumn(1,click_abs,click_ord)==1 && test.goodblock(1,click_abs,click_ord)==1){

     ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
}
 else{

     ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
 }
 int value;
 for(i=0;i<16;i++){
     for(j=0;j<16;j++){
         value=test.element_read(i,j);
         if(value!=0 && filled[i][j]!=1){
         if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

             ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
         else{

             ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
         }}
     }}
}}


void classe1616::on_number2_clicked()
{  if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(2));
        if(filled[click_abs][click_ord]!=1){

                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                     test.element_write(click_abs,click_ord,2);

                             celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                                 celll->setText(QString::number(2));
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(2,click_abs,click_ord)==1 && test.goodcolumn(2,click_abs,click_ord)==1 && test.goodblock(2,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void classe1616::on_number3_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(3));
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,3);


                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);

                             celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                                 celll->setText(QString::number(3));
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(3,click_abs,click_ord)==1 && test.goodcolumn(3,click_abs,click_ord)==1 && test.goodblock(3,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void classe1616::on_number4_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(4));


        if(filled[click_abs][click_ord]!=1){
          test.element_write(click_abs,click_ord,4);
                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);

                             celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                                 celll->setText(QString::number(4));
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(4,click_abs,click_ord)==1 && test.goodcolumn(4,click_abs,click_ord)==1 && test.goodblock(4,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}

void classe1616::on_number5_clicked()
{if(click_abs!=99){
    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(5));
        if(filled[click_abs][click_ord]!=1){

                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                     test.element_write(click_abs,click_ord,5);

                             celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                                 celll->setText(QString::number(5));
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(5,click_abs,click_ord)==1 && test.goodcolumn(5,click_abs,click_ord)==1 && test.goodblock(5,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void classe1616::on_number6_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
        celll->setText(QString::number(6));
        celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        if(filled[click_abs][click_ord]!=1){

                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                     test.element_write(click_abs,click_ord,6);

                                 celll->setText(QString::number(6));
                         celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(6,click_abs,click_ord)==1 && test.goodcolumn(6,click_abs,click_ord)==1 && test.goodblock(6,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void classe1616::on_number7_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(7));
        if(filled[click_abs][click_ord]!=1){

                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                     test.element_write(click_abs,click_ord,7);

                                 celll->setText(QString::number(7));
                         celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(7,click_abs,click_ord)==1 && test.goodcolumn(7,click_abs,click_ord)==1 && test.goodblock(7,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}

void classe1616::on_number8_clicked()
{  if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(8));
        if(filled[click_abs][click_ord]!=1){

                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                     test.element_write(click_abs,click_ord,8);

                                 celll->setText(QString::number(8));
                         celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(8,click_abs,click_ord)==1 && test.goodcolumn(8,click_abs,click_ord)==1 && test.goodblock(8,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void classe1616::on_number12_clicked()
{  if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);
int i,j;
    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);

    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(12));
        if(filled[click_abs][click_ord]!=1){

                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
test.element_write(click_abs,click_ord,12);
                                 celll->setText(QString::number(12));
                                 celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(12,click_abs,click_ord)==1 && test.goodcolumn(12,click_abs,click_ord)==1 && test.goodblock(12,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void classe1616::on_number10_clicked()
{  if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
        celll->setText(QString::number(10));
        celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        if(filled[click_abs][click_ord]!=1){

                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                     test.element_write(click_abs,click_ord,10);

                                 celll->setText(QString::number(10));
                         celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(10,click_abs,click_ord)==1 && test.goodcolumn(10,click_abs,click_ord)==1 && test.goodblock(10,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void classe1616::on_number11_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(11));
        if(filled[click_abs][click_ord]!=1){

                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                     test.element_write(click_abs,click_ord,11);

                                 celll->setText(QString::number(11));
                         celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(11,click_abs,click_ord)==1 && test.goodcolumn(11,click_abs,click_ord)==1 && test.goodblock(11,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void classe1616::on_number9_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(9));
        if(filled[click_abs][click_ord]!=1){

                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                     test.element_write(click_abs,click_ord,9);

                                 celll->setText(QString::number(9));
                         celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(9,click_abs,click_ord)==1 && test.goodcolumn(9,click_abs,click_ord)==1 && test.goodblock(9,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void classe1616::on_number13_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);
int i,j;
    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);

    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(13));
        if(filled[click_abs][click_ord]!=1){

                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                     test.element_write(click_abs,click_ord,13);

                                 celll->setText(QString::number(13));
                                 celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(13,click_abs,click_ord)==1 && test.goodcolumn(13,click_abs,click_ord)==1 && test.goodblock(13,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void classe1616::on_number14_clicked()
{  if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
        celll->setText(QString::number(14));
        celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        if(filled[click_abs][click_ord]!=1){

                             test.element_write(click_abs,click_ord,14);
                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);

                                 celll->setText(QString::number(14));
                         celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(14,click_abs,click_ord)==1 && test.goodcolumn(14,click_abs,click_ord)==1 && test.goodblock(14,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void classe1616::on_number15_clicked()
{ if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(15));
        if(filled[click_abs][click_ord]!=1){

                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
  test.element_write(click_abs,click_ord,15);
                                 celll->setText(QString::number(15));
                         celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(15,click_abs,click_ord)==1 && test.goodcolumn(15,click_abs,click_ord)==1 && test.goodblock(15,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void classe1616::on_number16_clicked()
{  if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(16));
        if(filled[click_abs][click_ord]!=1){

                                     QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                     test.element_write(click_abs,click_ord,16);

                                 celll->setText(QString::number(16));
                         celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                 ui->mytable->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=16;
                j=16;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(16,click_abs,click_ord)==1 && test.goodcolumn(16,click_abs,click_ord)==1 && test.goodblock(16,click_abs,click_ord)==1){

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}
}

void classe1616::on_solveit_clicked()
{QFont font("Helvetica", 20, QFont::Bold);
    indsolved=1;

      QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
      ui->timing->setText(QString(" "));

    ui->newgame->setEnabled(false);
     ui->newgame->setText(" ");
     ui->newgame->setStyleSheet("background:transparent");
    ui->number1->setEnabled(false);
    ui->number2->setEnabled(false);

    ui->number3->setEnabled(false);

    ui->number4->setEnabled(false);

    ui->number5->setEnabled(false);

    ui->number6->setEnabled(false);

    ui->number7->setEnabled(false);

    ui->number8->setEnabled(false);
    ui->number9->setEnabled(false);

    ui->number10->setEnabled(false);

    ui->number11->setEnabled(false);

    ui->number12->setEnabled(false);
    ui->number13->setEnabled(false);

    ui->number14->setEnabled(false);

    ui->number15->setEnabled(false);

    ui->number16->setEnabled(false);

    QTableWidgetItem *heo = new QTableWidgetItem;
    heo->setFont(font);

heo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

for(int i=0;i<16;i++){
    for(int j=0;j<16;j++){

    int value=test.element_read_solution1(i,j);
    if(value!=0){
            QTableWidgetItem *heo = new QTableWidgetItem;
            heo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            heo->setFont(font);

            heo->setText(QString::number(value));
        ui->mytable->setItem(i,j,heo);}
    }
}

}
void classe1616::on_menu_clicked()
{    if(indsolved==0){

    QMessageBox::StandardButton reply;
          reply = QMessageBox::question(this, "Save", "Do you want to save the game?",
                                        QMessageBox::Yes|QMessageBox::No);
          if (reply == QMessageBox::Yes) {
    ui->save->click();
          }}
        this->hide();
        parentWidget()->show();

}

void classe1616::on_erase_clicked()
{ if( indsolved==0 && click_abs!=99){
    QFont font("Helvetica", 20, QFont::Bold);
               QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
       celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
test.element_write(click_abs,click_ord,0);
           if(filled[click_abs][click_ord]!=1){
               for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                            if(i==click_abs && j==click_ord){
                                        QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                    celll->setText(" ");
                                    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                            }}}
                    ui->mytable->setItem(click_abs,click_ord,celll);
           }
           int value;
           for(i=0;i<16;i++){
               for(j=0;j<16;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}

}
}

void classe1616::on_indication_clicked()
{
    int i,j;
    QFont font("Helvetica", 20, QFont::Bold);
if(test.indication>0 && click_abs!=99){
        ui->mytable->clearSelection();
                QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);

        celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            celll->setText(QString::number(test.element_read_solution1(click_abs,click_ord)));
            if(filled[click_abs][click_ord]!=1){
                for( i=0;i<16;i++){
                for( j=0;j<16;j++){
                             if(i==click_abs && j==click_ord){
                                         QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                         test.element_write(click_abs,click_ord,test.element_read_solution1(i,j));

                                         celll->setText(QString::number(test.element_read_solution1(click_abs,click_ord)));
                             celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);}}}
                     ui->mytable->setItem(click_abs,click_ord,celll);
                    test.indication--;
                    ui->indication->setText(QString::number(test.indication)+" HINTS LEFT");

                    ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::lightGray);

            }}
if(test.indication==0){ui->indication->setStyleSheet("background :transparent");
ui->indication->setText(" ");}
int ind=0;
    for(i=0;i<16;i++){
        for(j=0;j<16;j++){
if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                ind =0;}
    else{	i=16;
        j=16;
        ind=1;}}}

   if(ind==0){
    QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
}
void classe1616::UpdateTime()
{
    counter++;
    ui->timing->setText(QString("  %1 s  ").arg(counter) );

        }

void classe1616::on_save_clicked()
{
    save1616.open("/Users/hamzaelfarre/Desktop/28april/working/save/save1616.txt");
       save1616.close();

       fstream file("/Users/hamzaelfarre/Desktop/28april/working/save/save1616.txt",ios::app);
       for(int i=0;i<16;i++){
           for(int j=0;j<16;j++){
               file<<test.element_read_backup(i,j);
               if(test.element_read_backup(i,j)>9){
                   file<<" ";
               }
           }
       }
       for(int i=0;i<16;i++){
           for(int j=0;j<16;j++){
               file<<test.element_read(i,j);
               if(test.element_read(i,j)>9){
                   file<<" ";
               }
           }
       }
       for(int i=0;i<16;i++){
           for(int j=0;j<16;j++){
               file<<test.element_read_solution1(i,j);
               if(test.element_read_solution1(i,j)>9){
                   file<<" ";
               }
           }
       }
       file<<test.indication;
}

void classe1616::on_reload_clicked()
{
    QFont font("Helvetica", 20, QFont::Bold);
        int a=0;
        int c;
         fstream file("/Users/hamzaelfarre/Desktop/28april/working/save/save1616.txt");
        string content;
        string k;
        string tm;
        getline(file,content);
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                k=content[a];
                tm=content[a+2];
                if(tm==" "){
                    tm=content[a+1];
                    c=(atoi(k.c_str())*10)+atoi(tm.c_str());
                    a=a+2;
                }
                else {
                     c=atoi(k.c_str());
                }

                test.element_write_backup(i,j,c);
                filled[i][j]=1;
                a++;
            }
        }
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                k=content[a];
                tm=content[a+2];
                if(tm==" "){
                    tm=content[a+1];
                    c=(atoi(k.c_str())*10)+atoi(tm.c_str());
                    a=a+2;
                }
                else {
                     c=atoi(k.c_str());
                }

                test.element_write(i,j,c);
                filled[i][j]=1;
                a++;
            }
        }
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                k=content[a];
                tm=content[a+2];
                if(tm==" "){
                    tm=content[a+1];
                    c=(atoi(k.c_str())*10)+atoi(tm.c_str());
                    a=a+2;
                }
                else {
                     c=atoi(k.c_str());
                }

                test.element_write_solution(i,j,c);
                filled[i][j]=1;
                a++;
            }
        }
        k=content[a];
        test.indication=atoi(k.c_str());
        int value;
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                celll->setTextAlignment(Qt::AlignHCenter||Qt::AlignVCenter) ;
                celll->setFont(font);
                    celll->setText(" ");
     ui->mytable->setItem(i,j,celll);
     filled[i][j]=0;
            }
        }
              file.close();
              for(int i=0;i<16;i++){
                  for(int j=0;j<16;j++){
                      value=test.element_read_backup(i,j);
                              QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                      celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                      celll->setFont(font);
                          celll->setText(QString::number(value));
                      if(value!=0){
           ui->mytable->setItem(i,j,celll);
           ui->mytable->item(i,j)->setBackgroundColor(Qt::lightGray);
           filled[i][j]=1;}}}
              for(int i=0;i<16;i++){
                  for(int j=0;j<16;j++){
                      value=test.element_read(i,j);
                              QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                      celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                      celll->setFont(font);
                          celll->setText(QString::number(value));
                      if(value!=0 && filled[i][j]!=1){
           ui->mytable->setItem(i,j,celll);
           ui->mytable->item(i,j)->setBackgroundColor(Qt::white);
        }}}
}
