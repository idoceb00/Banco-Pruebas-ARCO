#ifndef ORDENARPALABRASWINDOW_H
#define ORDENARPALABRASWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <time.h>

using namespace std;


namespace Ui {
class ordenarPalabrasWindow;
}

class ordenarPalabrasWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ordenarPalabrasWindow(QWidget *parent = nullptr);
    ~ordenarPalabrasWindow();

private slots:
    void on_origenButton_clicked();

    void on_destinoButton_clicked();

    void on_ejecutar_button_clicked();

private:
    Ui::ordenarPalabrasWindow *ui;

    vector<QString> words;

    QString rutaOrigen;
    QString rutaDestino;
};

#endif // ORDENARPALABRASWINDOW_H
