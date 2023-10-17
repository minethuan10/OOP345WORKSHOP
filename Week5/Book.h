#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
namespace sdds {
	class Book {
		std::string author{};
		std::string book_title{};
		std::string country_publication{};
		size_t year_publication=0.0;
		double book_price=0.0;
		std::string description{};
	public:
		Book() :author(""),book_title(""),country_publication(""),year_publication(0),book_price(0),description("") {};
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		
		double& price();
		Book(const std::string& strBook);
		std::string removeSpaces(std::string& str);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(description);
		}
		std::ostream& read(std::ostream& os)const;
		friend std::ostream& operator <<(std::ostream&, const Book& book);
	};
	
}
#endif // !SDDS_BOOK_H
