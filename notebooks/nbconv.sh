#!/bin/bash

time jupyter nbconvert --to html --execute LifeModel.ipynb
#cp /repo/sources/Predator-prey/CLI/CLI /usr/bin/pp-model
time jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute AgentsToSteps.ipynb
time jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute SeedToSteps.ipynb
time jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute SpaceToAgent.ipynb
