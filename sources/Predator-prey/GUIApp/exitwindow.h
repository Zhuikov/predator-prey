#ifndef EXITWINDOW_H
#define EXITWINDOW_H
#include <QtWidgets>
#include "mainmenu.h"

class ExitWindow : public QDialog
{
    Q_OBJECT

    const QSize WINDOW_SIZE { 300, 90 };
    const QSize BUTTON_SIZE { 120, 30 };

    QPushButton* yes_button;
    QPushButton* no_button;

    QWidget* parent;
    QLabel* exit_label;

public:
    explicit ExitWindow(QWidget* parent);

private slots:
    void close_app();
    void close_exit_window();
};

#endif // EXITWINDOW_H
