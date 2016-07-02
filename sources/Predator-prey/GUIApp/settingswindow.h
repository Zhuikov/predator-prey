#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H
#include <QtWidgets>
#include "mainmenu.h"
#include "settings.h"

class SettingsWindow : public QWidget
{
    Q_OBJECT

    Settings* settings;

    const QSize WINDOW_SIZE { 660, 540 };
    const QSize BUTTON_SIZE { 200, 30 };

    QPushButton* back_button;
    QPushButton* save_button;

    QLabel* field_length_label;
    QLabel* field_height_label;
    QLabel* predators_label;
    QLabel* preys_label;
    QLabel* grass_label;
    QLabel* moves_without_meal_label;
    QLabel* grow_interval_label;
    QLabel* success_label;
    QTimer* timer_for_label;


    QSpinBox* field_length;
    QSpinBox* field_height;
    QSpinBox* predators;
    QSpinBox* preys;
    QSpinBox* grass;
    QSpinBox* moves_without_meal;
    QSpinBox* grow_interval;

    QLabel* createLabel(QString text, int horizontal, int vertical, bool invisiblity = false);
    QSpinBox* createSpinBox(int min, int max, int horizontal, int vertical);

public:
    SettingsWindow(QWidget* parent, Settings* settings);

private slots:
    void closeSettings();
    void saveSettings();
    void unlockSaveButton();
};

#endif // SETTINGSWINDOW_H
