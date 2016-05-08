#ifndef MAINMENU_H
#define MAINMENU_H
#include "QtWidgets"

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent);
private:

    const QSize SCREEN_SIZE { 800, 640 };
    const QSize BUTTON_SIZE { 350, 30 };

//    QString button_style =
//            "QPushButton {"
//                "border: "
//                "background: "
//                "background: "
//                "padding: "
//                "border-radius: "
//                "color: "
//                "font-size: "
//            "}";

    QPushButton* exit_button;
};

#endif // MAINMENU_H
