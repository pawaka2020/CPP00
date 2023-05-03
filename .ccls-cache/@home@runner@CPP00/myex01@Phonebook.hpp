#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "main.hpp"

class Phonebook {

public:
    Phonebook();
    void addContact();
    void searchContacts();

private:
    Contact contacts[8];
    int count;
//sub-functions for 'addContact'
	void enterField(std::string& field, std::string promptText);
	void add(Contact contact, Contact contacts[], int& count);
//sub-functions for 'searchContacts'
	std::string truncate(std::string s);
	void displayContacts(Contact contacts[], int count);
	void promptEnterIndex(Contact contacts[], int count);
};

#endif // PHONEBOOK_HPP