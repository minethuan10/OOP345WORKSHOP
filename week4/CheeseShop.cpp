// CheeseShop.cpp
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
#include "CheeseShop.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
using namespace std;

namespace sdds {

	CheeseShop::CheeseShop(const std::string& name) {
		cheesey = name;
		shop = nullptr;
		count = 0;
	}
	CheeseShop& CheeseShop::addCheese(const Cheese& cheese) {
		const Cheese** newShop = new const Cheese * [count + 1];

		for (size_t i = 0; i < count; i++) {
			newShop[i] = shop[i];
		}

		newShop[count] = new const Cheese(cheese);

		if (shop) {
			delete[] shop;
		}

		shop = newShop;
		count++;

		return *this;
	}

	ostream& operator<<(ostream& os, const CheeseShop& cheese)
	{
		size_t i = 0;
		if (cheese.count == 0)
		{
			os << "--------------------------" << endl;
			os << cheese.cheesey << endl;
			os << "--------------------------" << endl;
			os << "This shop is out of cheese!" << endl;
			os << "--------------------------" << endl;

		}
		else
		{
			os << "--------------------------" << endl;
			os << cheese.cheesey << endl;
			os << "--------------------------" << endl;
			for (i = 0; i < cheese.count; i++)
			{
				cheese.shop[i]->read(os);
			}
			os << "--------------------------" << endl;

		}
		return os;
	}

	CheeseShop& CheeseShop::operator=(const CheeseShop& src)
	{
		if (this != &src)
		{
			const Cheese** newshop = new const Cheese * [src.count];


			for (size_t i = 0; i < src.count; i++)
			{
				newshop[i] = src.shop[i];
			}
			delete[] shop;
			shop = newshop;
			cheesey = src.cheesey;
			count = src.count;
		}

		return *this;
	}

	CheeseShop& CheeseShop::operator=(CheeseShop&& src)
	{
		if (this != &src)
		{
			delete[] shop;
			shop = nullptr;

			shop = src.shop;
			src.shop = nullptr;
			count = src.count;
			src.count = 0;
			cheesey = move(src.cheesey);
		}
		return *this;
	}

	CheeseShop::CheeseShop(CheeseShop&& src)
	{
		operator=(move(src));
	}

	CheeseShop::CheeseShop(const CheeseShop& src)
	{
		operator=(src);
	}

	CheeseShop::~CheeseShop() {

		for (size_t i = 0; i < count; i++)
		{
			delete shop[i];
		}
		delete[] shop;
	};

} // namespace sdds
