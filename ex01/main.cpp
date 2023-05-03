/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2023/03/03 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Phonebook.hpp"

int	main(){
	PhoneBook phoneBook;
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