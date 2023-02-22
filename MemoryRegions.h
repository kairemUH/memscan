///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 4 - memscan - SRE - Spring 2023
///
///
/// memscan - find all legal memory addresses and count number of 'A's in memory
/// 
///
/// @file    MemoryRegions.h
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#pragma once

class MemoryRegion {

////////////////////  Member Variables  ////////////////////
private:
    string fileLine;
    string startAddress;
    string endAddress;
    string permissions;
    string pathName;
    bool   isReadable;
    int    numBytesRead;
    int    numberOfAs;
    unsigned long startAddressValue;
    unsigned long endAddressValue;
    

////////////////////  Constructors  ////////////////////
public:
    MemoryRegion( string newFileLine );


////////////////////  Getters  ////////////////////
public:
    string getPermissions()  const noexcept;
    string getPathName()     const noexcept;
    bool   isReadable()      const noexcept;
    int    getnumBytesRead() const noexcept;
    int    getnumberOfAs()   const noexcept;
    unsigned long getStartAddressValue() const noexcept;
    unsigned long getEndAddressValue()   const noexcept;
    
};
