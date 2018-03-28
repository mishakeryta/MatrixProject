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





void MainWindow::on_btnCaluclate_clicked()
{
    QString outstr = "";
    try
    {
        ui->textBrowser->clear();
        QString qsMatrix  = ui->pteMatrix->toPlainText();
        Matrix matrix{};
        outstr+= "Rading matrix:\n";
        qsMatrix>>matrix;
        outstr+="Inversing matrix1:\n";
        try
        {
            outstr<<matrix.inverse();
        }
        catch(logic_error ex)
        {
            outstr+="Fail\n";
        }
        catch(...)
        {
            throw;
        }
        outstr +="\nMatrix1 info:\n Max abs  value:\n";
        outstr += QString::fromStdString(to_string(matrix.findMaxAbsValue()));
        outstr +="\nMax negative value\n";
        outstr += QString::fromStdString(to_string(matrix.findMaxNegativeValue()));
        outstr +="\nMin positive value:\n";
        outstr += QString::fromStdString(to_string(matrix.findMinPositiveValue()));
        outstr += "\nDeterminant:\n";
        try
        {
            outstr += QString::fromStdString(to_string(matrix.determinant()));
        }
        catch(logic_error er)
        {
            outstr+="Wrong inputs, for youre operation.\n";
        }
        catch(...)
        {
            throw;
        }
        Matrix matrix2{};
        matrix2<<(ui->twMatrix2);

        outstr<<matrix2;
        if(ui->rbPlus->isChecked())
        {
            outstr+="Matrix1 + Matrix2 = \n";
            try
            {
                outstr<<(matrix+matrix2);
            }
            catch(logic_error er )
            {
                outstr+="Fail\n";
            }
            catch(...)
            {
                throw;
            }
        }
        if(ui->rbSubstract->isChecked())
        {
            outstr+="Matrix1 - Matrix2 = \n";
            try
            {
                outstr<<(matrix-matrix2);
            }
            catch(logic_error er )
            {
                outstr+="Fail\n";
            }
            catch(...)
            {
                throw;
            }
        }
        if(ui->rbMulti->isChecked())
        {
            outstr+="Matrix1 * Matrix2 = \n";
            try
            {
                outstr<<(matrix*matrix2);
            }
            catch(logic_error er )
            {
                outstr+="Fail\n";
            }
            catch(...)
            {
                throw;
            }
        }
        if(ui->rbPlusPlus->isChecked())
        {
            try
            {
                outstr<<(matrix.operator ++());
            }
            catch(logic_error er )
            {
                outstr+="Fail\n";
            }
            catch(...)
            {
                throw;
            }

        }

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

void MainWindow::on_btSubtructCol_clicked()
{
    if(ui->twMatrix2->columnCount())
    {
        ui->twMatrix2->setColumnCount(ui->twMatrix2->columnCount()-1);
    }
}

void MainWindow::on_pushButton_clicked()
{
     ui->twMatrix2->setColumnCount(ui->twMatrix2->columnCount()+1);
}


void MainWindow::on_brSubract_clicked()
{
    if(ui->twMatrix2->rowCount())
    {
        ui->twMatrix2->setRowCount(ui->twMatrix2->rowCount()-1);
    }
}

void MainWindow::on_btAddRow_clicked()
{
    ui->twMatrix2->setRowCount(ui->twMatrix2->rowCount()+1);
}
