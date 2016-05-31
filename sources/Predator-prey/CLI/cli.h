#ifndef CLI_H
#define CLI_H

#include "model.h"
#include "settings.h"
#include "logging.h"
#include "cassert"

class CLI
{
public:
    CLI(int argc, char *argv[]);

    void startModel();
private:
    Settings *settings;
    Logging *logs;
    Model *model;
};

#endif // CLI_H
