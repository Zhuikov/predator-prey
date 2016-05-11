#ifndef MAINMENU_H
#define MAINMENU_H
#include "QtWidgets"
#include "exitwindow.h"

/// это просто ужасно...
/// эту вещь хочется закинуть в класс, но компилятор не дает. Пишет, что что-то там не литерал(
/// а вот так компилирует
static const QString button_style =
        "QPushButton {"
            " border: 1px solid #324ab2;"
            " background: qlineargradient(x1: 0, y1: 1, x2: 0, y2: 0,  stop: 0 #122faa, stop: 1 #24a4ff);"
            " border-radius: 9px;"
            " color: #ffd7a8;"
            " font-size: 20px;"
            " font-weight: bold;"
        "}"
        "QPushButton:pressed {"
            " background: qlineargradient(x1: 0, y1: 1, x2: 0, y2: 0,  stop: 0 #24a4ff, stop: 1 #0047ab);"
        "}"
        "QPushButton:hover {"
            " color: #33ff33;"
            " border: 2px solid #f07000;"
        "}";

class MainMenu : public QWidget
{
    Q_OBJECT

    const QSize WINDOW_SIZE { 660, 540 };
    const QSize BUTTON_SIZE { 300, 30 };

    QPushButton* settings_button;
    QPushButton* exit_button;

    QDialog* exit_menu;

public:
    explicit MainMenu(QWidget *parent);

private slots:
    void close_menu();
};

#endif // MAINMENU_H
