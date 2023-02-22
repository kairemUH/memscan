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

#include <iostream>
#include <cstring>

class MemoryRegion {

////////////////////  Member Variables  ////////////////////
private:
   std::string fileLine;
   std::string startAddress;
   std::string endAddress;
   std::string permissions;
   std::string pathName;
    bool   isReadable;
    int    numBytesRead;
    int    numberOfAs;
    unsigned long startAddressValue;
    unsigned long endAddressValue;
    

////////////////////  Constructors  ////////////////////
public:
    MemoryRegion( std::string newFileLine );


////////////////////  Getters  ////////////////////
public:
    std::string getStartAddress() const noexcept;
    std::string getEndAddress() const noexcept;
    std::string getPermissions()  const noexcept;
    std::string getPathName()     const noexcept;
    bool   getIsReadable()      const noexcept;
    int    getNumBytesRead() const noexcept;
    int    getNumAs()   const noexcept;
    unsigned long getStartAddressValue() const noexcept;
    unsigned long getEndAddressValue()   const noexcept;
    
};
