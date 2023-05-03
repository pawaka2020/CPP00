//#include "main.hpp"

#include "Phonebook.hpp"

//constructor, initialize fields of 'Phonebook' instance.
PhoneBook::PhoneBook(){
	index = 0;
	index_max = 7;
	contacts = new Contact[index_max + 1];
}

//destructor, delete 'contacts' as 'Phonebook' instance is destroyed
PhoneBook::~PhoneBook(){
	delete[] contacts;
}

//sub-function for 'add'
//gets input from prompt, but returns error if nothing is entered and repeats prompt.
std::string PhoneBook::getInput(const std::string& prompt)
{
    std::string input = "";
	std::string error = "Error: field must not be empty. Please try again.";
    while (input == "")
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input == "")
            std::cout << error << std::endl;
    }
    return input;
}

//adds contacts into list. If already 8, index moves back to 0 and goes on from there.
void PhoneBook::add(){
	contacts[index].setFirstName(getInput("First name : "));
	contacts[index].setLastName(getInput("Last name : "));
	contacts[index].setNickname(getInput("Nickname : "));
	contacts[index].setDarkestSecret(getInput("Darkest secret : "));
	std::cout << "'" + contacts[index].getFirstName() + "' added as entry #" + std::to_string(index);
	std::cout << std::endl;
	index++;
	if (index > index_max) index = 0;
}

//sub-function for 'search'
void PhoneBook::printField(const std::string& input)
{
	int len = input.length();
	int space = 10;
	std::cout << "|";
	if (len <= 10)
	{
		while (space > len)
		{
			std::cout << " ";
			space--;
		}
		std::cout << input;
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			std::cout << input[i];
		}
		std::cout << ".";
	}
}

//sub-function for 'search'

void PhoneBook::printSearchRow(int i){
	printField(std::to_string(i));
	printField(contacts[i].getFirstName());
	printField(contacts[i].getLastName());
	printField(contacts[i].getNickname());
	std::cout << "|";
	std::cout << std::endl;
}

void PhoneBook::printRows()
{
	for (int i = 0; i <= index_max && contacts[i].getFirstName() != ""; i++)
	{
		printField(std::to_string(i));
		printField(contacts[i].getFirstName());
		printField(contacts[i].getLastName());
		printField(contacts[i].getNickname());
		std::cout << "|";
		std::cout << std::endl;	
	}
}

void PhoneBook::search(){
	std::cout<<"|     Index|First name| Last name|  Nickname|" <<std::endl;
	printRows();
}
