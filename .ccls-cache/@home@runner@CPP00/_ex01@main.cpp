#include "main.hpp"
#include "Phonebook.hpp"

int	main(){
	//declare the 'PhoneBook' class instance first.
	PhoneBook phoneBook;

	//then the 'input' string
    std::string input = "";
    while (1)
    {
        std::cout << "Please enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, input);
        if (input == "ADD")
			phoneBook.add();
        else if (input == "SEARCH")
            phoneBook.search();
        else if (input == "EXIT")
            exit(0);
        else
            std::cout << "Error: '" + input + "' is an invalid command. Please try again." << std::endl;
    }
}