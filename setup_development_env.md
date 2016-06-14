# Qt
Скачать и установить Qt (В случае windows -- с установкой MinGW)

https://www.qt.io/ru/download-open-source/

# Python
## Anaconda
Скачать и установить дистрибутив Anaconda -- miniconda

http://conda.pydata.org/miniconda.html

в файле ppenv.yml содержится окружения для conda, следует создать его в командной строке

`conda env create -f ppenv.yml`

подробнее об окружениях conda -- http://conda.pydata.org/docs/using/envs.html

## Pycharm IDE
Скачать и установить pycharm

https://www.jetbrains.com/pycharm/download

Сделать клон репозитория predator-prey, открыть папку с репозиторием в pycharm --
будет создан проект pycharm

File --> Settings --> Project:predator-prey --> Project interpreter

Там нажать на кнопку с шестеренкой --> Add Local

Там выбрать в папке с miniconda3/envs/ppenv/python.exe

 OK и все подхватится (окружение ppenv должно быть уже создано из командной строки)
