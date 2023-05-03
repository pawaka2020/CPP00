#ifndef CONTACT_HPP
# define CONTACT_HPP
#include "main.hpp"
class Contact{
	public:
		//constructor and destructor
		Contact();
		~Contact();
		//setters, 'const' ensures parameters are not modified 
		//& allows using memory address of strings instead of copying, improving performance.
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& lastName);
		void setNickname(const std::string& nickname);
		void setPhone(const std::string& phone);
		void setDarkestSecret(const std::string& darkestSecret);
		//getters, 'const' ensures returning field values without modifying any fields beforehand.
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhone() const;
		std::string getDarkestSecret() const;
	private:
		//fields
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phone;
		std::string darkestSecret;
};
#endif
