mi_exe: lab4.o
        g++ lab4.o -o mi_exe

lab4.o: lab4.cpp
        g++ -c lab4.cpp