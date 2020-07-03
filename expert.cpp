#include "expert.h"
#include "ui_expert.h"
#include "classsudoku.h"
#include "QString"
#include "levelselect.h"
#include "QTableWidgetItem"
#include "QMessageBox"
#include "QLabel"
#include "time.h"
#include"QTimer"
#include "QTime"
#include "mainwindow.h"
#include <QStyle>
#include <QDesktopWidget>
expert::expert(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::expert)
{
    ui->setupUi(this);
    QPixmap back(":/resource/BACK.png");
    QIcon backk(back);
    ui->menu->setIcon(backk);
  this->setFixedSize(QSize(996, 718));
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );
    QPixmap background (":/resource/expert_background.png");
    ui->background->setPixmap(background);
    QPixmap clock (":/resource/time1.png");
    ui->clocklabel->setScaledContents(true);
    ui->clocklabel->setPixmap(clock);
    ui->newgame->click();
}

expert::~expert()
{
    delete ui;
}

void expert::on_newgame_clicked()
{
    counter = 0;

    QFont font("Helvetica", 20, QFont::Bold);
    ui->indication->setEnabled(true);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
                    QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);

            celll->setTextAlignment(Qt::AlignHCenter||Qt::AlignVCenter) ;
            celll->setFont(font);
                celll->setText(" ");
 ui->mytable1->setItem(i,j,celll);
 filled[i][j]=0;
        }
    }
    int value;
    if(ind==0){
test.clear_grille(2);
ui->newgame->setText("Reset");
counter = 0;
 timer_s = new QTimer(this);
 QObject::connect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
 timer_s->start(1000);
ind=1;}
    else{test.reset_grille();}
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            value=test.element_read(i,j);
                    QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
            celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            celll->setFont(font);
                celll->setText(QString::number(value));
            if(value!=0){
 ui->mytable1->setItem(i,j,celll);
 ui->mytable1->item(i,j)->setBackgroundColor(Qt::lightGray);
 filled[i][j]=1;}}}
    if(saved==1 && indsave==0){
    ui->reload->click();
    if(test.indication==0){ui->indication->setStyleSheet("background :transparent");
    ui->indication->setText(" ");}
    int value;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            value=test.element_read(i,j);
            if(value!=0 && filled[i][j]!=1){
            if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                ui->mytable1->item(i,j)->setBackgroundColor(Qt::white);}
            else{
                ui->mytable1->item(i,j)->setBackgroundColor(Qt::red);
            }}
        }}
    indsave=1;}
}
void expert::on_mytable1_cellClicked(int row, int column)
{
    click_abs=row;
    click_ord=column;
}
void expert::on_number1_clicked()
{if(click_abs!=99){
    QFont font("Helvetica", 20, QFont::Bold);
    ui->mytable1->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(1));
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,1);

                 ui->mytable1->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=9;
                j=9;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }

           if (test.goodrow(1,click_abs,click_ord)==1 && test.goodcolumn(1,click_abs,click_ord)==1 && test.goodblock(1,click_abs,click_ord)==1){
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::white);}
                   else{
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void expert::on_number2_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable1->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(2));
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,2);

                 ui->mytable1->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=9;
                j=9;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(2,click_abs,click_ord)==1 && test.goodcolumn(2,click_abs,click_ord)==1 && test.goodblock(2,click_abs,click_ord)==1){
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::white);}
                   else{
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void expert::on_number3_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable1->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(3));
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,3);

                 ui->mytable1->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=9;
                j=9;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(3,click_abs,click_ord)==1 && test.goodcolumn(3,click_abs,click_ord)==1 && test.goodblock(3,click_abs,click_ord)==1){
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::white);}
                   else{
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}

void expert::on_number4_clicked()
{   if(click_abs!=99){
    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable1->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(4));
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,4);

                 ui->mytable1->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=9;
                j=9;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(4,click_abs,click_ord)==1 && test.goodcolumn(4,click_abs,click_ord)==1 && test.goodblock(4,click_abs,click_ord)==1){
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::white);}
                   else{
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}

