all: main.o Menu.o Array.o LL.o Stack.o Queue.o node.o
	g++ -Wall -o main main.o Menu.o Array.o LL.o Stack.o Queue.o node.o

main.o:	main.cpp Menu.h
	g++ -Wall -c main.cpp

Menu.o: Menu.cpp Menu.h 
	g++ -Wall -c Menu.cpp

Array.o: Array.cpp Array.h 
	g++ -Wall -c Array.cpp

node.o: node.cpp node.h 
	g++ -Wall -c node.cpp

LL.o: LL.cpp Classes.h
	g++ -Wall -c LL.cpp
  
Stack.o: Stack.cpp Classes.h
	g++ -Wall -c Stack.cpp

Queue.o: Queue.cpp Classes.h
	g++ -Wall -c Queue.cpp

clean:	
	rm -f main *.o *.gch