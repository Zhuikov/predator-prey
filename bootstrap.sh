#!/bin/bash

echo "Install C++ build tools"
apt-get update
apt-get install -y build-essential qt5-default

echo "Install anaconda"
wget --quiet https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh

chmod +x Miniconda3-latest-Linux-x86_64.sh
./Miniconda3-latest-Linux-x86_64.sh -b -p /opt/anaconda
cat >> /home/vagrant/.bashrc << END
  # For anaconda
  PATH=/opt/anaconda/bin:$PATH
END

echo "Install jupiter"
/opt/anaconda/bin/conda install jupyter
