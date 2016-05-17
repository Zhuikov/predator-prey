#include "settingswindow.h"
#include "field.h"

SettingsWindow::SettingsWindow(QWidget* parent, Settings *settings) : QDialog(parent, Qt::WindowTitleHint)
{
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Настройки");
    this->parent = parent;
    this->settings = settings;

    QPixmap background(":/settings_texture2.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);


    field_length_label = createLabel("Длина поля", WINDOW_SIZE.width() - 550, WINDOW_SIZE.height() - 480);
    field_height_label = createLabel("Высота поля", WINDOW_SIZE.width() - 550, WINDOW_SIZE.height() - 430);
    predators_label = createLabel("Количество хищников", WINDOW_SIZE.width() - 550, WINDOW_SIZE.height() - 380);
    preys_label = createLabel("Количество жертв", WINDOW_SIZE.width() - 550, WINDOW_SIZE.height() - 330);
    moves_without_meal_label = createLabel("Время жизни хищника без еды",
                                           WINDOW_SIZE.width() - 550, WINDOW_SIZE.height() - 280);
    success_label = createLabel("Настройки успешно сохранены",
                                WINDOW_SIZE.width() - 500, WINDOW_SIZE.height() - 80, true);

    field_length = createSpinBox(Field::MIN_FIELD_SIZE, Field::MAX_FIELD_SIZE,
                                 WINDOW_SIZE.width() - 170, WINDOW_SIZE.height() - 480);
    field_length->setValue(settings->getFieldLength());

    field_height = createSpinBox(Field::MIN_FIELD_SIZE, Field::MAX_FIELD_SIZE,
                                 WINDOW_SIZE.width() - 170, WINDOW_SIZE.height() - 430);
    field_height->setValue(settings->getFieldHeight());

    predators = createSpinBox( 1, settings->getMaxUnits(), WINDOW_SIZE.width() - 170, WINDOW_SIZE.height() - 380);
    predators->setValue(settings->getNumOfPredators());

    preys = createSpinBox( 1, settings->getMaxUnits(), WINDOW_SIZE.width() - 170, WINDOW_SIZE.height() - 330);
    preys->setValue(settings->getNumOfPreys());

    moves_without_meal = createSpinBox(settings->getMinMovesWithoutMeal(), settings->getMaxMovesWithoutMeal(),
                                       WINDOW_SIZE.width() - 170, WINDOW_SIZE.height() - 280);
    moves_without_meal->setValue(settings->getMovesWithoutMeal());

    back_button = new QPushButton("Назад", this);
    back_button->setStyleSheet(button_style);
    back_button->resize(BUTTON_SIZE);
    back_button->move(WINDOW_SIZE.width() - 600, WINDOW_SIZE.height() - 130);
    connect(back_button, SIGNAL(clicked()), SLOT(closeSettings()));

    save_button = new QPushButton("Сохранить", this);
    save_button->setStyleSheet(button_style);
    save_button->resize(BUTTON_SIZE);
    save_button->move(WINDOW_SIZE.width() - 260, WINDOW_SIZE.height() - 130);
    connect(save_button, SIGNAL(clicked()), SLOT(saveSettings()));
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
                "font-size: 18px;"
                "font-weight: bold");
    spinBox->move(horizontal, vertical);
    spinBox->show();

    return spinBox;
}

void SettingsWindow::closeSettings()
{
    this->hide();
    parent->move(this->x(), this->y());
    parent->show();
}

void SettingsWindow::saveSettings()
{
    settings->setFieldHeight(field_height->value());
    settings->setFieldLength(field_length->value());
    settings->setMovesWithoutMeal(moves_without_meal->value());
    settings->setNumOfPredators(predators->value());
    settings->setNumOfPreys(preys->value());

    success_label->show();
    // todo блокировать кнопку на время
    QTimer::singleShot(1000, success_label, SLOT(hide()));
}
