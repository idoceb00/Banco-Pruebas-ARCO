#ifndef ORDENARPALABRASWINDOW_H
#define ORDENARPALABRASWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>

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

private:
    Ui::ordenarPalabrasWindow *ui;

    string rutaOrigen;
    string rutaDestino;
};

#endif // ORDENARPALABRASWINDOW_H
