#ifndef CLI_H
#define CLI_H

#include "model.h"
#include "settings.h"
#include "logging.h"
#include "cassert"
#include "string"

using std::string;

class Cli
{
public:
    Cli(int argc, char *argv[]);

    void startModel();
private:
    Settings *settings;
    Logging *logs;
    Model *model;
};

#endif // CLI_H
