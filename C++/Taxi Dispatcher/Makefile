taxi.out: TaxiMain.o Dispatcher.o Taxi.o Graph.o
	g++ -g TaxiMain.o Dispatcher.o Taxi.o Graph.o -o taxi.out
TaxiMain.o: TaxiMain.cpp Dispatcher.h
	g++ -c -g TaxiMain.cpp
Dispatcher.o: Dispatcher.cpp Dispatcher.h Taxi.h Graph.h
	g++ -c -g Dispatcher.cpp
Taxi.o: Taxi.cpp Taxi.h Graph.h
	g++ -c -g Taxi.cpp
Graph.o: Graph.cpp Graph.h
	g++ -c -g Graph.cpp
