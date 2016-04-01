#include <iostream>
#include "modelapi.h"
#include "consoleDialog.h"
#include"exceptions.h"

int main()
{
    Settings settings;
    ConsoleDialog CD(&settings);
    try {
    CD.menuPresentation();
    }
    catch (BadFieldBoundary& e)
    {
        e.showMessage();
        CD.menuPresentation();
    }

    return 0;
}
