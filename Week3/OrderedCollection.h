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
#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H
#include "Collection.h"
namespace sdds {
	template <typename T>
	class OrderedCollection : public Collection<T, 72> {
	public:
		using Collection<T, 72>::size;
		using Collection<T, 72>::operator+=;
		using Collection<T, 72>::operator[];


		bool operator+=(const T& newItem) {
			bool added = Collection<T, 72>::operator+=(newItem);
			for (unsigned i = 0; i < Collection<T, 72>::size() - 1; i++) {
				for (unsigned j = 0; j < Collection<T, 72>::size() - i - 1; j++) {
					if (Collection<T, 72>::operator[](j) > Collection<T, 72>::operator[](j + 1)) {
						auto temp = Collection<T, 72>::operator[](j);
						Collection<T, 72>::operator[](j) = Collection<T, 72>::operator[](j + 1);
						Collection<T, 72>::operator[](j + 1) = temp;
					}
				}
			}
			return added;
		}
	};
}
#endif // !SDDS_ORDEREDCOLLECTION_H