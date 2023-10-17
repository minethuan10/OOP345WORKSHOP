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

#include <iostream>
#include <iomanip>
#include "CheeseParty.h"
using namespace std;
namespace sdds {
   
    CheeseParty::~CheeseParty() {
        delete[] cheese1;
    }
    CheeseParty& CheeseParty::addCheese(const Cheese& cheese) {
        bool flag = true;
        for (size_t i = 0; i < m_size; i++) {
            if (cheese1[i] == &cheese) {
                flag = false;
            }
        }
        if (flag) {
            const Cheese** tmpCheeseArray = new const Cheese * [m_size + 1];
            for (size_t i = 0; i < m_size; i++) {
                tmpCheeseArray[i] = cheese1[i];
            }
            tmpCheeseArray[m_size++] = &cheese;
            delete[] cheese1;
            cheese1 = tmpCheeseArray;
        }
        return *this;
    }


    CheeseParty& CheeseParty::removeCheese() {
        for (size_t i = 0; i < m_size; i++) {
            if (cheese1[i]->getweight() == 0.0) {
                cheese1[i] = nullptr;
            }
        }
        return *this;
    }
    CheeseParty::CheeseParty(const CheeseParty& source) {
        *this = source;
    }
    CheeseParty::CheeseParty(CheeseParty&& source) {
        *this = std::move(source);
    }
    CheeseParty& CheeseParty::operator=(const CheeseParty& source) {
        if (this != &source) {
            m_size = source.m_size;
            delete[] cheese1;
            cheese1 = new const Cheese * [m_size];
            for (size_t i = 0; i < m_size; i++) {
                cheese1[i] = source.cheese1[i];
            }
        }
        return *this;
    }
    CheeseParty& CheeseParty::operator=(CheeseParty&& source) {
        if (this != &source) {
            delete[] cheese1;
            m_size = source.m_size;
            cheese1 = source.cheese1;
            source.cheese1 = nullptr;
        }
        return *this;
    }
    std::ostream& operator<<(std::ostream& os, CheeseParty& cheeseParty) {
        os << setfill('-') << setw(26) << '-' << endl;
        os << "Cheese Party" << endl;
        os << setfill('-') << setw(26) << '-' << endl;
        os << setfill(' ');
        if (cheeseParty.cheese1) {
            for (size_t i = 0; i < cheeseParty.m_size; i++) {
                if (cheeseParty.cheese1[i]) {
                    os << *cheeseParty.cheese1[i];
                }
            }
        }
        else {
            os << "This party is just getting started!" << endl;
        }
        os << setfill('-') << setw(26) << '-' << endl;
        os << setfill(' ');
        return os;
    }
}