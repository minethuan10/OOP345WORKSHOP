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

#define _CRT_SECURE_NO_WARNINGS
#include "RideRequest.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>

using namespace std;
double g_taxrate = 0.0;
double g_discount = 0.0;
namespace sdds {
    RideRequest::~RideRequest()
    {

        delete[] ride_detail;
        ride_detail = nullptr;
    }
    RideRequest& RideRequest::operator=(const RideRequest& src)
    {
        if (this != &src)
        {
            delete[] ride_detail;
            ride_detail = new char[strlen(src.ride_detail) + 1];
            strcpy(ride_detail, src.ride_detail);
            strcpy(customer_name, src.customer_name);
            price = src.price;
            discount = src.discount;
        }

        return *this;

    }

    RideRequest::RideRequest(const RideRequest& src)
    {
        delete[] ride_detail;
        ride_detail = nullptr;
        ride_detail = new char[strlen(src.ride_detail) + 1];
        strcpy(ride_detail, src.ride_detail);
        strcpy(customer_name, src.customer_name);
        price = src.price;
        discount = src.discount;
    }
    istream& RideRequest::read(istream& istr)
    {
        char input{};
        string data{};
        delete[] ride_detail;
        ride_detail = nullptr;
        if (istr)
        {
            istr.get(customer_name, 10, ',');
            istr.ignore(1000, ',');
            getline(istr, data, ',');
            ride_detail = new char[data.length() + 1];
            strcpy(ride_detail, data.c_str());
            istr >> price;
            istr.ignore(1000, ',');
            istr >> input;
            if (input == 'Y')
            {
                discount = true;
            }
            else
            {
                discount = false;
            }
            istr.ignore(1000, '\n');
        }
        return istr;
    }


    void RideRequest::display()
    {
        static int counter = 0;
        counter++;

        cout << left << setw(2) << counter << ". ";

        if (strlen(customer_name) > 0)
        {
            double priceTax = (price * g_taxrate) + price;
            double discounted = priceTax - g_discount;

            cout << left << setw(10) << customer_name << "|";
            cout << left << setw(25) << ride_detail<< "|";
            cout << left << fixed << setprecision(2) << setw(12) << priceTax << "|";

            if (discount == true)
            {
                cout << right << setw(13) << discounted;
            }

        }
        else
        {
            cout << "No Ride Request";
        }
        cout << endl;
    }
}