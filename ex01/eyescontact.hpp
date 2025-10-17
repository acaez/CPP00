#ifndef EYESCONTACT_HPP
#define EYESCONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        Contact();
        ~Contact();
        void setContact();
        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
        void displayContact();
};

class PhoneBook
{
    private:
        Contact contact[8];
        int     index;
        int     total;
        std::string format(std::string field);
    
    public:
        PhoneBook();
        ~PhoneBook();
        void addContact();
        void searchContact();
};

#endif
