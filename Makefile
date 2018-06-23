
#g++ -c main.cpp crazyball.cpp -I ~/Descargas/Aleph-w 


#g++ main.o crazyball.o -o crazyball -L ~/Descargas/Aleph-w -lAleph-w -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

DESIGNAR = /home/debian/Descargas/DeSiGNARedg/DeSiGNAR

CXX = clang++ -std=c++14

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses -Wno-invalid-source-encoding

FLAGS = -DDEBUG -D_GLIBCXX__PTHREADS -g -O0 $(WARN) 

OPT = -DNDEBUG -Ofast $(WARN)

INCLUDE = -I. -I $(DESIGNAR)/include

LIBS = taxi.o -L $(DESIGNAR)/lib -lDesignar -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: main

main: taxi.o main.cpp
	$(CXX) $(FLAGS) $(INCLUDE) $@.cpp -o $@ $(LIBS)

taxi.o: taxi.h taxi.cpp
	$(CXX) -c $(FLAGS) $(INCLUDE) taxi.cpp

clean:
	$(RM) *~ main *.o

