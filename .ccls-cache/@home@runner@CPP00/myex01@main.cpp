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
