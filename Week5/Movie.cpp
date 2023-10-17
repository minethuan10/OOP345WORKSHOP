#include "Movie.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
namespace sdds {
    Movie::Movie(const std::string& strMovie) {
        size_t i = 0;
        while (strMovie[i] != ',') {
            m_title += strMovie[i];
            i++;
        }
        m_title = removespace(m_title);
        i++;
        string temp_year;
        while (strMovie[i] != ',') {
            temp_year += strMovie[i];
            i++;
        }
        year = stoi(temp_year);
        i++;
        while (i != strMovie.length()) {
            m_description += strMovie[i];
            i++;
        }
        m_description = removespace(m_description);
    }
    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        os << setw(40) << right << movie.m_title << " | "
            << setw(4) << movie.year << " | "
            << movie.m_description << endl;
        return os;
    }
    std::string Movie::removespace(std::string& str) {
        str.erase(0, str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
        return str;
    }
}