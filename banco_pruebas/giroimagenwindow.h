#ifndef GIROIMAGENWINDOW_H
#define GIROIMAGENWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <time.h>
#include <vector>
#include <iostream>
#include <QDir>

using namespace std;

namespace Ui {
class giroImagenWindow;
}

class giroImagenWindow : public QWidget
{
    Q_OBJECT

public:
    explicit giroImagenWindow(QWidget *parent = nullptr);
    ~giroImagenWindow();

private slots:

    void on_ejecutarButton_clicked();

    void on_resetButton_clicked();

    void on_seleccionarDirectButton_clicked();

private:
    Ui::giroImagenWindow *ui;

    QString origen;
    QString destino;
};

#endif // GIROIMAGENWINDOW_H
