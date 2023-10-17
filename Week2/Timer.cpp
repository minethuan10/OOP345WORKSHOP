/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 1
// Version 1.0
// Description
// tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Vu Duc Thuan Tran
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include "Timer.h"


using namespace std;
using namespace chrono;

namespace sdds
{
    void Timer::start() {
        startTime = high_resolution_clock::now();
    }


    long long int Timer::stop() {
        auto endTime = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(endTime - startTime);
        return duration.count();
    }

}