#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{money += 500;ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
    ui->lcdNumber->display(money);
    delete ui;
}

void Widget::checkMoney(int input){
    if(input<100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    }

    if(input>=100 && input<=140){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
 }
    if(input>=150 && input<=190){
        ui->pbMilk->setEnabled(false);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
        }
    if(input>=200){
      ui->pbCoffee->setEnabled(true);
      ui->pbMilk->setEnabled(true);
      ui->pbTea->setEnabled(true);
     }
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    checkMoney(money);
}

void Widget::order(int diff){
    money -= diff;
    ui->lcdNumber->display(money);
    checkMoney(money);
}

int money = 0;
void Widget::on_pb10_clicked()
{
    changeMoney(10);
    //money += 10;
    //ui->lcdNumber->display(money);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    order(100);
}

void Widget::on_pbTea_clicked()
{
    order(150);
}

void Widget::on_pbMilk_clicked()
{
    order(200);
}

void Widget::on_pbreset_clicked()
{
   QMessageBox m;
   QString less_money = QString("Return : %1").arg(money);
   m.information(nullptr, "hi", less_money);
   money = 0;
       ui->lcdNumber->display(money);
       checkMoney(money);
}
