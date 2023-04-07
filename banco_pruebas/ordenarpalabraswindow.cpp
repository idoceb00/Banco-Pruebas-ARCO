#include "ordenarpalabraswindow.h"
#include "ui_ordenarpalabraswindow.h"

ordenarPalabrasWindow::ordenarPalabrasWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ordenarPalabrasWindow)
{
    ui->setupUi(this);
}

ordenarPalabrasWindow::~ordenarPalabrasWindow()
{
    delete ui;
}

void ordenarPalabrasWindow::on_origenButton_clicked()
{
    QFileDialog x;

    this->rutaOrigen = x.getOpenFileName(this, "ordenarPalabrasWindow");

    this->ui->origenLineEdit->setText(this->rutaOrigen);
}


void ordenarPalabrasWindow::on_destinoButton_clicked()
{
    QFileDialog x;

    this->rutaDestino = x.getExistingDirectory(this, "Selecciona un archivo");

    this->ui->destinoLineEdit->setText(this->rutaDestino);
}

