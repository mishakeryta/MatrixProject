#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Matrix.hpp"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tMatrixA->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ui->tMatrixA->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tMatrixA->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tMatrixA->resize(ui->tMatrixA->columnCount()*ui->tMatrixA->columnWidth(0),
            ui->tMatrixA->rowCount()*ui->tMatrixA->rowHeight(0));
    ui->tMatrixA->setMaximumSize(6*ui->tMatrixA->columnWidth(0),6*ui->tMatrixA->rowHeight(0));

    ui->tMatrixB->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    ui->tMatrixB->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tMatrixB->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tMatrixB->setMaximumSize(ui->tMatrixB->columnWidth(0),6*ui->tMatrixB->rowHeight(0));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbtPlusSize_clicked()
{
    if(ui->tMatrixB->rowCount() < 6)
    {
        ui->tMatrixA->setColumnCount(ui->tMatrixA->columnCount() + 1);
        ui->tMatrixA->setRowCount(ui->tMatrixA->rowCount() + 1);

        ui->tMatrixA->resize(ui->tMatrixA->columnCount()*ui->tMatrixA->columnWidth(0),
                             ui->tMatrixA->rowCount()*ui->tMatrixA->rowHeight(0));

        ui->tMatrixB->setRowCount(ui->tMatrixB->rowCount()+1);
        ui->tMatrixB->resize(ui->tMatrixB->columnCount()*ui->tMatrixB->columnWidth(0),
                         ui->tMatrixB->rowCount()*ui->tMatrixB->rowHeight(0));
        //ui->tMatrixB->move(ui->tMatrixA->pos().rx() + ui->tMatrixA->width(),
         //                  ui->tMatrixB->pos().ry());
    }

}

void MainWindow::on_pbtMinusSize_clicked()
{
    if(ui->tMatrixB->rowCount() > 2)
    {
        ui->tMatrixA->setColumnCount(ui->tMatrixA->columnCount() - 1);
        ui->tMatrixA->setRowCount(ui->tMatrixA->rowCount() - 1);

        ui->tMatrixA->resize(ui->tMatrixA->columnCount()*ui->tMatrixA->columnWidth(0),
                             ui->tMatrixA->rowCount()*ui->tMatrixA->rowHeight(0));

        ui->tMatrixB->setRowCount(ui->tMatrixB->rowCount()-1);
        ui->tMatrixB->resize(ui->tMatrixB->columnCount()*ui->tMatrixB->columnWidth(0),
                         ui->tMatrixB->rowCount()*ui->tMatrixB->rowHeight(0));
        //ui->tMatrixB->move(ui->tMatrixA->pos().rx() + ui->tMatrixA->width(),
       //                    ui->tMatrixB->pos().ry());
    }

}
