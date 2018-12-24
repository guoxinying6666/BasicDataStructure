CC = clang++
CFLAGS = -Wall -Wextra -c
DEPS = Tree.h Survivor.h BinaryTree.h BinarySearchTree.h
FLAG = -std=c++11

%.o: %.cpp $(DEPS)
	$(CC) $(FLAG) -o $@ $< $(CFLAGS)
survivor: Stack.o RPNCalc.o run-calc.o
	$(CC) $(FLAG) -o calculator Stack.o RPNCalc.o run-calc.o
bttest: test-stack.o RPNCalc.o Stack.o
	$(CC) $(FLAG) -o stacktest test-stack.o RPNCalc.o Stack.o
bsttest: 
	
clean:
	rm -f *.o core* *~ calculator
	rm -f *.o core* *~ stacktest
