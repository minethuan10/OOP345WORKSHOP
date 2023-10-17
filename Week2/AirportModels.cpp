#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "AirportModels.h"

using namespace std;

namespace sdds
{

	bool Airport::isEmpty() const
	{
		if (airport_code.empty() && airport_name.empty() && airport_city.empty() && airport_state.empty() && airport_country.empty() && airport_latitude == 0.0 && airport_longtitude == 0.0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	ostream& operator << (ostream& os, const Airport& air)
	{
		if (air.isEmpty())
		{
			os << "Empty Airport";
		}
		else
		{
			os << right << setw(23) << setfill('.') << "Airport Code : " << left << setw(30) << setfill('.') << air.airport_code << endl;
			os << right << setw(23) << setfill('.') << "Airport Name : " << left << setw(30) << setfill('.') << air.airport_name << endl;
			os << right << setw(23) << setfill('.') << "City : " << left << setw(30) << setfill('.') << air.airport_city<< endl;
			os << right << setw(23) << setfill('.') << "State : "<< left << setw(30) << setfill('.') << air.airport_state << endl;
			os << right << setw(23) << setfill('.') << "Country : "<< left << setw(30) << setfill('.') << air.airport_country << endl;
			os << right << setw(23) << setfill('.') << "Latitude : " << left << setw(30) << setfill('.') << air.airport_latitude<< endl;
			os << right << setw(23) << setfill('.') << "Longitude : " << left << setw(30) << setfill('.') << air.airport_longtitude<< endl;
		}
		return os;
	}


	AirportLog::~AirportLog()
	{
		delete[] count;
	}

	AirportLog::AirportLog(const string& file)
	{
		ifstream File(file);
		if (!File)
		{
			cout << "Unable to open file" << file << endl;
		}

		string line;
		getline(File, line);

		size_t nmairports = 0;
		while (getline(File, line)) {
			++nmairports;
		}

		count = new Airport[nmairports];

		File.clear();
		File.seekg(0);


		Airport airport;

		getline(File, line);

		for (size_t i = 0; i < nmairports; ++i) {
			getline(File, line);
			stringstream ss(line);
			string token;
			getline(ss, token, ',');
			airport.airport_code = token;
			getline(ss, token, ',');
			airport.airport_name = token;
			getline(ss, token, ',');
			airport.airport_city = token;
			getline(ss, token, ',');
			airport.airport_state = token;
			getline(ss, token, ',');
			airport.airport_country = token;
			getline(ss, token, ',');
			airport.airport_latitude = stod(token);
			getline(ss, token, ',');
			airport.airport_longtitude = stod(token);
			count[i] = airport;
		}


		numberofairport = nmairports;

	}

	void AirportLog::addAirport(const Airport& ac)
	{
		Airport* newLogs = new Airport[numberofairport+ 1];

		for (size_t i = 0; i < numberofairport; ++i) {
			newLogs[i] = count[i];
		}

		newLogs[numberofairport] = ac;

		delete[] count;
		count = newLogs;

		++numberofairport;
	}

	AirportLog AirportLog::findAirport(const char* names, const char* countrys)
	{
		AirportLog airports;

		for (size_t i = 0; i < numberofairport; ++i)
		{
			if (strcmp(count[i].airport_state.c_str(), names) == 0 && strcmp(count[i].airport_country.c_str(), countrys) == 0)
			{
				airports.addAirport(count[i]);
			}
		}
		return airports;
	}

	Airport& AirportLog::operator[](size_t a)
	{
		if (a < numberofairport) {
			return count[a];
		}
		else {

			static Airport emptyAirport;
			return emptyAirport;
		}
	}
	AirportLog::operator size_t()
	{
		return numberofairport;
	}

	AirportLog::AirportLog(const AirportLog& src)
	{
		operator=(src);
	}

	AirportLog::AirportLog(AirportLog&& src)
	{
		operator=(move(src));
	}

	AirportLog& AirportLog::operator=(AirportLog&& src)
	{
		if (this != &src)
		{
			if (count)
			{
				delete[] count;
				count = nullptr;
			}

			count = src.count;
			src.count = nullptr;
			numberofairport = src.numberofairport;
			src.numberofairport = 0;
		}
		return *this;
	}

	AirportLog& AirportLog::operator=(const AirportLog& src) {
		if (this != &src) {
			Airport* newLogs = new Airport[src.numberofairport];
			for (size_t i = 0; i < src.numberofairport; i++) {
				newLogs[i] = src.count[i];
			}

			delete[] count;
			count = newLogs;
			numberofairport = src.numberofairport;
		}
		return *this;
	}

}