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
    QRegExp rx("[\n]");
    QList<QString> qsRowsValues = qsMatrix.split(QRegExp("\n"),QString::SkipEmptyParts);
    QList<double>* valueOnRows = new QList<double>[qsRowsValues.length()]{};
    rx.setPattern("[ ]");
    unsigned int maxLength = 0;
    for(int i = 0;i < qsRowsValues.length();++i)
    {

        QList<QString> qsValueOnRow = qsRowsValues.at(i).split(QRegExp(" "),QString::SkipEmptyParts);
        if(qsValueOnRow.length()>maxLength)
        {
            maxLength = qsValueOnRow.length();
        }
        for(auto qsVal:qsValueOnRow)
        {
            valueOnRows[i].append(qsVal.toDouble());
        }
    }
    Matrix matrix(qsRowsValues.length(),maxLength);
    for(int i = 0;i<qsRowsValues.length();++i)
    {
        for(int j = 0;j<valueOnRows[i].length();++j)
        {
            matrix[i][j] = valueOnRows[i].at(j);
        }
    }
    QString outstr = "";
    outstr<<matrix;
    outstr += QString::fromStdString(to_string(matrix.determinant()));
    ui->textBrowser->setPlainText(outstr);
    delete[] valueOnRows;
}


