#!/usr/bin/env sh
apt-get install -y git
git submodule update --init --recursive
apt-get install -y cmake g++  # add sudo according to taste
apt-get install -y ctags
#apt-get install -y google-mock
