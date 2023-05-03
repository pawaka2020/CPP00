#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

#define LINE "---------------------------------------------"

class PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();
		void	addcontact();
		void	search();
	private:
		//* Add Utils
		std::string getstream(std::string prompt);
		std::string overwriteContact();

		//* Search utils
		void printthat(std::string stream);
		void printdetails(int index);
		//fields
		int lastcontact;
		int totalid;
		_contact *contact_list;
};

int	isnumarray(std::string str);

#endif
