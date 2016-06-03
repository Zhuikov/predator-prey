#ifndef LOGGING_H
#define LOGGING_H

#include "fstream"
#include "model.h"
#include "string"

using std::ofstream;
using std::endl;
using std::string;

class Logging
{
public:
    Logging(string &name);
    void addLog(Model *model);
    ~Logging();

private:
    ofstream out;
};

#endif // LOGGING_H
