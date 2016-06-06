#include "cli.h"

using namespace std;

int main(int argc, char *argv[])
{
    Cli cli(argc, argv);
    cli.startModel();

    return 0;
}
