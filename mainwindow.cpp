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
    QString outstr = "";
    try
    {
        ui->textBrowser->clear();
        QString qsMatrix  = ui->pteMatrix->toPlainText();
        Matrix matrix{};
        qsMatrix>>matrix;
        outstr<<matrix.inverse();
        outstr+="\n\n";
        outstr<<matrix*matrix.inverse();
        outstr += QString::fromStdString(to_string(matrix.determinant()));

    }
    catch(logic_error exp)
    {
        outstr+="Wrong inputs, for youre operation.";
    }
    catch(out_of_range)
    {
        outstr+="Inappropriate access.";
    }
    catch(...)
    {
        throw;
    }
    ui->textBrowser->setPlainText(outstr);

}


