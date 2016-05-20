#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H
#include <QtWidgets>
#include "mainmenu.h"

class ResultWindow : public QDialog
{
    Q_OBJECT

    const QSize WINDOW_SIZE { 300, 90 };
    const QSize BUTTON_SIZE { 120, 30 };

    QPushButton* ok_button;
    QLabel* result_label;

public:
    ResultWindow(QWidget* parent, QString winners);

private slots:
    void closeWindow();
};

#endif // RESULTWINDOW_H
