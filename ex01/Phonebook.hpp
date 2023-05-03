/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2023/03/03 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		void printRows(int *i);
		int	getNumberInput(int i);
		void printContactInfo(int n);
};

#endif