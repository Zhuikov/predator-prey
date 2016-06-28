#include "cli.h"

Cli::Cli(int argc, char *argv[])
{
    assert(argc == 9); // c++11 statement, if false then error

    mode = *argv[1];

    int field_length = atoi(argv[2]);
    int field_height = atoi(argv[3]);
    int predators = atoi(argv[4]);
    int preys = atoi(argv[5]);
    int num_of_grass = atoi(argv[6]);
    int grow_interval = atoi(argv[7]);
    int seed = atoi(argv[8]);

    settings = new Settings(field_length, field_height, predators, preys, num_of_grass, grow_interval);
    name = string(argv[2]) + 'x' + argv[3] + '_' + argv[4] + '_' + argv[5] + '_' + argv[6] + '_' + argv[7] + '_' + argv[8];
    model = new Model(settings, seed);
}

int Cli::startModel()
{
    switch( mode ) {
        case 'l' :
        case 'L' : return modeWithLogs();
        case 's' :
        case 'S' : return modeWithSteps();
        case 'w' :
        case 'W' : return modeWithWinner();
    }
    return -100; // some kind of wrong value
}

int Cli::modeWithLogs()
{
    Logging *logs = new Logging(name);
    logs->addLog(model);
    while( model->isEnd() == false ) {
        model->movePredators();
        model->movePreys();
        if (model->getStep() % settings->getGrowInterval() == 0) {
            model->createGrass();
        }
        logs->addLog(model);
    }
    return model->getStep();
}

int Cli::modeWithSteps()
{
    while( model->isEnd() == false )
    {
        model->movePredators();
        model->movePreys();
        if (model->getStep() % settings->getGrowInterval() == 0) {
            model->createGrass();
        }
    }
    return model->getStep();
}

int Cli::modeWithWinner()
{
    while( model->isEnd() == false )
    {
        model->movePredators();
        model->movePreys();
        if (model->getStep() % settings->getGrowInterval() == 0) {
            model->createGrass();
        }
    }
    if (model->getPredatorsNum() > 0 && model->getPreysNum() == 0) return 1; // Predators win
    else if (model->getPredatorsNum() == 0 && model->getPreysNum() == 0) return 0; // Draw
    else if (model->getPredatorsNum() == 0 && model->getPreysNum() > 0) return -1; // Preys win
    return -101; // some kind of wrong value
}
