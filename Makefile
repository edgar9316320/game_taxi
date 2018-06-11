
#g++ -c main.cpp crazyball.cpp -I ~/Descargas/Aleph-w 


#g++ main.o crazyball.o -o crazyball -L ~/Descargas/Aleph-w -lAleph-w -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

LIBS = -L $(DESIGNAR)/lib -lDesignar -lgsl -lgslcblas -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
DESIGNAR = /home/edgar/Descargas/AYDA/lab04/DeSiGNAR

programa: main.o taxi.o
	g++ main.o taxi.o -o taxi -L $(RUT)/include $(LIBS)
#lAleph-w -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o: main.cpp taxi.h
	g++ -c main.cpp -I $(RUT)/include

taxi.o: taxi.cpp taxi.h
	g++ -c taxi.cpp -I $(RUT)/include

clean:
	rm -f ~*.o
