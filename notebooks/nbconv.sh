#!/bin/bash

/opt/anaconda/bin/jupyter nbconvert --to notebook --execute /repo/notebooks/LifeModel.ipynb
cp /repo/sources/Predator-prey/CLI/CLI /usr/bin/pp-model
/opt/anaconda/bin/jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to notebook --execute /repo/notebooks/AgentsToSteps.ipynb
time pp-model S 200 200 3000 3000 13
#/opt/anaconda/bin/jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to notebook --execute /repo/notebooks/SeedToSteps2.ipynb
