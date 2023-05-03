/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2023/03/03 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "main.hpp"

//constructor
Contact::Contact(){
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phone = "";
	this->darkestSecret = "";
}

//destructor. I will only implement if needed.
Contact::~Contact(){}

//setters
void Contact::setFirstName(const std::string& firstName){
	this->firstName = firstName;
}
void Contact::setLastName(const std::string& lastName){
	this->lastName = lastName;
}
void Contact::setNickname(const std::string& nickname){
	this->nickname = nickname;
}
void Contact::setDarkestSecret(const std::string& darkestSecret){
	this->darkestSecret = darkestSecret;
}

//getters
std::string Contact::getFirstName() const{
	return this->firstName;
}
std::string Contact::getLastName() const{
	return this->lastName;
}
std::string Contact::getNickname() const{
	return this->nickname;
}
std::string Contact::getDarkestSecret() const{
	return this->darkestSecret;
}