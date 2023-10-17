#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
namespace sdds {
	class Movie {
		std::string m_title{};
		std::string m_description{};
		size_t year{};
	public:
		Movie() :m_title(""), m_description(""), year(0) {};
		const std::string& title() const{
			return m_title;
		}
		Movie(const std::string& strMovie);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
		std::string removespace(std::string& str);
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}
#endif // !SDDS_MOVIE_H
