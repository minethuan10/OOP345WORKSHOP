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

#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H
#include <iostream>
#include <iostream>
#include "Cheese.h"
namespace sdds {
    class CheeseParty {
        const Cheese** cheese1 = nullptr;
        size_t m_size = 0;
    public:
        CheeseParty() :cheese1(nullptr), m_size(0) {};
        ~CheeseParty();
        CheeseParty& addCheese(const Cheese& cheese);
        CheeseParty& removeCheese();
        CheeseParty(const CheeseParty& source);
        CheeseParty(CheeseParty&& source);
        CheeseParty& operator=(const CheeseParty& source);
        CheeseParty& operator=(CheeseParty&& source);
        friend std::ostream& operator<<(std::ostream& os, CheeseParty& cheeseParty);
    };
}
#endif