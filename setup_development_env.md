# Qt
Download and setup Qt (if you use Windows -- with MinGW setup)

https://www.qt.io/ru/download-open-source/

# Python
## Anaconda
Download and setup distribution Anaconda -- miniconda

http://conda.pydata.org/miniconda.html

There are environments for conda in ppenv.yml file. You should create it in command line:

`conda env create -f ppenv.yml`

Details about conda enviroments see here -- http://conda.pydata.org/docs/using/envs.html 

## Pycharm IDE
Download and setup PyCharm

https://www.jetbrains.com/pycharm/download

Clone repository Predator-Prey, open /notebooks in PyCharm -- 
PyCharm project will be created

File --> Settings --> Project:predator-prey --> Project interpreter

Press the button with cogwheel --> Add Local

Choose in directory miniconda3/envs/ppenv/python.exe

OK and that's all (environment ppenv has already created in command line)
