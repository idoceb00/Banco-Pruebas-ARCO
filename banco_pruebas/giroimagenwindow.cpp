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

void giroImagenWindow::on_pushButton_2_clicked()
{
    origen = QFileDialog::getExistingDirectory(this, "Elige el directorio de las imagenes");
    destino = QFileDialog::getExistingDirectory(this, "Elige el destino");

}

