FROM ubuntu:14.04.4

MAINTAINER artem.zhuikov@mail.ru

RUN apt-get -y update && apt-get install -y wget build-essential qt5-default

RUN /usr/bin/wget --quiet https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh
RUN chmod +x Miniconda3-latest-Linux-x86_64.sh
RUN ./Miniconda3-latest-Linux-x86_64.sh -b -p /opt/anaconda
RUN /opt/anaconda/bin/conda install --quiet --yes jupyter

CMD /opt/anaconda/bin/conda run "jupyter notebook --ip=0.0.0.0"