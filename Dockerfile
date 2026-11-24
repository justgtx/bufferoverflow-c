
FROM kalilinux/kali-rolling

WORKDIR /H@cker$


RUN apt-get update && apt-get install -y \
    build-essential \
    libc6-dev \
    gdb \
    wireshark \
    tshark \
    tcpdump

RUN useradd -m -s /bin/bash ghost

COPY . .
RUN gcc -o challenge challenge_1/challenge.c

RUN chmod 711 hidden_secrets.h
RUN chmod 711 challenge_1/secret.h
USER ghost

CMD ["/bin/bash"]
