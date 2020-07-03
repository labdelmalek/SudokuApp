#include "howtoplay.h"
#include "ui_howtoplay.h"
#include "QLabel"
#include "QPixmap"
#include <QStyle>
#include <QDesktopWidget>
howtoplay::howtoplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::howtoplay)
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
    QPixmap background (":/resource/how_to_play.png");
    ui->background->setPixmap(background);
ui->background->setScaledContents(true);
QPixmap back(":/resource/BACK.png");
QIcon backk(back);
ui->menu->setIcon(backk);


}

howtoplay::~howtoplay()
{
    delete ui;
}

void howtoplay::on_menu_clicked()
{
    this->hide();
    parentWidget()->show();
}
