FROM python:3.8.7-buster

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y
RUN apt-get install --no-install-recommends scons \
python3-ruamel.yaml \
python3-yaml \
build-essential \
libgtkmm-3.0-dev \
g++ \
gfortran \
git \
python \
libboost-dev \
cython \
python-dev \
python-numpy \
python-numpy-dev \
python-setuptools \
python3 \
python3-dev \
python3-setuptools \
python3-numpy \
cython3 \
python3-matplotlib -y

RUN update-alternatives --install /usr/bin/python python /usr/bin/python3 1

RUN mkdir /app && mkdir /app/asali
COPY . /app/asali/

WORKDIR /app
RUN git clone https://github.com/Cantera/cantera.git

WORKDIR /app/cantera
RUN scons build system_sundials=n && scons install

WORKDIR /app/asali
RUN make all CANTERA_PREFIX=/usr/local/

CMD [ "./Asali" ]
