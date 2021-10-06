#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>

class PhoneBook
{
public:
    PhoneBook() = default; /* since C++11 */
    ~PhoneBook() = default; /* since C++11 */
public:
    bool operator>(const PhoneBook& obj);
    bool operator<(const PhoneBook& obj);
    bool operator==(const PhoneBook& obj);
    void isValid();
    bool is_Valid();

    friend std::ostream& operator<<(std::ostream& os,const PhoneBook& book )
    {
        os << book.name << "  "<< book.lastName << "  " 
           << book.separator << " " << book.phoneNumber <<'\n' ;
        return os ;
    }
	friend std::fstream& operator>>(std::fstream& is, PhoneBook& book)
    {
        is >> book.name;
        is >> book.lastName;
        if((book.lastName < "a" || book.lastName > "z" || book.lastName < "A" || book.lastName > "Z") && book.lastName.size() < 2 )
        {
            book.separator = book.lastName[0];
            book.lastName = "";
            is >> book.phoneNumber;
        }
        else
        {
            is >> book.separator;
            is >> book.phoneNumber;
        }
    return is ;
    }
    private:
    std::string name;
    std::string lastName;
    std::string phoneNumber;
    char separator;
};
#endif /* PHONEBOOK_H */
