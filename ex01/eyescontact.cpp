#include <iostream>
#include <string>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        Contact()
        {
            firstName = "";
            lastName = "";
            nickname = "";
            phoneNumber = "";
            darkestSecret = "";
        }
    
    void setContact()           
    {
        std::cout << "first name: ";
        std::getline(std::cin, firstName);
        while (firstName.empty())
        {
            std::cout << "\033[1A\033[Kfirst name: ";
            std::getline(std::cin, firstName);
        }
  
        std::cout << "last name: ";
        std::getline(std::cin, lastName);
        while (lastName.empty())
        {
            std::cout << "\033[1A\033[Klast name: ";
            std::getline(std::cin, lastName);
        }
        
        std::cout << "nickname: ";
        std::getline(std::cin, nickname);
        while (nickname.empty())
        {
            std::cout << "\033[1A\033[Knickname: ";
            std::getline(std::cin, nickname);
        }
        
        std::cout << "phone number: ";
        std::getline(std::cin, phoneNumber);
        while (phoneNumber.empty())
        {
            std::cout << "\033[1A\033[Kphone number: ";
            std::getline(std::cin, phoneNumber);
        }

        std::cout << "darkest secret: ";
        std::getline(std::cin, darkestSecret);
        while (darkestSecret.empty())
        {
            std::cout << "\033[1A\033[Kdarkest secret: ";
            std::getline(std::cin, darkestSecret);
        }

        std::cout << "Contact added" << std::endl;
    }
    
    void getContact()
    {
        std::cout << "First name: " << firstName << std::endl;
        std::cout << "Last name: " << lastName << std::endl;
        std::cout << "Nickname: " << nickname << std::endl;
        std::cout << "Phone number: " << phoneNumber << std::endl;
        std::cout << "Darkest secret: " << darkestSecret << std::endl;
    }
    
    // Méthodes pour accéder aux données privées
    std::string getFirstName() { return firstName; }
    std::string getLastName() { return lastName; }
    std::string getNickname() { return nickname; }
};

class PhoneBook 
{
    private:
        Contact contact[8];
        int     index;
        int     total;
    
    public:
        PhoneBook()
        {
            index = 0;
            total = 0;
        }
    
    std::string formatColumn(std::string text)
    {
        if (text.length() > 10)
        {
            text = text.substr(0, 9) + ".";
        }
        while (text.length() < 10)
        {
            text = " " + text;  // Alignement à droite
        }
        return text;
    }

    void searchContact() 
    {
        if (total == 0)
        {
            std::cout << "No contacts saved." << std::endl;
            return;
        }
        std::cout << "|     index|first name| last name|  nickname|" << std::endl;
        
        for (int i = 0; i < total; i++)
        {
            std::cout << "|         " << i << "|";
            std::cout << formatColumn(contact[i].getFirstName()) << "|";
            std::cout << formatColumn(contact[i].getLastName()) << "|";
            std::cout << formatColumn(contact[i].getNickname()) << "|" <<std::endl;
        }
        std::cin >> index;

        if (index >= 0 && index < total)
            contact[index].getContact();
        else
            std::cout << "Invalid index!" << std::endl;
    }
    
    void addContact()
    {
        contact[index].setContact();
        index = (index + 1) % 8;
        if (total < 8)
            total++;
    }
};

int main() 
{
    PhoneBook phonebook;
    
    phonebook.addContact();
    phonebook.searchContact();
    
    return 0;
}