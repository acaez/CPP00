#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

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
