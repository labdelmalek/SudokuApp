#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H

#include <QMainWindow>

namespace Ui {
class howtoplay;
}

class howtoplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit howtoplay(QWidget *parent = nullptr);
    ~howtoplay();

private slots:
    void on_menu_clicked();

private:
    Ui::howtoplay *ui;
};

#endif // HOWTOPLAY_H
