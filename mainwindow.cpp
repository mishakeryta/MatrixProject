#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbtRead_clicked()
{
    QString qsMatrix  = ui->pteMatrix->toPlainText();
    QRegExp rx("[ ]");

}
