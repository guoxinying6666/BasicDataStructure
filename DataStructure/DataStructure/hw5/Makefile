CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11
DEPS = Actor.h LinkedList.h Stack.h Queue.h Graph.h SixDegrees.h 
 
 %.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

sixdegrees: Actor.o LinkedList.o Stack.o Queue.o Graph.o SixDegrees.o main.o 
	$(CC) -o sixdegrees Actor.o LinkedList.o Stack.o Queue.o Graph.o SixDegrees.o main.o
graphtest: Actor.o LinkedList.o Stack.o Queue.o Graph.o SixDegrees.o test-graph.o
	$(CC) -o graphtest Actor.o LinkedList.o Stack.o Queue.o Graph.o SixDegrees.o test-graph.o
test1: Actor.o LinkedList.o Stack.o Queue.o Graph.o SixDegrees.o test-actors.o
	$(CC) -o test1 Actor.o LinkedList.o Stack.o Queue.o Graph.o SixDegrees.o test-actors.o
clean:
	rm -f *.o core* *~ er
