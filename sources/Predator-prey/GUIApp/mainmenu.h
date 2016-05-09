#ifndef MAINMENU_H
#define MAINMENU_H
#include "QtWidgets"

class MainMenu : public QWidget
{
    Q_OBJECT

    const QSize WINDOW_SIZE { 700, 540 };
    const QSize BUTTON_SIZE { 300, 30 };

    QString button_style =
            "QPushButton {"
                " border: 1px solid #324ab2;"
                " background: qlineargradient(x1: 0, y1: 1, x2: 0, y2: 0,  stop: 0 #ffb366, stop: 1 #ff4f00);"
                " border-radius: 9px;"
                " color: #324ab2;"
                " font-size: 20px;"
                " font-weight: bold;"
            "}"
            "QPushButton:pressed {"
                " background: qlineargradient(x1: 0, y1: 1, x2: 0, y2: 0,  stop: 0 #ff7433, stop: 1 #ffb366);"
            "}"
            "QPushButton:hover {"
                " color: #33ff33;"
                " border: 1.5px solid #324ab2;"
            "}";

    QPushButton* settings_button;
    QPushButton* exit_button;

public:
    MainMenu(QWidget *parent);

public slots:
    void close_window();
};

#endif // MAINMENU_H
