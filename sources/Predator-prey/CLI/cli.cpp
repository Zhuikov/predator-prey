#include "cli.h"

CLI::CLI(int argc, char *argv[])
{
    assert(argc == 5); // c++11 statement, if false then error

    int field_length = atoi(argv[1]);
    int field_height = atoi(argv[2]);
    int num_of_predators = atoi(argv[3]);
    int num_of_preys = atoi(argv[4]);

    settings = new Settings(field_length, field_height, num_of_predators, num_of_preys);
    logs = new Logging();
}

void CLI::startModel()
{
    model = new Model(settings);

    logs->addLog(model);
    while( model->isEnd() == false ) {
        this->model->movePredators();
        this->model->movePreys();
        this->model->remove();
        logs->addLog(model);
    }
    // todo log winner
}
