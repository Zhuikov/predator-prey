#ifndef EXITWINDOW_H
#define EXITWINDOW_H
#include <QtWidgets>
#include "mainmenu.h"

class ExitWindow : public QWidget
{
    Q_OBJECT

    const QSize WINDOW_SIZE { 300, 90 };
    const QSize BUTTON_SIZE { 100, 30 };

    QPushButton* yes_button;
    QPushButton* no_button;
//    QString button_style =
//            "QPushButton {"
//                " border: 1px solid #324ab2;"
//                " background: qlineargradient(x1: 0, y1: 1, x2: 0, y2: 0,  stop: 0 #ffb366, stop: 1 #ff4f00);"
//                " border-radius: 9px;"
//                " color: #324ab2;"
//                " font-size: 20px;"
//                " font-weight: bold;"
//            "}"
//            "QPushButton:pressed {"
//                " background: qlineargradient(x1: 0, y1: 1, x2: 0, y2: 0,  stop: 0 #ff7433, stop: 1 #ffb366);"
//            "}"
//            "QPushButton:hover {"
//                " color: #33ff33;"
//                " border: 1.5px solid #324ab2;"
//            "}";

public:
    ExitWindow(QWidget* parent);
};

#endif // EXITWINDOW_H
