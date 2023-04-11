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
    this->origen = QFileDialog::getExistingDirectory(this, "Elige el directorio de las imagenes");
    this->destino = QFileDialog::getExistingDirectory(this, "Elige el destino");

    this->ui->Origen_lineEdit->setText(origen);
    this->ui->Destino_lineEdit->setText(destino);
}

void giroImagenWindow::on_ejecutarButton_clicked()
{
    vector<double> tiempos;

    QDir dir(this->origen);
    QFileInfoList list = dir.entryInfoList();

    clock_t inicio;
    clock_t fin;

    double media = 0;

    for(int i = 0; i < 5; i++){
        inicio = clock();

        for(int j = 0; j < list.size();j++){
            QFileInfo ruta = list.at(j);

            if((ruta.fileName().indexOf(".jpg") != -1) || (ruta.fileName().indexOf(".png") != -1) || (ruta.fileName().indexOf(".jpeg") != -1)){
                QImage image(ruta.filePath());

                QMatrix matrix;

                matrix.rotate(180);

                QImage rotatedImage = image.transformed(matrix);

                rotatedImage.save(this->destino + "/" +ruta.fileName());
            }
        }

        fin = clock();

        double tiempo = (double)(fin - inicio)/CLOCKS_PER_SEC;

        media += tiempo;

        tiempos.push_back(tiempo);
    }

    //Multiplico por 1000 para pasarlo a milisegundos
    this->ui->time1->setText(QString::number(tiempos[0] * 1000) + " ms");
    this->ui->time2->setText(QString::number(tiempos[1] * 1000) + " ms");
    this->ui->time3->setText(QString::number(tiempos[2] * 1000) + " ms");
    this->ui->time4->setText(QString::number(tiempos[3] * 1000) + " ms");
    this->ui->time5->setText(QString::number(tiempos[4] * 1000) + " ms");

    media = media/5;

    this->ui->timeMedia->setText(QString::number(media * 1000) + " ms");

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


