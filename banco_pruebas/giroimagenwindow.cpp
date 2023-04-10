#include "giroimagenwindow.h"
#include "ui_giroimagenwindow.h"

#include <QFileDialog>

giroImagenWindow::giroImagenWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::giroImagenWindow)
{
    ui->setupUi(this);
}

giroImagenWindow::~giroImagenWindow()
{
    delete ui;
}

void giroImagenWindow::on_directories_button_clicked()
{
    origen = QFileDialog::getExistingDirectory(this, "Elige el directorio de las imagenes");
    destino = QFileDialog::getExistingDirectory(this, "Elige el destino");
}


void giroImagenWindow::on_pushButton_clicked()
{

}


void giroImagenWindow::on_pushButton_3_clicked()
{

}

