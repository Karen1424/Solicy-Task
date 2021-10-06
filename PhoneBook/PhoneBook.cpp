#include "PhoneBook.h"

/*operator (>,<,==) overloading*/
bool PhoneBook::operator>(const PhoneBook& obj)
{
    if(this->name > obj.name){return true;}
    else if(this->name == obj.name && this->lastName > obj.lastName){return true;}
    else if(this->name == obj.name && this->lastName == obj.lastName && this->phoneNumber > obj.phoneNumber){return true;}
    return false;
}
bool PhoneBook::operator<(const PhoneBook& obj)
{
    if(this->name < obj.name){return true;}
    else if(this->name == obj.name && this->lastName < obj.lastName){return true ;}
    else if(this->name == obj.name && this->lastName == obj.lastName && this->phoneNumber < obj.phoneNumber){return true;}
    return false;
}
bool PhoneBook::operator==(const PhoneBook& obj)
{
    if(this->name == obj.name && this->lastName == obj.lastName && separator == obj.separator && phoneNumber == obj.phoneNumber )
    {
        return true;
    }
        return false;
}
/*checking whether the correct values ​​are entered or not*/
void PhoneBook::isValid()
{
    if(this->phoneNumber.size() != 9)
    {
        std::cout<< "phone number should be 9 digits.";
    }
    if(this->separator == '-' ||this->separator == ':' )
    {
        return;
    }
    else
    {
        std::cout<< "the separator should be `:` or `-`.";
    }
}
/*checks if correct values ​​are entered  
  returns true if something is found to be wrong*/
bool PhoneBook::is_Valid()
{
    if(this->phoneNumber.size() != 9)
    {
        return true;
    }
    if(this->separator == '-' ||this->separator == ':' )
    {
        return false;
    }
    else
    {
        return true;
    }
}
