#include "logging.h"

Logging::Logging(std::string &name)
{
    out.open(name + ".csv");
}

void Logging::addLog(Model *model)
{
    // this is for csv
    out << model->getStep() << ","
        << model->getPredatorsNum() << ","
        << model->getPreysNum() << std::endl;

    // this is for txt
    // out << model->getStep() << " "
    //     << model->getPredatorsNum() <<  " "
    //     << model->getPreysNum() << std::endl;
}

Logging::~Logging()
{
    out.close();
}
