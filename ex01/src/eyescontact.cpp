#include "PhoneBook.hpp"
#include <iomanip>
#include <cctype>

Contact::Contact()
{
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    darkestSecret = "";
}

Contact::~Contact()
{
}

void Contact::setContact()
{
    char    c;

    std::cout << "first name: ";
    if (!std::getline(std::cin, firstName))
        return;
    while (firstName.empty())
    {
        std::cout << "\033[1A\033[Kfirst name: ";
        if (!std::getline(std::cin, firstName))
            return;
    }
    std::cout << "last name: ";
    if (!std::getline(std::cin, lastName))
        return;
    while (lastName.empty())
    {
        std::cout << "\033[1A\033[Klast name: ";
        if (!std::getline(std::cin, lastName))
            return;
    }
    std::cout << "nickname: ";
    if (!std::getline(std::cin, nickname))
        return;
    while (nickname.empty())
    {
        std::cout << "\033[1A\033[Knickname: ";
        if (!std::getline(std::cin, nickname))
            return;
    }
    std::cout << "phone number: ";
    if (!std::getline(std::cin, phoneNumber))
        return;
    while (phoneNumber.empty())
    {
        std::cout << "\033[1A\033[Kphone number: ";
        if (!std::getline(std::cin, phoneNumber))
            return;
    }
    for (size_t i = 0; i < phoneNumber.length(); i++)
    {
        if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
        {
            std::cout << "Incorrect input" << std::endl;
            std::cout << "phone number: ";
            if (!std::getline(std::cin, phoneNumber))
                return;
        }
    }
    std::cout << "darkest secret: ";
    if (!std::getline(std::cin, darkestSecret))
        return;
    while (darkestSecret.empty())
    {
        std::cout << "\033[1A\033[Kdarkest secret: ";
        if (!std::getline(std::cin, darkestSecret))
            return;
    }

    std::cout << "add contact (press ENTER): ";
    while ((c = std::cin.get()) != '\n')
    {
        if (std::cin.eof())
            return;
    }
    std::cout << "Contact added" << std::endl;
}

std::string Contact::getFirstName()
{
    return (firstName);
}

std::string Contact::getLastName()
{
    return (lastName);
}

std::string Contact::getNickname()
{
    return (nickname);
}

std::string Contact::getPhoneNumber()
{
    return (phoneNumber);
}

std::string Contact::getDarkestSecret()
{
    return (darkestSecret);
}

void Contact::displayContact()
{
    std::cout << "first name: " << firstName << std::endl;
    std::cout << "last name: " << lastName << std::endl;
    std::cout << "nickname: " << nickname << std::endl;
    std::cout << "phone number: " << phoneNumber << std::endl;
    std::cout << "darkest secret: " << darkestSecret << std::endl;
}

PhoneBook::PhoneBook()
{
    index = 0;
    total = 0;
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::format(std::string field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void PhoneBook::addContact()
{
    contact[index].setContact();
    index = (index + 1) % 8;
    if (total < 8) total++;
} 

void PhoneBook::searchContact()
{ 
    int selectIndex;

    if (total == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    std::cout << "----------|----------|----------|----------" << std::endl;
    for (int i = 0; i < total; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << format(contact[i].getFirstName()) << "|";
        std::cout << std::setw(10) << format(contact[i].getLastName()) << "|";
        std::cout << std::setw(10) << format(contact[i].getNickname()) << std::endl;
    }
    std::string input;
    std::cout << "Enter index: ";
    if (!std::getline(std::cin, input))
        return;
    
    while (input.empty() || input.length() != 1 || input[0] < '0' || input[0] > '7')
    {
        std::cout << "\033[1A\033[KEnter index: ";
        if (!std::getline(std::cin, input))
            return;
    }    
    selectIndex = input[0] - '0';
    if (selectIndex >= 0 && selectIndex < total)
        contact[selectIndex].displayContact();
    else
        std::cout << "Invalid index." << std::endl;
}