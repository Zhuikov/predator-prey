#include "seedwindow.h"

SeedWindow::SeedWindow(QWidget* parent, Settings* settings) : QDialog(parent, Qt::WindowTitleHint)
{
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("New seed");

    QPixmap background(":/texture.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);

    this->settings = settings;

    ok_button = new QPushButton("OK", this);
    ok_button->setStyleSheet(button_style);
    ok_button->move(WINDOW_SIZE.width() / 2 - BUTTON_SIZE.width() / 2, 50);
    ok_button->resize(BUTTON_SIZE);
    connect(ok_button, SIGNAL(clicked()), SLOT(ok()));

    seed_label = new QLabel(this);
    seed_label->setStyleSheet(
                "color: #122faa;"
                "font-size: 18px;"
                "font-weight: bold;");
    seed_label->move(25, 13);
    seed_label->setText("Set another seed");

    seed_line = new QLineEdit(this);
    seed_line->move(220, 14);
    seed_line->resize(80, 20);
    seed_line->setStyleSheet(
               "font-weight: bold;"
               "font-size: 14px;"
               "color: #122faa");
    QString number = QString::number(settings->getSeed());
    seed_line->setText(number);
}

void SeedWindow::ok()
{
    QString number = seed_line->text();
    settings->setSeed(number.toInt());
    this->close();
}
