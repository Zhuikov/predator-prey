#!/bin/bash

/opt/anaconda/bin/jupyter nbconvert --to notebook --execute /repo/notebooks/LifeModel.ipynb
cp /repo/sources/Predator-prey/CLI/CLI /usr/bin/pp-model
/opt/anaconda/bin/jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --stdout --to notebook --execute /repo/notebooks/ModelLaunchExample.ipynb
