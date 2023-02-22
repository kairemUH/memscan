///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 4 - memscan - SRE - Spring 2023
///
///
/// memscan - find all legal memory addresses and count number of 'A's in memory
/// 
///
/// @file    MemoryRegions.cpp
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#define debug

#include "MemoryRegions.h"

using namespace std;

////////////////////  Constructors  ////////////////////

MemoryRegion::MemoryRegion( string newFileLine ) {

    // Set fileLine
    MemoryRegion::fileLine = newFileLine;
   
    #ifdef debug
      cout << MemoryRegion::fileLine << endl;
    #endif

    // Set startAddress
    MemoryRegion::startAddress = newFileLine.substr(0,12);

    #ifdef debug
      cout << "startAddress  " << MemoryRegion::startAddress << endl;
    #endif


    // Set endAddress
    MemoryRegion::endAddress = newFileLine.substr(13,12);

    #ifdef debug
      cout << "endAddress  " << MemoryRegion::endAddress << endl;
    #endif

    // Set permissions
    MemoryRegion::permissions = newFileLine.substr(26,4);

    #ifdef debug
      cout << "permissions  " << MemoryRegion::permissions << endl;
    #endif

    // Set pathName
    size_t pathNameStart = newFileLine.find(" /");
    
    if ( pathNameStart == string::npos ) {
        pathNameStart = newFileLine.find(" [");
    }

    if (pathNameStart != string::npos ) {
        MemoryRegion::pathName = newFileLine.substr(pathNameStart);
    }

    else {
       MemoryRegion::pathName = "anonymous";
    }

    #ifdef debug
      cout << "pathName  " << MemoryRegion::pathName << endl;
    #endif

    // Set startAddressValue
    MemoryRegion::startAddressValue = stoul(MemoryRegion::startAddress, nullptr, 16);

    #ifdef debug
      cout << "startAddressValue  " << MemoryRegion::startAddressValue << endl;
    #endif

    // Set endAddressValue
    MemoryRegion::endAddressValue = stoul(MemoryRegion::endAddress, nullptr, 16);

    #ifdef debug
      cout << "endAddressValue  " << MemoryRegion::endAddressValue << endl;
    #endif

    // Set numBytesRead
    MemoryRegion::numBytesRead = (int) ( MemoryRegion::endAddressValue - MemoryRegion::startAddressValue );

    // Set isReadable. If the memory is not readable, then the object is potentially all junk and it should not be used.
    if( (pathName.find("vvar") != string::npos) || (permissions.find("r") == string::npos) || (permissions.find("w") != string::npos) || (permissions.find("x") != string::npos) ) {

        MemoryRegion::isReadable = false;

    }

    else {

        MemoryRegion::isReadable = true;

    }

    #ifdef debug
      cout << "isReadable  " << MemoryRegion::isReadable << endl;
    #endif

    // Set numberOfAs
    if( MemoryRegion::isReadable == true ) {
        
        for( unsigned long i = MemoryRegion::startAddressValue; i <= MemoryRegion::endAddressValue; i++ ) {

            if( * (char*)i == 'A' ) {
                MemoryRegion::numberOfAs++;
            }
            // MemoryRegion::numberOfAs = 1;
        }

    }

    #ifdef debug
      cout << "numberOfAs  " << MemoryRegion::numberOfAs << endl;
    #endif

}


////////////////////  Getters  ////////////////////

string MemoryRegion::getStartAddress() const noexcept {
    return MemoryRegion::startAddress;
}

string MemoryRegion::getEndAddress() const noexcept {
    return MemoryRegion::endAddress;
}

string MemoryRegion::getPermissions() const noexcept {
    return MemoryRegion::permissions;
}

string MemoryRegion::getPathName() const noexcept {
    return MemoryRegion::pathName;
}

bool MemoryRegion::getIsReadable() const noexcept {
    return MemoryRegion::isReadable;
}

int MemoryRegion::getNumBytesRead() const noexcept {
    return MemoryRegion::numBytesRead;
}

int MemoryRegion::getNumAs() const noexcept {
    return MemoryRegion::numberOfAs;
}

unsigned long MemoryRegion::getStartAddressValue() const noexcept {
    return MemoryRegion::startAddressValue;
}

unsigned long MemoryRegion::getEndAddressValue() const noexcept {
    return MemoryRegion::endAddressValue;
}
