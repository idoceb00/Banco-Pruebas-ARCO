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
    sort(words.begin(), words.end());

    QFile file(rutaDestino + "/palabrasOrdenadas.txt");
    if(!file.open(QIODevice::WriteOnly))
        QMessageBox::information(0, "error", file.errorString());

    QTextStream out(&file);

    for(int i = 0; i < (int)words.size(); i++){
        out << words[i] << endl;
    }

    file.close();
}

