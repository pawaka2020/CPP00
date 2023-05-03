#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"
#include "main.hpp"

class PhoneBook{
	public:
		//constructor and destructor
		PhoneBook();
		~PhoneBook();
		//functions
		void add();
		void search();
	private:
		//fields
		int index;
		int	index_max;
		Contact *contacts;
		//sub-functions for 'add'
		std::string getInput(const std::string& prompt);
		//sub-functions for 'search'
		void printField(const std::string& stream);
		void printSearchRow(int i);
		void printRows();
};

#endif