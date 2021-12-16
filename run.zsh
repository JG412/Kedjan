#!/bin/zsh
echo "\n********START********\n"
g++ -std=c++20 -g -Wall main.cpp
./a.out
echo "\n********END********\n"
./check.sh