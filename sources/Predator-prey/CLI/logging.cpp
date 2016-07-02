#include "logging.h"

Logging::Logging(std::string &fileName)
{
    out.open(fileName + ".csv");
}

void Logging::addLog(Model *model)
{
    out << model->getStep() << ","
        << model->getPredatorsNum() << ","
        << model->getPreysNum() << ","
        << model->getGrassNum() << std::endl;
}

Logging::~Logging()
{
    out.close();
}
