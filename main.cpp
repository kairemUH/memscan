///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 4 - memscan - SRE - Spring 2023
///
///
/// memscan - find all legal memory addresses and count number of 'A's in memory
/// 
///
/// @file    memscan.cpp
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

// Memory regions object
// Fill out start adress, end adress, permissions, bytes read, is readable
// Check to see if not readable. If permissions are not readable or it is vvar, then set isreadable to false. Dont read the adresses.
// If is readable, go through and read the adresses and count number of 'A's in memory.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "MemoryRegions.h"

using namespace std;

int main( int argc, char* argv[] ) {

    // Create a list of memory regions
    vector<MemoryRegion> allLegalMemoryRegions;

    /// Open the maps file in read only mode
    ifstream mapFile;

    mapFile.open( "/proc/self/maps", ios::in );

    if( !mapFile ) {

        cout << "Error: could not open file [maps]." << endl;

        return 0;

    }


    // Process file lines and fill in list of memory regions
    string line;

    while( getline(mapFile, line) ) {

        MemoryRegion temp = MemoryRegion( line );

        allLegalMemoryRegions.push_back(temp);

    }


    // Go through array of memory regions and print out data to console
    unsigned int vectorSize = allLegalMemoryRegions.size();

    for( unsigned int i = 0; i < vectorSize; i++ ) {

        if( allLegalMemoryRegions[i].getIsReadable() ) {

            cout << i << ":   " << allLegalMemoryRegions[i].getStartAddress() << " - " << allLegalMemoryRegions[i].getEndAddress() << allLegalMemoryRegions[i].getPermissions()
                 << "  Number of bytes read [" << allLegalMemoryRegions[i].getNumBytesRead() << "]  Number of 'A' is [" << allLegalMemoryRegions[i].getNumAs() << "]" << endl;

        }

    }

    return 0;

}
