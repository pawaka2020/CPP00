/*
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
*/
/*
My solution:
1 - combine all the program parameters into a single string. 
2 - remove excess space between words in that single string. 
3 - convert into large caps all the small caps inside that single string. 
4 - print that single string.
5 - If no parameters are given, simply print "* LOUD AND UNBEARABLE FEEDBACK NOISE *" instead.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

// // Combine program parameters into a single string
// std::string combine_parameters(int argc, char* argv[]) {
//     std::stringstream ss;

//     for (int i = 1; i < argc; i++) {
//         ss << argv[i];
//         if (i < argc - 1) {
//             ss << " ";
//         }
//     }

//     return ss.str();
// }

// // Remove excess space between words in a string
// std::string remove_excess_space(const std::string& str) {
//     std::string result;

//     // Iterate through each character in the input string
//     for (auto it = str.begin(); it != str.end(); it++) {
//         // Skip over multiple spaces
//         if (isspace(*it) && (it == str.begin() || isspace(*(it - 1)))) {
//             continue;
//         }
//         // Convert character to uppercase and append to result string
//         result += toupper(*it);
//     }

//     return result;
// }

// // Convert all lowercase letters to uppercase
// std::string lower_to_upper_case(const std::string &str) {
// 	// copies parameter 'str' to a new variable, 'result'
//     std::string result = str;

//     // use 'transform' operation from 'result'.begin() to 'result'.end().
// 	// then store 'transform' operation output to 'result'.begin()
// 	// 'toupper' function is applied in the 'transform' operation
//     std::transform(result.begin(), result.end(), result.begin(), ::toupper);

// 	// returns value of 'result' back to 'str'
//     return result;
// }

// // Print the megaphone message
// void print_megaphone(const std::string& message) {
//     if (message.empty()) {
//         std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
//     } else {
//         std::cout << message << std::endl;
//     }
// }

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
	//bool in_word = false;
    // Copy non-space characters to result string

  //   for (char c : str) {
  //       if (std::isspace(c)) 
		// {
  //           // If not already in a word, skip this space
  //           if (in_word == false) continue;
  //           in_word = false;
  //       } 
		// else 
  //       	in_word = true;
  //       result += c;
  //   }
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

    // Convert each lowercase letter to uppercase
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

//g++ megaphone.cpp -o megaphone
int main(int argc, char** argv) {
	//Do NOT use 0 to denote an emptry string. Use "" instead. It doesn't work like in C.
	std::string message = "";
	message = combine_params(argc, argv);
	message = remove_extra_spaces(message);
	message = all_upper_caps(message);
	print_on_megaphone(message);
	return (0);
	// std::string combined_params = combine_parameters(argc, argv);
    // std::string uppercase_message = lower_to_upper_case(combined_params);
    // std::string message = remove_excess_space(uppercase_message);
    // print_megaphone(message);
    // return 0;
}