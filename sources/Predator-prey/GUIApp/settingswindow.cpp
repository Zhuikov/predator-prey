#include "settingswindow.h"

SettingsWindow::SettingsWindow(QWidget* parent) : QDialog(parent, Qt::WindowTitleHint)
{
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Настройки");
    this->parent = parent;

    QPixmap background(":/settings_texture2.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);
    this->setAutoFillBackground(true);

    field_length_label = createLabel("Длина поля", WINDOW_SIZE.width() - 550, WINDOW_SIZE.height() - 480);
    field_height_label = createLabel("Высота поля", WINDOW_SIZE.width() - 550, WINDOW_SIZE.height() - 430);
    predators_label    = createLabel("Количество хищников", WINDOW_SIZE.width() - 550, WINDOW_SIZE.height() - 380);
    preys_label        = createLabel("Количество жертв", WINDOW_SIZE.width() - 550, WINDOW_SIZE.height() - 330);
    moves_without_meal_label = createLabel("Время жизни хищника без еды",
                                           WINDOW_SIZE.width() - 550, WINDOW_SIZE.height() - 280);
    success_label = createLabel("Настройки успешно сохранены",
                                WINDOW_SIZE.width() - 500, WINDOW_SIZE.height() - 80, true);

    field_length = createSpinBox(10, 30, WINDOW_SIZE.width() - 150, WINDOW_SIZE.height() - 480);
    field_height = createSpinBox(10, 30, WINDOW_SIZE.width() - 150, WINDOW_SIZE.height() - 430);
    // todo изменить максимумы
    predators    = createSpinBox( 1, 30, WINDOW_SIZE.width() - 150, WINDOW_SIZE.height() - 380);
    preys        = createSpinBox( 1, 30, WINDOW_SIZE.width() - 150, WINDOW_SIZE.height() - 330);
    moves_without_meal = createSpinBox(5, 1000, WINDOW_SIZE.width() - 150, WINDOW_SIZE.height() - 280);

    back_button = new QPushButton("Назад", this);
    back_button->setStyleSheet(button_style);
    back_button->resize(BUTTON_SIZE);
    back_button->move(WINDOW_SIZE.width() - 600, WINDOW_SIZE.height() - 130);
    connect(back_button, SIGNAL(clicked()), SLOT(close_settings()));

    save_button = new QPushButton("Сохранить", this);
    save_button->setStyleSheet(button_style);
    save_button->resize(BUTTON_SIZE);
    save_button->move(WINDOW_SIZE.width() - 260, WINDOW_SIZE.height() - 130);
    connect(save_button, SIGNAL(clicked()), SLOT(save_settings()));
}

QLabel* SettingsWindow::createLabel(QString text, int horizontal, int vertical, bool invisiblity)
{
    QLabel* label = new QLabel(this);
    label->setStyleSheet(label_style);
    label->move(horizontal, vertical);
    label->setText(text);
    if (invisiblity == false) {
        label->show();
    }
    else {
        label->hide();
    }

    return label;
}

QSpinBox* SettingsWindow::createSpinBox(int min, int max, int horizontal, int vertical)
{
    QSpinBox* spinBox = new QSpinBox(this);
    spinBox->setRange(min, max);
    spinBox->setStyleSheet(
                "color: #122faa;"
                "font-size: 18px;");
    spinBox->move(horizontal, vertical);
    spinBox->show();

    return spinBox;
}

void SettingsWindow::close_settings()
{
    this->close();
    parent->show();
}

void SettingsWindow::save_settings()
{
    success_label->show();
    // todo блокировать кнопку на время
    QTimer::singleShot(2 * 1000, success_label, SLOT(hide()));
}
