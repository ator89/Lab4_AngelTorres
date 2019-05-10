main: main.o
    g++ main.o -o main

main.o: lab4.cpp
    g++ -c lab4.cpp
