#include "PhoneBook.h"

void quickSort(std::vector<PhoneBook>& vec,int first , int last)
{
    if(first < last)
    {
        int left =  first;
        int rigth = last;
        PhoneBook mid = vec[(first+last)/2];
        do{
            while(vec[left] < mid)
                ++left;
            while(vec[rigth] > mid)
                --rigth;
            if(left <= rigth)
            {
                std::swap(vec[left], vec[rigth]);
                ++left;
                --rigth;
            }
        }
        while (left < rigth);
        quickSort(vec, first, rigth);
        quickSort(vec, left, last);
    }
}
int main(){
    std::string file_name;
    std::cout << "please provide the full path to the file" << std::endl;
    std::cin >> file_name ;
    PhoneBook temp;
    std::vector<PhoneBook> vec;
    std::fstream file;
    file.open(file_name);
    if(file.is_open())
    {
        while(!file.eof()){
            file >> temp ;
            vec.push_back(temp);
        }
    }
    else
    {
        std::cout << "This File is a Invalid" << std::endl;
        std::cout << "please provide the full path to the file";
        std::exit(0);
    }
    int first = 0;
    int last = vec.size()-1;
    quickSort(vec, first, last);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<PhoneBook>(std::cout));
    std::cout << std::endl << std::endl;
    std::cout << "Validations:" << std::endl;
    for(int i = 0; i < vec.size(); ++i)
    {   
        if(vec[i].is_Valid())
        {
            std::cout << "Line" << " " << i + 1 << ":  ";
            vec[i].isValid();
            std::cout << std::endl;
        }
    }
    file.close();
    return 0;
}