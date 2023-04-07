#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ordenarPalabras_clicked()
{
    ordenarPalabrasWindow *x = new ordenarPalabrasWindow();

    x->show();
}


void MainWindow::on_pushButton_2_clicked()
{

}

