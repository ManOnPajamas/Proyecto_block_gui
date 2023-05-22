#include "blockchain_grupo5.h"
#include "ui_blockchain_grupo5.h"
#include <QDate>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include "blocks.h"


BlockChain_Grupo5::BlockChain_Grupo5(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BlockChain_Grupo5)
{
    ui->setupUi(this);
    // Get the current date
    QDate currentDate = QDate::currentDate();

    // Convert the date to a string
    QString dateString = currentDate.toString(Qt::ISODate);

    // Set the string as the text of the QLabel
    ui->dateLabel->setText(dateString);

}

BlockChain_Grupo5::~BlockChain_Grupo5()
{
    delete ui;
}







void BlockChain_Grupo5::on_pushButton_clicked()
{

    this->hide();
    blocks block;
    block.setModal(true);
    block.exec();
}

