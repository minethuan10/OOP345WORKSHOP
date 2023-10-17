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
#include "Book.h"
#include <iostream>
using namespace std;
namespace sdds {
	Book& Book::operator=(const Book& other) 
	{
		if (this != &other) {
			m_title = other.m_title;
			m_numChapters = other.m_numChapters;
			m_numPages = other.m_numPages;
		}
		return *this;
	}

	bool Book::operator<(const Book& other) const
	{
		return double(m_numPages)/m_numChapters < double(other.m_numPages)/other.m_numChapters;
	}

	bool Book::operator>(const Book& other) const
	{
		return other < *this;
	}
	ostream& Book::print(ostream& os) const
	{
		if (m_title[0]!='\0'&&m_numPages>0&&m_numChapters>0) {
			os.setf(ios::right); os.setf(ios::fixed);
			if (m_numChapters > 9) {
				os.width(49);
			}
			else {
				os.width(50);
			}
			
			os << m_title << ',' << m_numChapters << ',' << m_numPages << " | (";

			os.precision(6);
			os << (double)m_numPages / m_numChapters << ")    ";

			os.unsetf(ios::right);
		}
		else
			cout << "| Invalid book data";

		return os;
	}
	std::ostream& operator<<(std::ostream& os, const Book& bk) {
		return bk.print(os);
	}
}