FROM gcc:latest
FROM kalilinux/kali-rolling
WORKDIR /bufferoverflow
COPY . .
RUN gcc -o challenge challenge.c
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    libc6-dev \
    wireshark\
    \gdb\
    \helix\
    && rm -rf /var/lib/apt/lists/*
RUN chmod 711 secret.h
USER ghost
RUN useradd -m ghost
CMD ["./challenge"]