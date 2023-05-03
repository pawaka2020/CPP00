#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

#define LINE "---------------------------------------------"

class PhoneBook{

	// fields.
	_contact *contact_list;
	int lastcontact;
	int totalid;

	public:
		//constructor
		PhoneBook();
		//destructor
		~PhoneBook();
		void	addcontact();
		void	search();
	private:
		//* Add Utils: sub-functions for 'addContact'
		std::string getstream(std::string prompt);
		std::string overwriteContact();

		//* Search utils : sub-functions for 'search'
		void printthat(std::string stream);
		void printdetails(int index);
};

int	isnumarray(std::string str);

#endif
