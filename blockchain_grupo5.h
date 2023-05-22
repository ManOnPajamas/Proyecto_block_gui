#ifndef BLOCKCHAIN_GRUPO5_H
#define BLOCKCHAIN_GRUPO5_H

#include <QMainWindow>
//#include "blocks.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BlockChain_Grupo5; }
QT_END_NAMESPACE

class BlockChain_Grupo5 : public QMainWindow
{
    Q_OBJECT

public:
    BlockChain_Grupo5(QWidget *parent = nullptr);
    ~BlockChain_Grupo5();


private slots:


    void on_pushButton_clicked();

private:
    Ui::BlockChain_Grupo5 *ui;
    //blocks *blck;

};
#endif // BLOCKCHAIN_GRUPO5_H
