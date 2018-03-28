#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matrix.hpp"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_btnCaluclate_clicked();

    void on_btSubtructCol_clicked();

    void on_pushButton_clicked();

    void on_brSubract_clicked();

    void on_btAddRow_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
