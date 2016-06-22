#include "modelwindow.h"
#include "resultwindow.h"

ModelWindow::ModelWindow(QWidget* parent, Settings* settings) : QWidget(parent, Qt::WindowTitleHint)
{
    this->settings = settings;
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Хищник-жертва");

    model = new Model(this->settings);

    QPixmap background(":/settings_texture2.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);

    start_button = new QPushButton("Старт", this);
    start_button->setStyleSheet(button_style);
    start_button->resize(BUTTON_SIZE);
    start_button->move(WINDOW_SIZE.width() - 640, WINDOW_SIZE.height() - 515);
    connect(start_button, SIGNAL(clicked()), SLOT(startModel()));

    generate_button = new QPushButton("Сгенерировать", this);
    generate_button->setStyleSheet(button_style);
    generate_button->resize(BUTTON_SIZE);
    generate_button->move(WINDOW_SIZE.width() - 420, WINDOW_SIZE.height() - 515);
    connect(generate_button, SIGNAL(clicked()), SLOT(generateModel()));

    menu_button = new QPushButton("Выйти в меню", this);
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
    model->movePredators();
    model->movePreys();
    if (model->getStep() % settings->getGrowInterval() == 0) {
        model->createGrass();
    }
    field->update();
    status->drawStatus();
    if (model->isEnd() == true) {
        endModel();
    }
}

void ModelWindow::generateModel()
{
    delete field;
    delete status;
    delete model;
    model = new Model(settings);
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
