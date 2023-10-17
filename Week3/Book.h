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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace sdds {
	class Book
	{
		std::string m_title{};
		unsigned m_numChapters{};
		unsigned m_numPages{};
	public:
		Book() :m_title(""), m_numChapters(0), m_numPages(0) {}
		Book(const std::string& title, unsigned nChapters, unsigned nPages) : m_title(title),m_numChapters(nChapters),m_numPages(nPages){}
		operator bool()const;

		Book& operator=(const Book& book);
		bool operator<(const Book& book) const;
		bool operator>(const Book& book) const;
		// TODO: In completing Part 1, add here the missing 
		// member prototypes that would be necessary for the 
		// Collection module code and tester module w3_p1.cpp 
		// to manage Book-type objects. 
		// 
		// In completing Part 2, add here the missing 
		// member prototypes that would be necessary for 
		// OrderedCollection module code and tester module 
		// w3_p2.cpp to manage Book-type object. 
		//
		// Write the implementations of these functions 
		// in Book.cpp file

		std::ostream& print(std::ostream& os) const;

	};
	std::ostream& operator<<(std::ostream& os, const Book& bk);

}
#endif // !SDDS_BOOK_H
