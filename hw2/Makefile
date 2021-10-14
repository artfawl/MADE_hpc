CC=g++
CFLAGS=-c
LDFLAGS=
OPTIMIZATIONS=-O3
SOURCES=m.cpp func.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=go

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
func.o: func.cpp
	$(CC) $(OPTIMIZATIONS) $(CFLAGS) $< -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o go
