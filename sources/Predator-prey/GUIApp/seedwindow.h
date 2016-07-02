#ifndef SEEDWINDOW_H
#define SEEDWINDOW_H
#include <QtWidgets>
#include "mainmenu.h"

class ModelWindow;

class SeedWindow : public QDialog
{
    Q_OBJECT

    const QSize WINDOW_SIZE { 320, 90 };
    const QSize BUTTON_SIZE { 120, 30 };

    QPushButton* ok_button;
    Settings* settings;
    QLineEdit* seed_line;
    QLabel* seed_label;

public:
    SeedWindow(QWidget* parent, Settings* settings);

private slots:
    void ok();
};

#endif // SEEDWINDOW_H