void expert::on_number5_clicked()
{if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable1->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(5));
        if(filled[click_abs][click_ord]!=1){
test.element_write(click_abs,click_ord,5);
                 ui->mytable1->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=9;
                j=9;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(5,click_abs,click_ord)==1 && test.goodcolumn(5,click_abs,click_ord)==1 && test.goodblock(5,click_abs,click_ord)==1){
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::white);}
                   else{
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void expert::on_number6_clicked()
{   if(click_abs!=99){


    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable1->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
        celll->setText(QString::number(6));
        celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        if(filled[click_abs][click_ord]!=1){
 test.element_write(click_abs,click_ord,6);
                 ui->mytable1->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=9;
                j=9;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(6,click_abs,click_ord)==1 && test.goodcolumn(6,click_abs,click_ord)==1 && test.goodblock(6,click_abs,click_ord)==1){
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::white);}
                   else{
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void expert::on_number7_clicked()
{   if(click_abs!=99){


    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable1->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(7));
        if(filled[click_abs][click_ord]!=1){
test.element_write(click_abs,click_ord,7);
                 ui->mytable1->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=9;
                j=9;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(7,click_abs,click_ord)==1 && test.goodcolumn(7,click_abs,click_ord)==1 && test.goodblock(7,click_abs,click_ord)==1){
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::white);}
                   else{
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}

void expert::on_number8_clicked()
{  if(click_abs!=99){


    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable1->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(8));
        if(filled[click_abs][click_ord]!=1){
 test.element_write(click_abs,click_ord,8);
                 ui->mytable1->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=9;
                j=9;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(8,click_abs,click_ord)==1 && test.goodcolumn(8,click_abs,click_ord)==1 && test.goodblock(8,click_abs,click_ord)==1){
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::white);}
                   else{
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}
void expert::on_number9_clicked()
{   if(click_abs!=99){


    QFont font("Helvetica", 20, QFont::Bold);
int i,j;
    ui->mytable1->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);

    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(9));
        if(filled[click_abs][click_ord]!=1){
test.element_write(click_abs,click_ord,9);
                 ui->mytable1->setItem(click_abs,click_ord,celll);
        }
        int ind=0;
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
     if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                        ind =0;}
            else{	i=9;
                j=9;
                ind=1;}}}

           if(ind==0){
            QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
           if (test.goodrow(9,click_abs,click_ord)==1 && test.goodcolumn(9,click_abs,click_ord)==1 && test.goodblock(9,click_abs,click_ord)==1){
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{
               ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::white);}
                   else{
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}


void expert::on_solveit_clicked()
{QFont font("Helvetica", 20, QFont::Bold);
    indsolved=1;

      QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
      ui->timing->setText(QString("   %1 s ").arg(0));
      ui->score1->setText(QString("Score: %1 pt ").arg(0));

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

    QTableWidgetItem *heo = new QTableWidgetItem;
    heo->setFont(font);

heo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){

    int value=test.element_read_solution1(i,j);
    if(value!=0){
            QTableWidgetItem *heo = new QTableWidgetItem;
            heo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            heo->setFont(font);

            heo->setText(QString::number(value));
        ui->mytable1->setItem(i,j,heo);}
    }
}
}



void expert::on_menu_clicked()
{
    if(indsolved==0){

    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Save", "Do you want to save the game?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
ui->savegame->click();
      }}
    this->hide();
    parentWidget()->show();
}

