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

void giroImagenWindow::on_seleccionarDirectButton_clicked()
{
    origen = QFileDialog::getExistingDirectory(this, "Elige el directorio de las imagenes");
    destino = QFileDialog::getExistingDirectory(this, "Elige el destino");

    ui->Origen_lineEdit->setText(origen);
    ui->Destino_lineEdit->setText(destino);
}

void giroImagenWindow::on_ejecutarButton_clicked()
{
    std::vector<double> tiempos;

    clock_t inicio;
    clock_t fin;

    double media = 0;

    for(int i = 0; i < 5; i++){
        inicio = clock();



        fin = clock();

        double tiempo = (double)(fin - inicio)/CLOCKS_PER_SEC;

        media += tiempo;

        tiempos.push_back(tiempo);
    }

    //Multiplico por 1000 para pasarlo a milisegundos
    this->ui->time1->setText(QString::number(tiempos[0] * 1000));
    this->ui->time2->setText(QString::number(tiempos[1] * 1000));
    this->ui->time3->setText(QString::number(tiempos[2] * 1000));
    this->ui->time4->setText(QString::number(tiempos[3] * 1000));
    this->ui->time5->setText(QString::number(tiempos[4] * 1000));

    media = media/5;

    this->ui->timeMedia->setText(QString::number(media * 1000));

}


void giroImagenWindow::on_resetButton_clicked()
{
    this->ui->Origen_lineEdit->setText("");
    this->ui->Destino_lineEdit->setText("");

    this->ui->time1->setText("");
    this->ui->time2->setText("");
    this->ui->time3->setText("");
    this->ui->time4->setText("");
    this->ui->time5->setText("");

    this->ui->timeMedia->setText("");

}


