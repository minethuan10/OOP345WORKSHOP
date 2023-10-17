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

#pragma once
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <iostream>
#include <string>
#include <chrono>



namespace sdds
{
	class Timer
	{
		std::chrono::high_resolution_clock::time_point startTime;
	public:
		void start();
		long long int stop();
	};

}
#endif 