void expert::on_erase_clicked()
{if(click_abs!=99 && indsolved==0) {
    QFont font("Helvetica", 20, QFont::Bold);
       ui->mytable1->clearSelection();
               QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
               test.element_write(click_abs,click_ord,0);

       celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

           if(filled[click_abs][click_ord]!=1){
               for(int i=0;i<9;i++){
               for(int j=0;j<9;j++){
                            if(i==click_abs && j==click_ord){
                                        QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                    celll->setText(" ");
                                    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                            }}}
                    ui->mytable1->setItem(click_abs,click_ord,celll);
           }
           int value;
           for(int i=0;i<9;i++){
               for(int j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::white);}
                   else{
                       ui->mytable1->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}
}

void expert::on_indication_clicked()
{
    int i,j;
    QFont font("Helvetica", 20, QFont::Bold);
if(test.indication>0 && click_abs!=99){
        ui->mytable1->clearSelection();
                QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);

        celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            celll->setText(QString::number(test.element_read_solution1(click_abs,click_ord)));
            if(filled[click_abs][click_ord]!=1){

                                         QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                         test.element_write(click_abs,click_ord,test.element_read_solution1(click_abs,click_ord));

                                         celll->setText(QString::number(test.element_read_solution1(click_abs,click_ord)));
                             celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                     ui->mytable1->setItem(click_abs,click_ord,celll);
                    test.indication--;
                    ui->indication->setText(QString::number(test.indication)+" HINTS LEFT");

                    ui->mytable1->item(click_abs,click_ord)->setBackgroundColor(Qt::lightGray);

            }}
if(test.indication==0){ui->indication->setStyleSheet("background :transparent");
ui->indication->setText(" ");}
int ind=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
if ( test.element_read(i,j)!=0 && test.goodcolumn(this->test.element_read(i,j),i,j)==1 && test.goodrow(this->test.element_read(i,j),i,j)==1 && test.goodblock(this->test.element_read(i,j),i,j)==1){
                ind =0;}
    else{	i=9;
        j=9;
        ind=1;}}}

   if(ind==0){
    QMessageBox::about(this,"Congratulations","YOU WIN");  QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime())); ui->newgame->setEnabled(false);
            ui->newgame->setStyleSheet("background :Transparent");
            ui->newgame->setText("");
      }
}
void expert::UpdateTime()
{

    counter++;
    ui->timing->setText(QString("   %1 s ").arg(counter));
}

void expert::on_savegame_clicked()
{
    hard.open("/Users/hamzaelfarre/Desktop/28april/working/save/hard.txt");
       hard.close();

       fstream file("/Users/hamzaelfarre/Desktop/28april/working/save/hard.txt",ios::app);
       for(int i=0;i<9;i++){
           for(int j=0;j<9;j++){
               file<<test.element_read_backup(i,j);
           }
       }
       for(int i=0;i<9;i++){
           for(int j=0;j<9;j++){
               file<<test.element_read(i,j);
           }
       }
       for(int i=0;i<9;i++){
           for(int j=0;j<9;j++){
               file<<test.element_read_solution1(i,j);
           }
       }
       file<<test.indication;

}

void expert::on_reload_clicked()
{
    QFont font("Helvetica", 20, QFont::Bold);
        int a=0;
        int c;
         fstream file("/Users/hamzaelfarre/Desktop/28april/working/save/hard.txt");
        string content;
        string k;
        getline(file,content);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                k=content[a];
                c=atoi(k.c_str());
                test.element_write_backup(i,j,c);
                filled[i][j]=1;
                a++;
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                k=content[a];
                c=atoi(k.c_str());
                test.element_write(i,j,c);
                filled[i][j]=1;
                a++;
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                k=content[a];
                c=atoi(k.c_str());
                test.element_write_solution(i,j,c);
                filled[i][j]=1;
                a++;
            }
        }
        k=content[a];
        test.indication=atoi(k.c_str());
        int value;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                celll->setTextAlignment(Qt::AlignHCenter||Qt::AlignVCenter) ;
                celll->setFont(font);
                    celll->setText(" ");
     ui->mytable1->setItem(i,j,celll);
     filled[i][j]=0;
            }
        }
              file.close();
              for(int i=0;i<9;i++){
                  for(int j=0;j<9;j++){
                      value=test.element_read_backup(i,j);
                              QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                      celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                      celll->setFont(font);
                          celll->setText(QString::number(value));
                      if(value!=0){
           ui->mytable1->setItem(i,j,celll);
           ui->mytable1->item(i,j)->setBackgroundColor(Qt::lightGray);
           filled[i][j]=1;}}}
              for(int i=0;i<9;i++){
                  for(int j=0;j<9;j++){
                      value=test.element_read(i,j);
                              QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                      celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                      celll->setFont(font);
                          celll->setText(QString::number(value));
                      if(value!=0 && filled[i][j]!=1){
           ui->mytable1->setItem(i,j,celll);
           ui->mytable1->item(i,j)->setBackgroundColor(Qt::white);
        }}}

}
