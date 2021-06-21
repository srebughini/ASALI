FROM ubuntu:20.04
#LABEL Author="ASALIcode" email="ste.rebu@outlook.it"

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y && apt-get install --no-install-recommends apt-utils \
git \
pkg-config \
scons \
g++ \
gfortran \
make \
ca-certificates \
python3 \
python3-setuptools \
python3-dev \
python3-ruamel.yaml \
libgtkmm-3.0-dev \
libcanberra-gtk3-module \
libboost-dev \
libplplot-dev -y \
&& update-alternatives --install /usr/bin/python python /usr/bin/python3 1

RUN mkdir /app \
&& mkdir /app/cantera \
&& mkdir /app/asali

WORKDIR /app/
RUN git clone https://github.com/Cantera/cantera.git /app/cantera/. -b 2.5 --depth=1

ADD https://api.github.com/repos/srebughini/ASALI/git/refs/heads/physical-properties version.json
RUN git clone -b physical-properties https://github.com/srebughini/ASALI.git --depth=1 /app/asali/.

WORKDIR /app/cantera
RUN scons build system_sundials=n python_package=minimal cc_flags='-Os' matlab_toolbox=n doxygen_docs=n sphinx_docs=n debug=n && scons install 

WORKDIR /app/asali/GUI/Ubuntu 
RUN bash -c "./build.sh --no-interaction"

CMD [ "./Asali" ]