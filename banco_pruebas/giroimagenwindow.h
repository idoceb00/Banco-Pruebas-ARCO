#ifndef GIROIMAGENWINDOW_H
#define GIROIMAGENWINDOW_H

#include <QWidget>

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
    void on_pushButton_2_clicked();

private:
    Ui::giroImagenWindow *ui;
};

#endif // GIROIMAGENWINDOW_H
