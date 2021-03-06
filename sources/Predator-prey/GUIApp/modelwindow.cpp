#include "modelwindow.h"
#include "resultwindow.h"

ModelWindow::ModelWindow(QWidget* parent, Settings* settings) : QWidget(parent, Qt::WindowTitleHint)
{
    this->settings = settings;
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Predator-prey");

    model = new Model(this->settings, seed);

    QPixmap background(":/settings_texture2.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);

    start_button = new QPushButton("Start", this);
    start_button->setStyleSheet(button_style);
    start_button->resize(BUTTON_SIZE);
    start_button->move(WINDOW_SIZE.width() - 640, WINDOW_SIZE.height() - 515);
    connect(start_button, SIGNAL(clicked()), SLOT(startModel()));

    generate_button = new QPushButton("Generate", this);
    generate_button->setStyleSheet(button_style);
    generate_button->resize(BUTTON_SIZE);
    generate_button->move(WINDOW_SIZE.width() - 420, WINDOW_SIZE.height() - 515);
    connect(generate_button, SIGNAL(clicked()), SLOT(generateModel()));

    menu_button = new QPushButton("Back to menu", this);
    menu_button->setStyleSheet(button_style);
    menu_button->resize(BUTTON_SIZE);
    menu_button->move(WINDOW_SIZE.width() - 200, WINDOW_SIZE.height() - 515);
    connect(menu_button, SIGNAL(clicked()), SLOT(exitToMenu()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveModel()));

    field = new FieldFrame(this, model->getField());
    field->show();

    status = new StatusFrame(this, model);
    status->show();
    status->drawStatus();
}

ModelWindow::~ModelWindow()
{
    this->~QWidget();
    delete model;
}

void ModelWindow::exitToMenu()
{
    MainMenu* menu_window = new MainMenu(0, settings);
    menu_window->move(this->x(), this->y());
    menu_window->show();
    this->close();
    delete model;
    timer->stop();
}

void ModelWindow::startModel()
{
    start_button->setEnabled(false);
    generate_button->setEnabled(false);
    timer->start(TIME_FOR_MOVE);
}

void ModelWindow::moveModel()
{
    model->move();
    field->update();
    status->drawStatus();
    if (model->isEnd() == true) {
        endModel();
    }
}

void ModelWindow::generateModel()
{
    SeedWindow* seed_window = new SeedWindow(this);
    seed_window->exec();
    delete seed_window;

    delete model;
    delete field;
    delete status;

    model = new Model(settings, seed);
    field = new FieldFrame(this, model->getField());
    status = new StatusFrame(this, model);
    field->show();
    status->show();
    status->drawStatus();

    start_button->setEnabled(true);
}

void ModelWindow::endModel()
{
    timer->stop();
    if (model->getPredatorsNum() == 0) {
        ResultWindow* result = new ResultWindow(this, "preys");
        result->exec();
        delete result;
    }
    if (model->getPreysNum() == 0) {
        ResultWindow* result = new ResultWindow(this, "predators");
        result->exec();
        delete result;
    }
    generate_button->setEnabled(true);
}
