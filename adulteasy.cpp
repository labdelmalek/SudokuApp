#include "adulteasy.h"
#include "ui_adulteasy.h"
#include "classsudoku.h"
#include "QString"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QMessageBox"
#include "QLabel"
#include "time.h"
#include "QFont"
#include<QTime>
#include<QTimer>
#include <QStyle>
#include <QDesktopWidget>
#include "mainwindow.h"
adulteasy::adulteasy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adulteasy)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(996, 718));
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );
    QPixmap back(":/resource/BACK.png");
    QIcon backk(back);
    QPixmap background (":/resource/easy_background.png");
    ui->background->setPixmap(background);
    QPixmap clock (":/resource/time1.png");
    ui->clocklabel->setScaledContents(true);
    ui->clocklabel->setPixmap(clock);
    ui->menu->setIcon(backk);
    ui->newgame->click();
}

adulteasy::~adulteasy()
{
    delete ui;
}
void adulteasy::on_newgame_clicked()
{
    QFont font("Helvetica", 20, QFont::Bold);
    //clearing the interface grill
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
            celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter) ;
            celll->setFont(font);
            celll->setText(" ");
 ui->mytable->setItem(i,j,celll);
 filled[i][j]=0;
        }
    }
    int value;
  //new game
    if(ind==0){
test.clear_grille(0);
ui->newgame->setText("Reset");
counter = 0;
 timer_s = new QTimer(this);
 QObject::connect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
 timer_s->start(1000);
ind=1;}
    //reset
    else{test.reset_grille();
    counter=0;}
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
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
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
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
void adulteasy::on_mytable_cellClicked(int row, int column)
{click_abs=row;
 click_ord=column;}
void adulteasy::on_number1_clicked()
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

 if ( test.goodrow(1,click_abs,click_ord)==1 && test.goodcolumn(1,click_abs,click_ord)==1 && test.goodblock(1,click_abs,click_ord)==1){
     ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
}
 else{
     ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
 }
 int value;
 for(i=0;i<9;i++){
     for(j=0;j<9;j++){
         value=test.element_read(i,j);
         if(value!=0 && filled[i][j]!=1){
         if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
             ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
         else{
             ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
         }}
     }}}}
}
void adulteasy::on_number2_clicked()
{
    if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i=0,j=0;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(2));
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,2);

                                 celll->setText(QString::number(2));
         ui->mytable->setItem(click_abs,click_ord,celll);

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
               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{
               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{
                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}}}
}
void adulteasy::on_number3_clicked()
{  if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(3));
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,3);

                 ui->mytable->setItem(click_abs,click_ord,celll);

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
               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{
               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){
                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{
                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}}}}
void adulteasy::on_number4_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(4));
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,4);

                 ui->mytable->setItem(click_abs,click_ord,celll);

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

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}}

void adulteasy::on_number5_clicked()
{if(click_abs!=99){
    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(5));
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,5);

                 ui->mytable->setItem(click_abs,click_ord,celll);

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

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}}}
}
void adulteasy::on_number6_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
        celll->setText(QString::number(6));
        celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,6);

                 ui->mytable->setItem(click_abs,click_ord,celll);
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

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}}
}}
void adulteasy::on_number7_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(7));
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,7);

                 ui->mytable->setItem(click_abs,click_ord,celll);

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

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}}
}}
void adulteasy::on_number8_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);

    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(8));
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,8);

                 ui->mytable->setItem(click_abs,click_ord,celll);

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

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}}
void adulteasy::on_number9_clicked()
{   if(click_abs!=99){

    QFont font("Helvetica", 20, QFont::Bold);
int i,j;
    ui->mytable->clearSelection();
            QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);

    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        celll->setText(QString::number(9));
        if(filled[click_abs][click_ord]!=1){
            test.element_write(click_abs,click_ord,9);

                 ui->mytable->setItem(click_abs,click_ord,celll);

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

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::white);
          }
           else{

               ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::red);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                   value=test.element_read(i,j);
                   if(value!=0 && filled[i][j]!=1){
                   if(test.goodrow(value,i,j)==1 && test.goodcolumn(value,i,j)==1 && test.goodblock(value,i,j)==1){

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::white);}
                   else{

                       ui->mytable->item(i,j)->setBackgroundColor(Qt::red);
                   }}
               }}
}}}
void adulteasy::on_solveit_clicked()
{    QFont font("Helvetica", 20, QFont::Bold);
     indsolved=1;
     counter=0;
     QObject::disconnect(timer_s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
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

for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
    int value=test.element_read_solution1(i,j);
    if(value!=0){
            QTableWidgetItem *heo = new QTableWidgetItem;
            heo->setText(QString::number(value));
            heo->setFont(font);
                        heo->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter) ;
        ui->mytable->setItem(i,j,heo);}
    }
}
}

