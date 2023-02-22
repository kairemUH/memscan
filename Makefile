###############################################################################
###               University of Hawaii, College of Engineering
###               Lab 4 - memscan - SRE - Spring 2023
###
### Build and test a memory scanning program
###
### @see     https://www.gnu.org/software/make/manual/make.html
###
### @file    Makefile
### @author Kai Matsusaka <kairem@hawaii.edu>
###############################################################################


TARGET = memscan

all: $(TARGET)

CC     = g++
CFLAGS = -Wall -Wextra $(DEBUG_FLAGS)

debug: DEBUG_FLAGS = -g -DDEBUG
debug: clean $(TARGET)

MemoryRegions.o: MemoryRegions.cpp MemoryRegions.h
	$(CC) $(CFLAGS) -c MemoryRegions.cpp

main.o: main.cpp MemoryRegions.h
	$(CC) $(CFLAGS) -c main.cpp

memscan: main.o MemoryRegions.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o MemoryRegions.o

test: memscan
	./memscan

clean:
	rm -f $(TARGET) *.o