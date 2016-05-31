FROM ubuntu:14.04.4

MAINTAINER artem.zhuikov@mail.ru

RUN apt-get -y update && apt-get install -y build-essential git qt5-default

RUN git clone https://github.com/Zhuikov/predator-prey.git
RUN qmake /predator-prey/sources/Predator-prey/Predator-prey.pro
RUN make sub-lib
RUN make sub-consoleApp
RUN cp /consoleApp/consoleApp /usr/bin/pp-model

ADD https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh conda.sh
RUN chmod +x conda.sh
RUN ./conda.sh -b -p /opt/anaconda
RUN /opt/anaconda/bin/conda install --quiet --yes jupyter

CMD /opt/anaconda/bin/conda run "jupyter notebook --ip=0.0.0.0 --no-browser"