void adulteasy::UpdateTime()
{
    counter++;
    ui->timing->setText(QString("  %1 s ").arg(counter));
}
void adulteasy::on_menu_clicked()
{
    if(indsolved==0){
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Save", "Do you want to save the game?",
        QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
ui->save->click();
      }}
    this->hide();
    parentWidget()->show();
}
void adulteasy::on_erase_clicked()
{if(click_abs!=99 && indsolved==0 && filled[click_abs][click_ord]==0){
    QFont font("Helvetica", 20, QFont::Bold);
               QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
int i,j;
       celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
test.element_write(click_abs,click_ord,0);
           if(filled[click_abs][click_ord]!=1){
               for(i=0;i<9;i++){
               for(j=0;j<9;j++){
                            if(i==click_abs && j==click_ord){
                                        QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                    celll->setText(" ");
                                    celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                            }}}
                    ui->mytable->setItem(click_abs,click_ord,celll);
           }
           int value;
           for(i=0;i<9;i++){
               for(j=0;j<9;j++){
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
void adulteasy::on_indication_clicked()
{
    int i,j;
    QFont font("Helvetica", 20, QFont::Bold);
if(test.indication>0 && click_abs!=99){
        ui->mytable->clearSelection();
                QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);

        celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            celll->setText(QString::number(test.element_read_solution1(click_abs,click_ord)));
            if(filled[click_abs][click_ord]!=1){
                                         QTableWidgetItem *celll = new QTableWidgetItem;    celll->setFont(font);
                                         test.element_write(click_abs,click_ord,test.element_read_solution1(click_abs,click_ord));
                                         celll->setText(QString::number(test.element_read_solution1(click_abs,click_ord)));
                             celll->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                     ui->mytable->setItem(click_abs,click_ord,celll);
                    test.indication--;
                 ui->indication->setText(QString::number(test.indication)+" HINTS LEFT");
                    ui->mytable->item(click_abs,click_ord)->setBackgroundColor(Qt::lightGray);}}
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
void adulteasy::on_save_clicked()
{
    easy.open("/Users/hamzaelfarre/Desktop/28april/working/save/easy.txt");
       easy.close();
       fstream file("/Users/hamzaelfarre/Desktop/28april/working/save/easy.txt",ios::app);
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

void adulteasy::on_reload_clicked()
{
    QFont font("Helvetica", 20, QFont::Bold);
        int a=0;
        int c;
         fstream file("/Users/hamzaelfarre/Desktop/28april/working/save/easy.txt");
        string content;
        string k;
        //copies the content of file in the variable content
        getline(file,content);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                k=content[a];
                // atoi(k.c_str()); biblio stdlib sert a convertir les chaines de caracteres en chiffres (entiers )
                c=atoi(k.c_str());
                test.element_write_backup(i,j,c);
                a++;
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                k=content[a];
                c=atoi(k.c_str());
                test.element_write(i,j,c);
                a++;
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                k=content[a];
                c=atoi(k.c_str());
                test.element_write_solution(i,j,c);
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
     ui->mytable->setItem(i,j,celll);
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
           ui->mytable->setItem(i,j,celll);
           ui->mytable->item(i,j)->setBackgroundColor(Qt::lightGray);
           filled[i][j]=1;}}}
              for(int i=0;i<9;i++){
                  for(int j=0;j<9;j++){
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
