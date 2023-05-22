#include "blocks.h"
//#include "blockchain_grupo5.h"
#include "ui_blocks.h"
#include "sha256.h"
#include <QString>
#include <string>
#include <QTextEdit>
#include <QWidget>
#include <QDialog>




blocks::blocks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::blocks)
{

    ui->setupUi(this);
    this->setWindowTitle("Bloques");
    connect(ui->textEdit, &QTextEdit::textChanged, this, &blocks::onTextChanged);

}

blocks::~blocks()
{
    delete ui;
}

void blocks::onTextChanged()
{
    SHA256 sha;
    QString sq = ui->textEdit->toPlainText();
    std::string str = sq.toStdString();



    sha.update(str);
    const uint8_t * digest = sha.digest();
    std::string shastr = SHA256::toString(digest);
    ui->label->setText(QString::fromStdString(shastr));
    delete[] digest;

}

void blocks::on_pushButton_clicked()
{
    SHA256 she;
    QString sq1 = ui->label->text();
    std::string str1 = sq1.toStdString();

    std::string nonce2 = she.findNonce(str1);
    ui->label_2->setText( QString::fromStdString(nonce2));

}


void blocks::on_pushButton_2_clicked()
{

}

