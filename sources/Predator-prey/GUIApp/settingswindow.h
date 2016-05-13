#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H
#include <QtWidgets>
#include "mainmenu.h"

class SettingsWindow : public QDialog
{
    Q_OBJECT

    const QSize WINDOW_SIZE { 660, 540 };
    const QSize BUTTON_SIZE { 200, 30 };

    QPushButton* back_button;
    QPushButton* save_button;

    QLabel* success_label;
    QTimer* timer_for_label;

    QString label_style =
                "color: #122faa;"
                "font-size: 20px;"
                "font-weight: bold;";
    QLabel* field_length_label;
    QLabel* field_height_label;
    QLabel* predators_label;
    QLabel* preys_label;
    QLabel* moves_without_meal_label;

    QSpinBox* field_length;
    QSpinBox* field_height;
    QSpinBox* predators;
    QSpinBox* preys;
    QSpinBox* moves_without_meal;

    QWidget* parent;

    QLabel* createLabel(QString text, int horizontal, int vertical, bool invisiblity = false);
    QSpinBox* createSpinBox(int min, int max, int horizontal, int vertical);

public:
    explicit SettingsWindow(QWidget* parent);

private slots:
    void close_settings();
    void save_settings();
};

#endif // SETTINGSWINDOW_H
