FROM ubuntu:20.04

ARG ASALI_USER

RUN DEBIAN_FRONTEND=noninteractive apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install sudo \
&& useradd -ms /bin/bash $ASALI_USER \
&& usermod -aG sudo $ASALI_USER \
&& echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

USER $ASALI_USER

RUN sudo DEBIAN_FRONTEND=noninteractive apt-get update -y \
&& sudo DEBIAN_FRONTEND=noninteractive apt-get install --no-install-recommends apt-utils \
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
libboost-dev -y \
dbus \
dbus-x11 \
plplot-driver-qt \
libplplot-dev -y \
&& sudo DEBIAN_FRONTEND=noninteractive update-alternatives --install /usr/bin/python python /usr/bin/python3 1 \
&& sudo rm -rf /var/lib/apt/lists/* \
&& mkdir /home/$ASALI_USER/sharedFolder

WORKDIR /home/$ASALI_USER
RUN git clone https://github.com/Cantera/cantera.git -b 2.5 --depth=1 \
&& git clone https://github.com/srebughini/ASALI.git -b physical-properties --depth=1 \
&& rm -rf /home/$ASALI_USER/ASALI/API \
&& rm -rf /home/$ASALI_USER/ASALI/GUI/Windows

WORKDIR /home/$ASALI_USER/cantera
RUN scons build system_sundials=n python_package=minimal cc_flags='-Os' matlab_toolbox=n doxygen_docs=n sphinx_docs=n debug=n && sudo scons install

WORKDIR /home/$ASALI_USER/ASALI/GUI/Ubuntu 
RUN bash -c "./build.sh --no-interaction --symbolic-link"

WORKDIR /home/$ASALI_USER/sharedFolder
CMD [ "Asali" ]