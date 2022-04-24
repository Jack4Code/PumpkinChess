pumpkin: main.o BitBoard.o
	g++ main.o BitBoard.o -o pumpkin

BitBoard.o: BitBoard.cpp
	g++ -c BitBoard.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o