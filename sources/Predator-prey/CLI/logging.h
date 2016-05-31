#ifndef LOGGING_H
#define LOGGING_H

#include "fstream"
#include "model.h"

using std::ofstream;
using std::endl;

class Logging
{
public:
    Logging();
    void addLog(Model *model);
    ~Logging();

private:
    ofstream out;
};

#endif // LOGGING_H
