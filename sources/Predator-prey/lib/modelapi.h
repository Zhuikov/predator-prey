#ifndef MODELAPI_H
#define MODELAPI_H


class ModelAPI
{
public:
    ModelAPI();
    void initializeModel();
    void saveModel();
    void loadModel();
    void changeTime();
    int checkPredators();
    int checkPreys();
};
#endif // MODELAPI_H
