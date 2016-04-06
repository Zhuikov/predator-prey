#include <iostream>
#include "modelapi.h"
#include "consoleDialog.h"
#include"exceptions.h"

int main()
{
    Settings settings;
    ConsoleDialog CD(&settings);

    int flag = 0;

    while(!flag) {
        try {
        flag = 1;
        CD.menuPresentation();
        }
        catch (BadFieldBoundary& e)
        {
            flag = 0;
            e.showMessage();
        }
        catch (BadNumOfPredators& e)
        {
            flag = 0;
            e.showMessage();
        }
        catch (BadNumOfPreys& e)
        {
            flag = 0;
            e.showMessage();
        }
    }


    return 0;
}
