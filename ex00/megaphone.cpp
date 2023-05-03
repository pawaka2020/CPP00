/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2023/03/03 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

// Combine all the program parameters into a single string
std::string combine_params(int argc, char** argv) {
    std::string result = "";

    //we start wth i = 1 because argv[0] is just program name
    for (int i = 1; i < argc; i++) {
        result += argv[i];
		//when i has not yet reached the last param, add " "
        if (i < argc-1)  result += " ";
	}
    return result;
}

// Remove excess space between words in a string
// '&' denotes passing reference without copying the entire string
//into the function parameter, impproving performance.
//'const' prevents 'str' from changing. Removing it would make 'str'
//work like a 'pointer' in C.
std::string remove_extra_spaces(const std::string &str) {
    std::string result = "";
	bool first_space = true;

	for (char c : str){
		if (!std::isspace(c))
		{
			first_space = true;
		}
		else
		{
			if (first_space == false) continue;
			first_space = false;
		}
		result += c;
	}

    return result;
}

// Convert all characters in a string to uppercase
std::string all_upper_caps(const std::string &str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Print a string in "megaphone" style
void print_on_megaphone(const std::string &str) {
	std::string defaultnoise = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    if (str.empty()) 
		std::cout << defaultnoise << std::endl;
    else 
		std::cout << str << std::endl;
	return;
}

int main(int argc, char** argv) {
	std::string message = "";
	message = combine_params(argc, argv);
	message = remove_extra_spaces(message);
	message = all_upper_caps(message);
	print_on_megaphone(message);
	return (0);
}