#include "levelkids.h"
#include "ui_levelkids.h"
#include "QMessageBox"
#include "QPixmap"
#include "QTableWidget"
#include "QIcon"
#include <QStyle>
#include <QDesktopWidget>
levelkids::levelkids(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::levelkids)
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
    ui->menu->setIcon(backk);
    QPixmap background (":/resource/kids_background.png");
    ui->background->setPixmap(background);
QPixmap grape(":/resource/grape.png");
QIcon grapeicon(grape);
ui->number1->setIcon(grapeicon);
QPixmap banana(":/resource/banana.png");
QIcon bananaicon(banana);
ui->number2->setIcon(bananaicon);
QPixmap apple(":/resource/apple.png");
QIcon appleicon(apple);
ui->number3->setIcon(appleicon);
QPixmap kiwi(":/resource/kiwi.png");
QIcon kiwiicon(kiwi);
ui->number4->setIcon(kiwiicon);

ui->NEWGAME->click();
}
levelkids::~levelkids()
{
    delete ui;
}

void levelkids::on_NEWGAME_clicked()
{
    ui->number1->setEnabled(true);
     ui->number2->setEnabled(true);

     ui->number3->setEnabled(true);

     ui->number4->setEnabled(true);
    for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                ui->mytable->setItem(i,j,NULL);
                filled[i][j]=0;
            }}
    QPixmap grapee(":/resource/grape.png");
    QIcon grapeicon(grapee);

    QPixmap bananaa(":/resource/banana.png");
    QIcon bananaicon(bananaa);

    QPixmap applee(":/resource/apple.png");
    QIcon appleicon(applee);

    QPixmap kiwii(":/resource/kiwi.png");
    QIcon kiwiicon(kiwii);

int value;
kids test;
 kidsgrille=test;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
value=kidsgrille.element_read(i,j);
if(value!=0){
    filled[i][j]=1;
    if(value==1){
        QTableWidgetItem *grape = new QTableWidgetItem;
        grape->setIcon(grapeicon);

        ui->mytable->setItem(i,j,grape);
        ui->mytable->item(i,j)->setBackgroundColor(Qt::lightGray);
    }
    else if(value==2){    QTableWidgetItem *banana = new QTableWidgetItem;
        banana->setIcon(bananaicon);  ui->mytable->setItem(i,j,banana);
    ui->mytable->item(i,j)->setBackgroundColor(Qt::lightGray);}
    else if(value==3){
        QTableWidgetItem *apple = new QTableWidgetItem;
        apple->setIcon(appleicon);ui->mytable->setItem(i,j,apple);
    ui->mytable->item(i,j)->setBackgroundColor(Qt::lightGray);}
    else{
        QTableWidgetItem *kiwi = new QTableWidgetItem;
        kiwi->setIcon(kiwiicon);ui->mytable->setItem(i,j,kiwi);
        ui->mytable->item(i,j)->setBackgroundColor(Qt::lightGray);
}}}  }}
void levelkids::on_mytable_cellClicked(int row, int column)
{
    click_abs=row;
    click_ord=column;
}

void levelkids::on_number1_clicked()
{
    int i,j;

    ui->mytable->clearSelection();
    if(filled[click_abs][click_ord]!=1){
kidsgrille.element_write(click_abs,click_ord,1);
        QPixmap grapee(":/resource/grape.png");
    QIcon grapeicon(grapee);
                 QTableWidgetItem *grape = new QTableWidgetItem;
                 grape->setIcon(grapeicon);
                 ui->mytable->setItem(click_abs,click_ord,grape);
         }
    int ind=0;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
 if ( kidsgrille.element_read(i,j)!=0 && kidsgrille.goodcolumn(this->kidsgrille.element_read(i,j),kidsgrille.get_grill(),i,j)==1 && kidsgrille.goodrow(this->kidsgrille.element_read(i,j),kidsgrille.get_grill(),i,j)==1 && kidsgrille.goodblock(this->kidsgrille.element_read(i,j),kidsgrille.get_grill(),i,j)==1){
                    ind =0;}
        else{	i=4;
            j=4;
            ind=1;}}}

       if(ind==0){
       QMessageBox::about(this,"Congratulations","YOU WIN");}
}
void levelkids::on_number2_clicked()
{
    ui->mytable->clearSelection();

    if(filled[click_abs][click_ord]!=1){
    kidsgrille.element_write(click_abs,click_ord,2);

    QPixmap bananaa(":/resource/banana.png");
    QIcon bananaicon(bananaa);
    int i,j;
                 QTableWidgetItem *banana = new QTableWidgetItem;
                 banana->setIcon(bananaicon);
                 ui->mytable->setItem(click_abs,click_ord,banana);
    int ind=0;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
 if ( kidsgrille.element_read(i,j)!=0 && kidsgrille.goodcolumn(this->kidsgrille.element_read(i,j),kidsgrille.get_grill(),i,j)==1 && kidsgrille.goodrow(this->kidsgrille.element_read(i,j),kidsgrille.get_grill(),i,j)==1 && kidsgrille.goodblock(this->kidsgrille.element_read(i,j),kidsgrille.get_grill(),i,j)==1){
                    ind =0;}
        else{	i=4;
            j=4;
            ind=1;}}}

       if(ind==0){
       QMessageBox::about(this,"Congratulations","YOU WIN");}
}

}

