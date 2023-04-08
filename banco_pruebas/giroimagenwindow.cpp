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
    QString origen = QFileDialog::getExistingDirectory(this, "Elige el directorio de las imagenes");
    QString destino = QFileDialog::getExistingDirectory(this, "Elige el destino");

}

