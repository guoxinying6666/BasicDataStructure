CC = clang++
CFLAGS = -Wall -Wextra -c
DEPS = Stack.h RPNCalc.h
FLAG = -std=c++11

%.o: %.cpp $(DEPS)
	$(CC) $(FLAG) -o $@ $< $(CFLAGS)
calculator: Stack.o RPNCalc.o run-calc.o
	$(CC) $(FLAG) -o calculator Stack.o RPNCalc.o run-calc.o
stacktest: test-stack.o RPNCalc.o Stack.o
	$(CC) $(FLAG) -o stacktest test-stack.o RPNCalc.o Stack.o
clean:
	rm -f *.o core* *~ calculator
	rm -f *.o core* *~ stacktest
