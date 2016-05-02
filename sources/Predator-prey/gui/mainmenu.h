#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>

class MainMenu : public QWidget
{
    Q_OBJECT

    const QSize screen_size{800, 640};
public:

    MainMenu(QWidget *parent);
};

#endif // MAINWINDOW_H
