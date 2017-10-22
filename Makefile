CXX=g++
CFLAGS=
LFLAGS=

all: row.o
	$(CXX) $(LFLAGS) -o rownania row.o

row.o:
	$(CXX) $(CFLAGS) -c row.cpp

clean:
	rm -f rownania row.o
