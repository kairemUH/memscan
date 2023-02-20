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

CC     = gcc
CFLAGS = -Wall -Wextra $(DEBUG_FLAGS)

debug: DEBUG_FLAGS = -g -DDEBUG
debug: clean $(TARGET)

memscan: memscan.c
	$(CC) $(CFLAGS) -o $(TARGET) memscan.c

test: memscan
	./memscan

clean:
	rm -f $(TARGET) *.o