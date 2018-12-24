CC = clang++
CFLAGS = -Wall -Wextra -c
DEPS = LinkedList.h Planet.h
FLAG = -std=c++11

%.o: %.cpp $(DEPS)
	$(CC) $(FLAG) -o $@ $< $(CFLAGS)

planets: Planet.o LinkedList.o planet-driver.o
	$(CC) $(FLAG) -o planets Planet.o LinkedList.o planet-driver.o

test: test-driver.o Planet.o LinkedList.o
	$(CC) $(FLAG) -o test Planet.o LinkedList.o test-driver.o

clean:
	rm -f *.o core* *~ planets