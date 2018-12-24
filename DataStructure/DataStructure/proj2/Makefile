CC = clang++
CFLAGS = -Wall -Wextra -c -O2
DEPS = Word.h Hash.h FSTree.h DirNode.h Indexing.h
FLAG = -std=c++11

%.o: %.cpp $(DEPS)
	$(CC) $(FLAG) -o $@ $< $(CFLAGS)
test: Word.o Hash.o FSTree.o DirNode.o Indexing.o test1.o
	$(CC) -o test Word.o Hash.o FSTree.o DirNode.o Indexing.o test1.o
gerp: Word.o Hash.o FSTree.o DirNode.o Indexing.o gerp.o
	$(CC) -o gerp Word.o Hash.o FSTree.o DirNode.o Indexing.o gerp.o
clean:
	rm -f *.o core* *~ test