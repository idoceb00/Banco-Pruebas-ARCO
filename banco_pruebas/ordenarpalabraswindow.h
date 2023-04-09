#ifndef ORDENARPALABRASWINDOW_H
#define ORDENARPALABRASWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

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

private:
    Ui::ordenarPalabrasWindow *ui;

    vector<QString> words;

    QString rutaOrigen;
    QString rutaDestino;
};

#endif // ORDENARPALABRASWINDOW_H
