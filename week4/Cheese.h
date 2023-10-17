/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4
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

#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H
#include <iostream>
namespace sdds {
	class Cheese {
		std::string m_name{ "NaC" };
		size_t m_weight{};
		double m_price{};
		std::string m_features{};
	public:
		Cheese(const std::string& str);
		Cheese slice(size_t weight);
		Cheese() :m_name("NaC"), m_weight(0), m_price(0), m_features("") {};
		//getter
		
		std::string removeSpaces(std::string& str);
		std::string getname()const;
		int getweight()const;
		double getprice()const;
		std::string getfeatures()const;
		std::ostream& read(std::ostream& os)const;

	};
	std::ostream& operator<<(std::ostream& os, const Cheese& cheese);
	
}
#endif // !SDDS_CHEESE_H
