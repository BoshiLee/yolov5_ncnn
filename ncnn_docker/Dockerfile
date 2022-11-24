FROM nvidia/cuda:11.2.0-cudnn8-runtime-ubuntu18.04
SHELL ["/bin/bash", "-c"]
RUN apt update

# Copy our local models into the image



ARG DEBIAN_FRONTEND=noninteractive

RUN apt install --no-install-recommends -y sudo ssh \
    software-properties-common \
    build-essential \
    git \
    cmake \
    wget \
    curl \
    libprotobuf-dev \
    protobuf-compiler \
    libopencv-dev \
    vim

RUN sudo apt update
RUN mkdir /docker_mount
WORKDIR /docker_mount
RUN git clone https://github.com/Tencent/ncnn.git
WORKDIR /docker_mount/ncnn
RUN git submodule update --init
RUN mkdir -p build
WORKDIR /docker_mount/ncnn/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DNCNN_BUILD_EXAMPLES=ON ..
RUN make -j$(nproc)
RUN make install
RUN sudo apt install --no-install-recommends -y python3.8 \
    python3.8-distutils

RUN echo 'alias python=/usr/bin/python3.8' >> ~/.bashrc
RUN source ~/.bashrc

WORKDIR /docker_mount
RUN curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
RUN python3.8 get-pip.py
RUN rm get-pip.py

WORKDIR /docker_mount
RUN git clone https://github.com/shaoshengsong/yolov5_62_export_ncnn
WORKDIR /docker_mount/yolov5_62_export_ncnn/
RUN pip install -r requirements.txt

EXPOSE 3000

# Make the server be the main container command
CMD python api/run.py
