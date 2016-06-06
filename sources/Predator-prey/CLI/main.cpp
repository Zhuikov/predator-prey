#include "cli.h"

using namespace std;

int main(int argc, char *argv[])
{
    Cli cli(argc, argv);

    return cli.startModel();
}