void levelkids::on_number3_clicked()
{ui->mytable->clearSelection();

    if(filled[click_abs][click_ord]!=1){
    kidsgrille.element_write(click_abs,click_ord,3);
    int i,j;

    QPixmap applee(":/resource/apple.png");
    QIcon appleicon(applee);

                 QTableWidgetItem *apple = new QTableWidgetItem;
                 apple->setIcon(appleicon);ui->mytable->setItem(click_abs,click_ord,apple);

    int ind=0;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
 if ( kidsgrille.element_read(i,j)!=0 && kidsgrille.goodcolumn(this->kidsgrille.element_read(i,j),kidsgrille.get_grill(),i,j)==1 && kidsgrille.goodrow(this->kidsgrille.element_read(i,j),kidsgrille.get_grill(),i,j)==1 && kidsgrille.goodblock(this->kidsgrille.element_read(i,j),kidsgrille.get_grill(),i,j)==1){
                    ind =0;}
        else{	i=4;
            j=4;
            ind=1;}}}

       if(ind==0){
       QMessageBox::about(this,"Congratulations","YOU WIN");}
}
}

void levelkids::on_number4_clicked()
{ui->mytable->clearSelection();
    int i,j;

    if(filled[click_abs][click_ord]!=1){
    kidsgrille.element_write(click_abs,click_ord,4);

    QPixmap kiwii(":/resource/kiwi.png");
    QIcon kiwiicon(kiwii);


                 QTableWidgetItem *kiwi = new QTableWidgetItem;
                 kiwi->setIcon(kiwiicon);ui->mytable->setItem(click_abs,click_ord,kiwi);

    int ind=0;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
 if ( kidsgrille.element_read(i,j)!=0 && kidsgrille.goodcolumn(this->kidsgrille.element_read(i,j),kidsgrille.get_grill(),i,j)==1 && kidsgrille.goodrow(this->kidsgrille.element_read(i,j),kidsgrille.get_grill(),i,j)==1 && kidsgrille.goodblock(this->kidsgrille.element_read(i,j),kidsgrille.get_grill(),i,j)==1){
                    ind =0;}
        else{	i=4;
            j=4;
            ind=1;}}}

       if(ind==0){
       QMessageBox::about(this,"Congratulations","YOU WIN");}
}
}

void levelkids::on_menu_clicked()
{
    this->hide();
    parentWidget()->show();
}

void levelkids::on_Solve_it_clicked()
{
    ui->number1->setEnabled(false);
    ui->number2->setEnabled(false);
    ui->number3->setEnabled(false);
    ui->number4->setEnabled(false);
    ui->mytable->clearSelection();
    QPixmap grapee(":/resource/grape.png");
    QIcon grapeicon(grapee);
    QTableWidgetItem *grape = new QTableWidgetItem;
    grape->setIcon(grapeicon);
    QPixmap bananaa(":/resource/banana.png");
    QIcon bananaicon(bananaa);
    QTableWidgetItem *banana = new QTableWidgetItem;
    banana->setIcon(bananaicon);
    QPixmap applee(":/resource/apple.png");
    QIcon appleicon(applee);
    QTableWidgetItem *apple = new QTableWidgetItem;
    apple->setIcon(appleicon);
    QPixmap kiwii(":/resource/kiwi.png");
    QIcon kiwiicon(kiwii);
    QTableWidgetItem *kiwi = new QTableWidgetItem;
    kiwi->setIcon(kiwiicon);

int value;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
value=kidsgrille.element_read_solution(i,j);
if(value!=0){
    if(value==1){
        QTableWidgetItem *grape = new QTableWidgetItem;
        grape->setIcon(grapeicon);
        ui->mytable->setItem(i,j,grape);}
    else if(value==2){    QTableWidgetItem *banana = new QTableWidgetItem;
        banana->setIcon(bananaicon);  ui->mytable->setItem(i,j,banana);}
    else if(value==3){
        QTableWidgetItem *apple = new QTableWidgetItem;
        apple->setIcon(appleicon);ui->mytable->setItem(i,j,apple);}
    else{
        QTableWidgetItem *kiwi = new QTableWidgetItem;
        kiwi->setIcon(kiwiicon);ui->mytable->setItem(i,j,kiwi);
}
}
   }
    }
}

void levelkids::on_reset_clicked()
{
ui->mytable->clearSelection();
    for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                ui->mytable->setItem(i,j,NULL);
            }}
    int value;
    QPixmap grapee(":/resource/grape.png"); QIcon grapeicon(grapee);
    QPixmap bananaa(":/resource/banana.png"); QIcon bananaicon(bananaa);
    QPixmap applee(":/resource/apple.png"); QIcon appleicon(applee);
    QPixmap kiwii(":/resource/kiwi.png");QIcon kiwiicon(kiwii);
    kidsgrille.reset_grille();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
value=kidsgrille.element_read(i,j);
if(value!=0){
    if(value==1){
        QTableWidgetItem *grape = new QTableWidgetItem;
        grape->setIcon(grapeicon);
        ui->mytable->setItem(i,j,grape);
        ui->mytable->item(i,j)->setBackgroundColor(Qt::lightGray);
    }
    else if(value==2){    QTableWidgetItem *banana = new QTableWidgetItem;
        banana->setIcon(bananaicon);  ui->mytable->setItem(i,j,banana);
        ui->mytable->item(i,j)->setBackgroundColor(Qt::lightGray);
    }
    else if(value==3){
        QTableWidgetItem *apple = new QTableWidgetItem;
        apple->setIcon(appleicon);ui->mytable->setItem(i,j,apple);
        ui->mytable->item(i,j)->setBackgroundColor(Qt::lightGray);
    }
    else{
        QTableWidgetItem *kiwi = new QTableWidgetItem;
        kiwi->setIcon(kiwiicon);ui->mytable->setItem(i,j,kiwi);
                ui->mytable->item(i,j)->setBackgroundColor(Qt::lightGray);
}}}  }
}
