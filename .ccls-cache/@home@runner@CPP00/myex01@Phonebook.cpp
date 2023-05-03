#include "Phonebook.hpp"
#include "main.hpp"

/*
Constructor. 'count' gets initialized to 0 when a new 'Phonebook' instance is created.
*/
Phonebook::Phonebook() {
    count = 0;
}

/*
Prompts user to fill a 'field' described by 'promptText'.
'userInput' cannot be empty. User will simply be shown error message and get prompted again.
The non-empty input is then passed to 'field'.
*/
void Phonebook::enterField(std::string& field, std::string promptText)
{
	std::string errorMessage = "Error: field must not remain empty.\n";
	std::string userInput = "";
	while (userInput.empty()){
		std::cout << promptText;
		std::cin >> userInput;
		if (userInput.empty()) std::cout << errorMessage << std::endl;
	}
	field = userInput;
}

/*
Adds 'contact' to 'contacts'.
If 'contacts' already has 8 elements, 'contact' is added to 0th element of 'contacts' instead.
*/
void Phonebook::add(Contact contact, Contact contacts[], int& count)
{
    if (count < 8) contacts[count++] = contact;
    else contacts[0] = contact;
}

/*
Adds a new 'contact' into 'contacts' array inside 'Phonebook'.
*/
void Phonebook::addContact() {
	Contact contact;
	enterField(contact.firstName, "Enter first name: ");
	enterField(contact.lastName, "Enter last name: ");
	enterField(contact.nickname, "Enter nickname: ");
	enterField(contact.phoneNumber, "Enter phone number: ");
	enterField(contact.darkestSecret, "Enter darkest secret: ");
	add(contact, contacts, count);
}


std::string Phonebook::truncate(std::string s)
{
	std::string result = "";
	if (s.length() > 10) result = s.substr(0, 9) + '.';
	return result;
}

void Phonebook::displayContacts(Contact contacts[], int count)
{
	//Print header.
	std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	//Print columns.
	for (int i = 0; i < count; i++) {
    	std::cout << std::right << std::setw(10) << truncate(contacts[i].firstName) << "|"
              	<< std::right << std::setw(10) << truncate(contacts[i].lastName) << "|"
              	<< std::right << std::setw(10) << truncate(contacts[i].nickname) << "|"
              	<< std::right << std::setw(10) << truncate(contacts[i].phoneNumber) << "|"
              	<< std::endl;
	}
}

void Phonebook::promptEnterIndex(Contact contacts[], int count)
{
	//Prompt user to enter index.
	int index;
    std::cout << "Enter the index of the contact you want to display: ";
    std::cin >> index;
    //Check if the index is valid.
    if (index < 0 || index >= count) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
	//Display info of selected contact.
	Contact selectedContact = contacts[index];
	std::cout << "First name: " << selectedContact.firstName << std::endl;
    std::cout << "Last name: " << selectedContact.lastName << std::endl;
    std::cout << "Nickname: " << selectedContact.nickname << std::endl;
    std::cout << "Phone number: " << selectedContact.phoneNumber << std::endl;
    std::cout << "Darkest secret: " << selectedContact.darkestSecret << std::endl;
}

/*
'SEARCH': Displays a specific element from 'contacts'. [ ]
1. First diplay all saved elements in 'contacts' in 4 columns: index, first name, last name, nickname . [ ]
2. Each column is 10 chars wide and separated by '|'. [ ]
3. Text right aligned. [ ]
4. If text longer than column, 10th characer replaced by '.', everything else truncated. [ ]
5. Prompt user again to enter an index. [ ]
6. Define relevant behavior for incorrect / out of range index. [ ]
7. Display contact info, one field per line for correct index . [ ]
*/
void Phonebook::searchContacts() {
	displayContacts(contacts, count);
	promptEnterIndex(contacts, count);
}