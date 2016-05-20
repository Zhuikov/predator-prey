#include "resultwindow.h"

ResultWindow::ResultWindow(QWidget* parent, QString winners) : QDialog(parent, Qt::WindowTitleHint)
{
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Результат");

    QPixmap background(":/texture.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);

    ok_button = new QPushButton("ОК", this);
    ok_button->setStyleSheet(button_style);
    ok_button->move(WINDOW_SIZE.width() / 2 - BUTTON_SIZE.width() / 2, 50);
    ok_button->resize(BUTTON_SIZE);
    connect(ok_button, SIGNAL(clicked()), SLOT(closeWindow()));

    result_label = new QLabel(this);
    result_label->setStyleSheet(
                "color: #122faa;"
                "font-size: 18px;"
                "font-weight: bold;");
    if (winners == "predators") {
        result_label->setText("Хищники съели всех жертв");
        result_label->move(20, 10);
    }
    else {
        result_label->setText("Жертвы убежали от хищников");
        result_label->move(5, 10);
    }
    result_label->show();
}

void ResultWindow::closeWindow()
{
    this->close();
}
