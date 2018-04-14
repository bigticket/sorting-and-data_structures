CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: AVLTREE
	./AVLTREE

AVLTREE: o/main.o 
	g++ -Wall -pedantic -o AVLTREE o/main.o

o/main.o: cpp/main.cpp hh/avltree.hh
	g++ ${CPPFLAGS} -o o/main.o cpp/main.cpp 

clean:
	rm -f obj/*.o AVLTREE


 
