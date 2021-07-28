FROM asalicode/cantera:2.5-focal-light

ARG ASALI_USER

RUN DEBIAN_FRONTEND=noninteractive apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install sudo \
&& useradd -ms /bin/bash $ASALI_USER \
&& usermod -aG sudo $ASALI_USER \
&& echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

USER $ASALI_USER

WORKDIR /home/$ASALI_USER
RUN sudo DEBIAN_FRONTEND=noninteractive apt-get update -y \
&& sudo DEBIAN_FRONTEND=noninteractive apt-get install --no-install-recommends git g++ gfortran make \
libyaml-cpp-dev libgtkmm-3.0-dev libcanberra-gtk3-module dbus-x11 plplot-driver-qt libplplot-dev dbus -y \
&& git clone https://github.com/srebughini/ASALI.git -b docker --depth=1 \
&& rm -rf /home/$ASALI_USER/ASALI/API \
&& rm -rf /home/$ASALI_USER/ASALI/GUI/Windows

WORKDIR /home/$ASALI_USER/ASALI/GUI/Ubuntu 
RUN bash -c "./build.sh --no-interaction --symbolic-link" \
&& sudo DEBIAN_FRONTEND=noninteractive apt-get autoremove g++ git make -y \
&& sudo rm -rf /var/lib/apt/lists/*

WORKDIR /home/$ASALI_USER/sharedFolder
CMD [ "Asali" ]
