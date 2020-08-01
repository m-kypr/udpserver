#!/usr/bin/sh

set -e
g++ UDPServer.cpp -o server
screen -S udp -d -m ./server 2223
