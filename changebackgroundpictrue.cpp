#include "changebackgroundpictrue.h"
#include "ui_changebackgroundpictrue.h"

ChangeBackgroundPictrue::ChangeBackgroundPictrue(QWidget *parent, QSize size) :
    QDialog(parent),
    ui(new Ui::ChangeBackgroundPictrue)
{
    ui->setupUi(this);
}

ChangeBackgroundPictrue::~ChangeBackgroundPictrue()
{
    delete ui;
}

void ChangeBackgroundPictrue::on_sure_clicked()
{

}

void ChangeBackgroundPictrue::on_back_clicked()
{

}
