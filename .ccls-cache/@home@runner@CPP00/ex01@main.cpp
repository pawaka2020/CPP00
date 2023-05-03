/*
1 - code Makefile
2 - code main.cpp
3 - code Phonebook.hpp
4 - code Phonebook.cpp
5 - code Contact.hpp
6 - code Contaact.cpp

'Phonebook' class has array 'contacts' of size 8. [ ]
If user adds 9th contact to 'Phonebook', oldest element of the array is replaced by the 9th one. [ ]
No dynamic allocation for the contact array (ie 'new' or 'malloc') . [ ]
'Contact' class represents an element of 'Phonebook's 'contacts' array. [ ]
'Phonebook' is instantiated as an instance instead of being used directly. [ ].
Each element of 'Phonebook''s 'contacts' array is instantiated as an instance of 'Contact'. [ ]
Anything only used inside a class is private, anything can be used outside a class is public. [ ]
'Phonebook''s 'contacts' is empty on program start. [ ]
User is prompted to enter either 'ADD', 'SEARCH' or 'EXIT' as a command.

'ADD': Adds a new contact into 'contacts' array inside 'Phonebook'. [ ]
1. Prompt user to fill fields of the new contact, one at a time. [ ]
2. Fields: first name, last name, nickname, phone number, darkest secret. [ ]
3. None of the fields can be empty. [ ]

'SEARCH': Displays a specific contact. [ ]
1. First diplay all saved contacts in 4 columns: index, first name, last name, nickname . [ ]
2. Each column 10 chars wide and separated by '|'. [ ]
3. Text right aligned. [ ]
4. If text longer than column, 10th characer replaced by ., everything else truncated. [ ]
5. Prompt user again to enter an index. [ ]
6. Define relevant behavior for incorrect / out of range index. [ ]
7. Display contact info, one field per line for correct index . [ ]

'Exit'
1. All contacts lost after program closes. [ ]

Other inputs discarded, repeat asking user another prompt. [ ]
after correct command, repeat asking user another prompt. [ ]

*/

//#include "Phonebook.hpp"
#include "main.hpp"

int main() {
    //Phonebook phonebook;

    std::string command;

    while (true) {
        std::cout << "Please enter a command (ADD, SEARCH, or EXIT): ";
        std::cin >> command;

        if (command == "ADD") {
            //phonebook.addContact();
        } else if (command == "SEARCH") {
            //phonebook.searchContacts();
        } else if (command == "EXIT") {
			return 0;	
        } else {
            std::cout << "Invalid command, please try again." << std::endl;
        }
    }
    return 0;
}