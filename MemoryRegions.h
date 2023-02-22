///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 4 - memscan - SRE - Spring 2023
///
///
/// memscan - find all legal memory adresses and count number of 'A's in memory
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
    string startAdress;
    string endAdress;
    string permissions;
    int    numBytesRead;
    int    numberOfAs;
    bool   isReadable;


////////////////////  Constructors  ////////////////////
public:
    MemoryRegion( string newFileLine ) noexcept;


////////////////////  Getters  ////////////////////
public:
    string getStartAdress()  const noexcept;
    string getEndAdress()    const noexcept;
    string getPermissions()  const noexcept;
    int    getnumBytesRead() const noexcept;
    int    getnumberOfAs()   const noexcept;
    bool   getisReadable()   const noexcept;

};
