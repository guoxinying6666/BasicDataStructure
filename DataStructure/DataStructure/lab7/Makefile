CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11
DEPS = HashTable.h HashString.h
 
 %.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

hasher: hash-experiment.o HashTable.o HashString.o
	$(CC) -o hasher hash-experiment.o HashTable.o HashString.o

clean:
	rm -f *.o core* *~ hasher
