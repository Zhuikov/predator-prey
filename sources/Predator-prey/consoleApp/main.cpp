#include <iostream>
#include "modelapi.h"
#include "consoleDialog.h"
#include"exceptions.h"

int main()
{
    Settings settings;
    ConsoleDialog CD(&settings);
    while (CD.menuPresentation()) {
    try {
            CD.menuPresentation();
    }
    catch (BadFieldBoundary& e)
    {
        e.showMessage();
    }
    catch (BadNumOfPredators& e)
    {
        e.showMessage();

    }
    catch (BadNumOfPreys& e)
    {
        e.showMessage();
    }
    }
    return 0;
}
