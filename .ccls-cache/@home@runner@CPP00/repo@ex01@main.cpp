/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:41:27 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/19 22:41:28 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

//displays the interface.
//use mine instead.
void	printmenu()
{
	std::cout << "Plase enter from above;" << std::endl;
	std::cout << "1 : ADD contact" << std::endl;
	std::cout << "2 : Search " << std::endl;
	std::cout << "3 : Exit the program" << std::endl;
	std::cout << "Enter The Choise: ";
}

//determines if string is an alphabet or not. 
int	isnumarray(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
	}
	return (1);
}

//I think we should make an even better input system, but moving on.
int	main()
{
	//declare the 'PhoneBook' class instance first.
	PhoneBook phonelist;
	
	//then the 'input' string
	std::string inp;

	//then start the command loop
	while (1)
	{
		//show menu
		printmenu();
		
		std::cin >> inp;
		std::cout << LINE << std::endl;
		
		if (!isnumarray(inp))
		{
			std::cout << "Please enter a menu(numeric)" << std::endl << LINE << std::endl;
			continue;
		}

		//remember add a break each time a command is executed to allow the loop to resume afterwards. 
		//it breaks the switch but not the loop itself.
		switch (stoi(inp))
		{
		case 1:
			phonelist.addcontact();
			break;
		case 2:
			phonelist.search();
			break;
		case 3:
			std::cout << "bye bye" << std::endl << LINE << std::endl;
			return (0);
		default:
			std::cout << "Wrong input!! Plase enter the menu numbers" << std::endl;
			break;
		}
	}
}