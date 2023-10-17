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
#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H
#include <iostream>
#include <string>
#include <cstring>


namespace sdds
{
	struct Airport
	{
		std::string airport_code;
		std::string airport_name;
		std::string airport_city;
		std::string airport_state;
		std::string airport_country;
		double airport_latitude = 0.0;
		double airport_longtitude = 0.0;
		friend std::ostream& operator << (std::ostream& os, const Airport& air);
		bool isEmpty() const;
	};

	class AirportLog
	{
		Airport* count{};
		size_t numberofairport = 0;

	public:

		AirportLog() : count(nullptr), numberofairport(0) {}
		~AirportLog();
		AirportLog(const std::string& file);
		void addAirport(const Airport& ac);
		AirportLog findAirport(const char* names, const char* countrys);
		Airport& operator[](size_t a);
		operator size_t();
		AirportLog(AirportLog&& src);
		AirportLog(const AirportLog& src);
		AirportLog& operator=(AirportLog&& src);
		AirportLog& operator=(const AirportLog& src);

	};
}

#endif 