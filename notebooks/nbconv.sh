#!/bin/bash

time /opt/anaconda/bin/jupyter nbconvert --to html --execute LifeModel.ipynb
time /opt/anaconda/bin/jupyter nbconvert --to html --execute DynamicLifeModel.ipynb

cp /repo/sources/Predator-prey/CLI/CLI /usr/bin/pp-model
time /opt/anaconda/bin/jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute Experiment_1.ipynb
time /opt/anaconda/bin/jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute Experiment_2.ipynb
time /opt/anaconda/bin/jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute Experiment_3.ipynb
time /opt/anaconda/bin/jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute Experiment_4.ipynb
time /opt/anaconda/bin/jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute Experiment_5.ipynb

