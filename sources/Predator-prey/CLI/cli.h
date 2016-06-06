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

    int startModel();
    int modeWithLogs();
    int modeWithSteps();
    int modeWithWinner();

private:
    Settings *settings;
    Model *model;
    Logging *logs;
    string name;
    char mode;
};

#endif // CLI_H
