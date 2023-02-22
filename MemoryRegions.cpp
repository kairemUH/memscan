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

#include <iostream>
#include <string>

#include "MemoryRegions.h"

using namespace std;

////////////////////  Constructors  ////////////////////

MemoryRegion::MemoryRegion( string newFileLine ) {

    // Set fileLine
    strcpy( MemoryRegion::fileLine, newFileLine );

    // Set startAddress
    MemoryRegion::startAddress = newFileLine.substr(0,12);

    // Set endAddress
    MemoryRegion::endAddress = newFileLine.substr(13,12);

    // Set permissions
    MemoryRegion::permissions = newFileLine.substr(26,4);

    // Set pathName
    size_t pathNameStart = newFileLine.find(" /");
    if ( pathNameStart == string::npos ) {
        pathNameStart = newFileLine.find(" [");
    }
    // @todo throw exception if still npos

    MemoryRegion::pathName = newFileLine.substr(pathNameStart);

    // Set startAddressValue
    MemoryRegion::startAddressValue = stoul(MemoryRegion::startAddress, nullptr, 16);

    // Set endAddressValue
    MemoryRegion::endAddressValue = stoul(MemoryRegion::endAddress, nullptr, 16);

    // Set numBytesRead
    MemoryRegion::numBytesRead = (int) ( MemoryRegion::startAddressValue - MemoryRegion::endAddressValue );

    // Set isReadable. If the memory is not readable, then the object is potentially all junk and it should not be used.
    if( (pathName.find("vvar") != string::npos) || (permissions.find("r") == string::npos) ) {

        MemoryRegion::isReadable = false;

    }

    else {

        MemoryRegion::isReadable = true;

    }

    // Set numberOfAs
    if( MemoryRegion::isReadable == true ) {
        
        for( unsigned long i = MemoryRegion::startAddressValue; i <= MemoryRegion::endAddressValue; i++ ) {

            if( * (void*)i == 'A' ) {
                MemoryRegion::numberOfAs++;
            }

        }

    }

}


////////////////////  Getters  ////////////////////

string MemoryRegion::getPermissions() const noexcept {
    return MemoryRegion::permissions;
}

string MemoryRegion::getPathName() const noexcept {
    return MemoryRegion::pathName;
}

bool MemoryRegion::isReadable() const noexcept {
    return MemoryRegion::isReadable;
}

int MemoryRegion::getnumBytesRead() const noexcept {
    return MemoryRegion::numBytesRead;
}

int MemoryRegion::getnumberOfAs() const noexcept {
    return MemoryRegion::numberOfAs;
}

unsigned long MemoryRegion::getStartAddressValue() const noexcept {
    return MemoryRegion::startAddressValue;
}

unsigned long MemoryRegion::getEndAddressValue() const noexcept {
    return MemoryRegion::endAddressValue;
}
