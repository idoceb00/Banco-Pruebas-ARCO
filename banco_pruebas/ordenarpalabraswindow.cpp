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

    //Lectura del archivo y almacenamiento de las palabras en un vector.

    QFile file(rutaOrigen);
    if(!file.open(QIODevice::ReadWrite))
        QMessageBox::information(0, "error", file.errorString());

    QTextStream in(&file);

    while(!in.atEnd()){
        QString line = in.readLine();
        words.push_back(line);
    }

    file.close();

}

void ordenarPalabrasWindow::on_destinoButton_clicked()
{
    QFileDialog x;

    this->rutaDestino = x.getExistingDirectory(this, "Selecciona un archivo");

    this->ui->destinoLineEdit->setText(this->rutaDestino);
}


void ordenarPalabrasWindow::on_ejecutar_button_clicked()
{
    vector<double> tiempos;
    clock_t inicio;
    clock_t fin;

    double media = 0;

    for(int i = 0; i < 5; i++){
        inicio = clock();

        sort(words.begin(), words.end());

        QFile file(rutaDestino + "/palabrasOrdenadas.txt");
        if(!file.open(QIODevice::WriteOnly))
        QMessageBox::information(0, "error", file.errorString());

        QTextStream out(&file);

        for(int i = 0; i < (int)words.size(); i++){
            out << words[i] << endl;
        }

        file.close();

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

