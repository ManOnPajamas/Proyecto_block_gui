#ifndef BLOCKS_H
#define BLOCKS_H

#include <QDialog>
//#include "blockchain_grupo5.h"


namespace Ui {
class blocks;
}

class blocks : public QDialog
{
    Q_OBJECT

public:
    explicit blocks(QWidget *parent = nullptr);
    ~blocks();
    void onTextChanged();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::blocks *ui;
    //BlockChain_Grupo5 *blck;
};

#endif // BLOCKS_H
