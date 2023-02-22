///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 4 - memscan - SRE - Spring 2023
///
///
/// memscan - find all legal memory adresses and count number of 'A's in memory
/// 
///
/// @file    memscan.cpp
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

// Memory regions object
// Fill out start adress, end adress, permissions, bytes read, is readable
// Check to see if not readable. If permissions are not readable or it is vvar, then set isreadable to false. Dont read the adresses.
// If is readable, go through and read the adresses and count number of 'A's in memory.

// Create an array of memory regions
// Open and read through maps file and fill in array of memory regions
// Go through array of memory regions and print out data to console

#include <iostream>
#include <cstring>

using namespace std;

struct memoryRegion {

    string fileLine;
    string startAdress;
    string endAdress;
    string permissions;
    int    numBytesRead;
    int    numberOfAs;
    bool   isReadable;

};

int main() {

memoryRegion allLegalMemory[100];

// Open and read through maps file and fill in array of memory regions

return 0;

}
