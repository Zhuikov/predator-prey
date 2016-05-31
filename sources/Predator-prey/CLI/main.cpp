#include "cli.h"

using namespace std;

int main(int argc, char *argv[])
{
    CLI cli(argc, argv);
    cli.startModel();

    return 0;
}
