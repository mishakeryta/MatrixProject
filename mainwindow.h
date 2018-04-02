#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "matrix.hpp"
#include <QMainWindow>
#include "rootfinder.h"

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
    void on_pbtPlusSize_clicked();

    void on_pbtMinusSize_clicked();

    void on_pbtCslculate_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
