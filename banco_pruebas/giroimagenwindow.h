#ifndef GIROIMAGENWINDOW_H
#define GIROIMAGENWINDOW_H

#include <QWidget>
#include <QFileDialog>

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

    void on_directories_button_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::giroImagenWindow *ui;

    QString origen;
    QString destino;
};

#endif // GIROIMAGENWINDOW_H
