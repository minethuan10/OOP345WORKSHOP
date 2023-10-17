#include "SpellChecker.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file.is_open()) {
			throw "Bad file name!";
		}

		for (size_t i = 0; i < 6; i++) {
			file >> m_badWords[i] >> m_goodWords[i];
		}

		file.close();
	};
	void SpellChecker::operator()(std::string& text) {
		for (size_t i = 0; i < 6; i++) {
			size_t found = text.find(m_badWords[i]);
			if (found != string::npos) {
				text.replace(found, m_badWords[i].length(), m_goodWords[i]);
				m_replacement[i]++;
			}
			found = text.find(m_badWords[i]);
			if (found != string::npos) {
				--i;
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		out<< "Spellchecker Statistics\n";
		for (int i = 0; i < 6; i++) {
			out << std::right << std::setw(15) << m_badWords[i] << ": " << m_replacement[i] << " replacements" << std::endl;
		}
	}
}