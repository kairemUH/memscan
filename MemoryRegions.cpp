///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 4 - memscan - SRE - Spring 2023
///
///
/// memscan - find all legal memory adresses and count number of 'A's in memory
/// 
///
/// @file    MemoryRegions.cpp
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

#include "MemoryRegions.h"

////////////////////  Constructors  ////////////////////

MemoryRegion::MemoryRegion( string newFileLine ) noexcept {

    strcpy( MemoryRegion::fileLine, newFileLine );

}
