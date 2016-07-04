#!/bin/bash
export PATH=$PATH:/opt/anaconda/bin/

time jupyter nbconvert --to html --execute LifeModel.ipynb
time jupyter nbconvert --to html --execute DynamicLifeModel.ipynb

cp /repo/sources/Predator-prey/CLI/CLI /usr/bin/pp-model
time jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute Experiment_1.ipynb
time jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute Experiment_2.ipynb
time jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute Experiment_3.ipynb
time jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute Experiment_4.ipynb
time jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute Experiment_5.ipynb
time jupyter nbconvert  --ExecutePreprocessor.timeout=6000 --to html --execute Experiment_6.ipynb

