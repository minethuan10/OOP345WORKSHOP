#include <iostream>
#include "Book.h"
#include <iomanip>
#include <sstream>
using namespace std;
namespace sdds {
	const string& Book::title()const {
		return book_title;
	}
	const string& Book::country()const {
		return country_publication;
	}
	const size_t& Book::year()const {
		return year_publication;
	}
	double& Book::price() {
		return book_price;
	}
    Book::Book(const std::string& strBook) {
		unsigned startPos = 0;
		unsigned endPos = strBook.find(',');

		if (endPos != string::npos) {
			author = strBook.substr(startPos, endPos - startPos);
			author.erase(0, author.find_first_not_of(" \t"));
			author.erase(author.find_last_not_of(" \t") + 1);

			startPos = endPos + 1;
			endPos = strBook.find(',', startPos);

			if (endPos != string::npos) {
				book_title = strBook.substr(startPos, endPos - startPos);
				book_title.erase(0, book_title.find_first_not_of(" \t"));
				book_title.erase(book_title.find_last_not_of(" \t") + 1);

				startPos = endPos + 1;
				endPos = strBook.find(',', startPos);

				if (endPos != string::npos) {
					country_publication = strBook.substr(startPos, endPos - startPos);
					country_publication.erase(0, country_publication.find_first_not_of(" \t"));
					country_publication.erase(country_publication.find_last_not_of(" \t") + 1);

					startPos = endPos + 1;
					endPos = strBook.find(',', startPos);

					if (endPos != string::npos) {
						string price = strBook.substr(startPos, endPos - startPos);
						price.erase(0, price.find_first_not_of(" \t"));
						price.erase(price.find_last_not_of(" \t") + 1);
						book_price = stod(price);

						startPos = endPos + 1;
						endPos = strBook.find(',', startPos);

						if (endPos != string::npos) {
							string year = strBook.substr(startPos, endPos - startPos);
							year.erase(0, year.find_first_not_of(" \t"));
							year.erase(year.find_last_not_of(" \t") + 1);
							year_publication = stoul(year);

							startPos = endPos + 1;
							description = strBook.substr(startPos);
							description.erase(0, description.find_first_not_of(" \t"));
							description.erase(description.find_last_not_of(" \t") + 1);
						}
					}
				}
			}
		}
    }

    ostream& Book::read(ostream& os)const {
        os << right << setw(20) << author;
        os << " | " << setw(22) << title();
        os << " | " << setw(5) << country();
        os << " | " << setw(4) << year();
        os << " | " << fixed << setprecision(2) << setw(6) << book_price;
        os << " | " << left << description<<endl;
        return os;
    }
    std::ostream& operator <<(std::ostream&os, const Book& book) {
        book.read(os);
        return os;
    }
}