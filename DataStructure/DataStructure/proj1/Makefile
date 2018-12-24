CC = clang++
CFLAGS = -Wall -Wextra -c
DEPS = BinaryTree.h BinarySearchTree.h Queue.h Survivor.h Tree.h
FLAG = -std=c++11

%.o: %.cpp $(DEPS)
	$(CC) $(FLAG) -o $@ $< $(CFLAGS)
survivor: survivor-driver.o BinaryTree.o BinarySearchTree.o Queue.o Survivor.o 
	$(CC) -o survivor survivor-driver.o BinaryTree.o BinarySearchTree.o Queue.o Survivor.o 
testbt: Survivor.o Queue.o BinaryTree.o test-bt-driver.o 
	$(CC) -o testbt Survivor.o Queue.o BinaryTree.o test-bt-driver.o 
testbst: Survivor.o BinaryTree.o Queue.o BinarySearchTree.o test-bst-driver.o 
	$(CC) -o testbst Survivor.o BinaryTree.o Queue.o BinarySearchTree.o test-bst-driver.o	
clean:
	rm -f *.o core* *~ survivor testbt testbst
