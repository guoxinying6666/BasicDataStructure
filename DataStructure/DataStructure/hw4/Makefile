CC = clang++
CFLAGS = -Wall -Wextra -c
DEPS = Patient.h Heap.h MinHeap.h MaxHeap.h
FLAG = -std=c++11

%.o: %.cpp $(DEPS)
	$(CC) $(FLAG) -o $@ $< $(CFLAGS)
heaps: Patient.o Heap.o MinHeap.o MaxHeap.o intake.o 
	$(CC) -o heapify Patient.o Heap.o  MinHeap.o MaxHeap.o intake.o 
test: test-min-heap.o Patient.o Heap.o MinHeap.o MaxHeap.o
	$(CC) -o test test-min-heap.o Patient.o Heap.o MinHeap.o MaxHeap.o
clean:
	rm -f *.o core* *~ er
