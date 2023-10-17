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
#include "Cheese.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>  // Add this include for std::istringstream
using namespace std;
namespace sdds {

    // Constructor that parses a string and initializes attributes
   // Constructor that parses a string and initializes attributes
    Cheese::Cheese(const std::string& str) {
        // Split the input string into tokens using commas as delimiters
        size_t pos = 0;
        std::string token;
        std::string delimiter = ",";
        std::string input = str;

        // Extract and assign values to attributes
        m_name = input.substr(0, input.find(delimiter));
        pos = input.find(delimiter) + 1;
        input.erase(0, pos);

        m_weight = std::stoul(input.substr(0, input.find(delimiter)));
        pos = input.find(delimiter) + 1;
        input.erase(0, pos);

        m_price = std::stod(input.substr(0, input.find(delimiter)));
        pos = input.find(delimiter) + 1;
        input.erase(0, pos);

        // Extract features and store as a space-separated list
        m_features = "";
        while ((pos = input.find(delimiter)) != std::string::npos) {
            token = input.substr(0, pos);
            token = removeSpaces(token); // Remove spaces from the token
            m_features += token + " ";
            input.erase(0, pos + 1);
        }
        // Add the last feature (no comma after it)
        m_features += removeSpaces(input);

        // Remove leading and trailing spaces from the name and features
        m_name = removeSpaces(m_name);
        m_features = removeSpaces(m_features);
    }


   std::string Cheese::removeSpaces(std::string& str) {
    // Remove leading spaces
    size_t start = str.find_first_not_of(" ");
    if (start != std::string::npos) {
        str = str.substr(start);
    }

    // Remove trailing spaces
    size_t end = str.find_last_not_of(" ");
    if (end != std::string::npos) {
        str = str.substr(0, end + 1);
    }

    // Replace consecutive spaces with a single space
    size_t found = str.find("  ");
    while (found != std::string::npos) {
        str.replace(found, 2, " ");
        found = str.find("  ");
    }

    return str;
}


    std::string Cheese::getname() const {
        return m_name;
    }

    int Cheese::getweight() const {
        return m_weight;
    }

    double Cheese::getprice() const {
        return m_price;
    }

    std::string Cheese::getfeatures() const {
        // Remove leading and trailing spaces
        std::string formattedFeatures = m_features;
        size_t start = formattedFeatures.find_first_not_of(" ");
        if (start != std::string::npos) {
            formattedFeatures = formattedFeatures.substr(start);
        }
        size_t end = formattedFeatures.find_last_not_of(" ");
        if (end != std::string::npos) {
            formattedFeatures = formattedFeatures.substr(0, end + 1);
        }

        // Replace consecutive spaces with a single space
        size_t found = formattedFeatures.find("  ");
        while (found != std::string::npos) {
            formattedFeatures.replace(found, 2, " ");
            found = formattedFeatures.find("  ");
        }

        return formattedFeatures;
    }

    

    Cheese sdds::Cheese::slice(const size_t weight)
    {
        Cheese slice = *this;

        if (weight <= this->m_weight)
        {

            slice.m_weight = weight;
            this->m_weight -= weight;
            return slice;
        }
        else
        {
            return Cheese();
        }
    }


    	ostream& Cheese::read(ostream& os)const
	{
		os << "|" << left << setw(21) << getname();
		os << "|" << setw(5) << getweight();
		os << "|" << fixed << setprecision(2) << setw(5) << getprice() ;
		os << "|" << right << setw(33) << getfeatures();
		os << " |" << endl;
		return os;
	}

	ostream& operator<<(ostream& os, const Cheese& cheese)
	{
		cheese.read(os); 
		return os;
	}

}