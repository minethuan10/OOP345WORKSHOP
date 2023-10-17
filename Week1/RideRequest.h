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

#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H
#include <iostream>
using namespace std;
//two global variables
extern double g_taxrate;
extern double g_discount;
namespace sdds {
	class RideRequest {
	//a C-style null-terminated string of up to 10 characters including the null byte terminator representing the name of the customer.
	//a C - style null - terminated string of up to 25 characters including the null byte terminator representing the extra details about the ride(e.g., a description or special requirements the customer made).
	//the price of the ride as a floating - point number in double precision.
	//a Boolean flag indicating whether the ride receives a discount
	private:
		char customer_name[11]{};
		char* ride_detail{};
		double price{};
		bool discount{};
	public:
		RideRequest() {};
		istream& read(istream& str);
		void display();
		~RideRequest();
		RideRequest(const RideRequest& src);
		RideRequest& operator=(const RideRequest& src);
	};
}
#endif // !SDDS_RIDEREQUEST_H
