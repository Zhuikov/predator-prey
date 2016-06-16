#!/bin/bash

time jupyter nbconvert --to notebook --execute LifeModel.ipynb
#cp /repo/sources/Predator-prey/CLI/CLI /usr/bin/pp-model
time jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to notebook --execute AgentsToSteps.ipynb
time jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to notebook --execute SeedToSteps2.ipynb
time jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to notebook --execute SS.ipynb
