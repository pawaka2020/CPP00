/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2023/03/03 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	contacts[index].setPhone(getInput("Phone : "));
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

//sub-function for 'search'
void PhoneBook::printRows(int *i)
{
	while (*i <= index_max && contacts[*i].getFirstName() != "")
	{
		printField(std::to_string(*i));
		printField(contacts[*i].getFirstName());
		printField(contacts[*i].getLastName());
		printField(contacts[*i].getNickname());
		std::cout << "|";
		std::cout << std::endl;
		(*i)++;
	}
	(*i)--;
}

//sub-function for 'search'
int	PhoneBook::getNumberInput(int i)
{
	int n = 0;
	std::string userInput;
	std::stringstream ss;
	while (1)
	{
		std::cout << "Please enter an index number (0 - " + std::to_string(i) + ") : ";
		std::getline(std::cin, userInput);
		std::stringstream ss(userInput);
		if (ss >> n && n >= 0 && n <= i && ss.eof()){
			break ; 
		}
		else{
			std::cout << "Error: Invalid input." << std::endl;
		}
	}
	return n;
}

//sub-function for 'search'
void PhoneBook::printContactInfo(int n){
	std::cout <<"First name : " + contacts[n].getFirstName() << std::endl;
	std::cout <<"Last name : " + contacts[n].getLastName() << std::endl;
	std::cout <<"Nickname : " + contacts[n].getNickname() << std::endl;
	std::cout <<"Phone : " + contacts[n].getPhone() << std::endl;
	std::cout <<"Darkest secret : " + contacts[n].getDarkestSecret() << std::endl;
}

//searches for contacts added previously through ADD command.
//then if entries found also prompt users to enter index to show more details of a particular
//contact.
void PhoneBook::search(){
	int i = 0;
	std::cout<< "|     Index|First name| Last name|  Nickname|" <<std::endl;
	printRows(&i);
	if (i == -1)
		std::cout<< "No entries found" <<std::endl;
	else{
		int n = getNumberInput(i);
		printContactInfo(n);
	}
}