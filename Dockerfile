FROM ubuntu:16.04

MAINTAINER Chuck Fairy <charlieabeling@gmail.com>

RUN echo "building simple docker image"

CMD echo "Hello Container"

RUN apt-get -qq update

RUN apt-get -y install g++ cmake git subversion libboost-all-dev

RUN git clone https://github.com/chuckfairy/plush.git /plush
RUN cd /plush; git submodule update --init; cmake .; make
