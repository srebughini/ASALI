FROM ubuntu:20.04
MAINTAINER ASALIcode <ste.rebu@outlook.it>

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y 
RUN apt-get install --no-install-recommends apt-utils git pkg-config -y 
RUN apt-get install --no-install-recommends scons -y
RUN apt-get install --no-install-recommends g++ gfortran make -y
RUN apt-get install --no-install-recommends ca-certificates -y
RUN apt-get install --no-install-recommends python3 python3-setuptools python3-tk python3-matplotlib python3-dev python3-ruamel.yaml -y
RUN apt-get install --no-install-recommends libgtkmm-3.0-dev -y
RUN apt-get install --no-install-recommends libboost-dev -y
RUN update-alternatives --install /usr/bin/python python /usr/bin/python3 1

RUN mkdir /app \
&& mkdir /app/cantera \
&& mkdir /app/asali

RUN git clone https://github.com/Cantera/cantera.git /app/cantera/. 

WORKDIR /app/cantera
RUN scons build system_sundials=n python_package=minimal cc_flags='-Os' matlab_toolbox=n doxygen_docs=n sphinx_docs=n debug=n && scons install 

COPY . /app/asali/

WORKDIR /app/asali
RUN make -f Makefile.docker all CANTERA_PREFIX=/usr/local/

FROM ubuntu:20.04
RUN apt-get update -y
RUN apt-get install --no-install-recommends python3 python3-setuptools python3-tk python3-matplotlib python3-dev python3-ruamel.yaml -y
RUN apt-get install --no-install-recommends libgtkmm-3.0-dev -y

RUN mkdir /app \
&& mkdir /app/asali

COPY . /app/asali/

WORKDIR /app/asali
COPY --from=0 /app/asali/Asali .
COPY --from=0 /usr/local/share/cantera /usr/local/share/cantera

CMD [ "./Asali" ]
