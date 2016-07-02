FROM ubuntu:latest

MAINTAINER artem.zhuikov@mail.ru

RUN apt-get -y update && apt-get install -y build-essential qt5-default
RUN apt-get clean

ADD https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh conda.sh
RUN chmod +x conda.sh
RUN ./conda.sh -b -p /opt/anaconda
ADD https://raw.githubusercontent.com/Zhuikov/predator-prey/develop/ppenv.yml ppenv.yml
RUN /opt/anaconda/bin/conda install --quiet --yes jupyter matplotlib scipy
