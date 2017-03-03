#ifndef MAINMENU_H
#define MAINMENU_H
#include "QtWidgets"
#include "exitwindow.h"
#include "settingswindow.h"
#include "modelwindow.h"
#include "model.h"
#include "settings.h"

static const QString button_style =
        "QPushButton {"
            " border: 1px solid #324ab2;"
            " background: qlineargradient(x1: 0, y1: 1, x2: 0, y2: 0,  stop: 0 #000000, stop: 1 #20155e);"
            " border-radius: 9px;"
            " color: #ffd7a8;"
            " font-size: 20px;"
            " font-weight: bold;"
        "}"
        "QPushButton:pressed {"
            " background: qlineargradient(x1: 0, y1: 1, x2: 0, y2: 0,  stop: 0 #20155e, stop: 1 #000000);"
        "}"
        "QPushButton:hover {"
            " color: #ff7e00;"
            " border: 2.3px solid #f75e25;"
        "}";

class MainMenu : public QWidget
{
    Q_OBJECT

    const QSize WINDOW_SIZE { 660, 540 };
    const QSize BUTTON_SIZE { 190, 30 };

    QPushButton* new_model_button;
    QPushButton* settings_button;
    QPushButton* exit_button;

    Settings* settings;

public:
    MainMenu(QWidget *parent, Settings*);

private slots:
    void closeMenu();
    void settingsMenu();
    void createModel();
};

#endif // MAINMENU_H
