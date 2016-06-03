#include "cli.h"

Cli::Cli(int argc, char *argv[])
{
    assert(argc == 6); // c++11 statement, if false then error

    int field_length = atoi(argv[1]);
    int field_height = atoi(argv[2]);
    int predators = atoi(argv[3]);
    int preys = atoi(argv[4]);
    int seed = atoi(argv[5]);

    // todo add seet to settings
    settings = new Settings(field_length, field_height, predators, preys);

    string name = string(argv[1]) + 'x' + argv[2] + '_' + argv[3] + '_' + argv[4] + '_' + argv[5];
    logs = new Logging(name);
}

void Cli::startModel()
{
    model = new Model(settings);

    logs->addLog(model);
    while( model->isEnd() == false ) {
        model->movePredators();
        model->movePreys();
        model->remove();
        logs->addLog(model);
    }
    // todo log winner
}
