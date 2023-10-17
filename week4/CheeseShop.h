// CheeseShop.h
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
#pragma once
#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H
#include "Cheese.h"

namespace sdds
{
	class CheeseShop : public Cheese
	{
		const Cheese** shop{};
		std::string cheesey{};
		size_t count{};

	public:
		~CheeseShop();
		CheeseShop(const std::string& name);
		CheeseShop(CheeseShop&& src);
		CheeseShop(const CheeseShop& src);
		CheeseShop& operator=(CheeseShop&& src);
		CheeseShop& operator=(const CheeseShop& src);
		CheeseShop& addCheese(const Cheese&);
		friend std::ostream& operator<<(std::ostream& os, const CheeseShop& cheese);
	};
} // namespace sdds

#endif // SDDS_CHEESESHOP_H
