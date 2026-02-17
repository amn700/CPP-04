#include "WrongCat.hpp"

WrongCat:: WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "default WrongCat constructor called!";
    std::cout <<std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called!";
    std::cout <<std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
    std::cout << "WrongCat copy constructor called!";
    std::cout <<std::endl;
}

WrongCat& WrongCat:: operator=(const WrongCat &obj)
{
    if (this != &obj)
    {
        std::cout << "WrongCat copy assignement called!";
        std::cout <<std::endl;
        this->type = obj.type;   
    }
    else
    {
        std::cout << "WrongCat copy assignement called on same object!";
        std::cout <<std::endl;
    }    
    return *this;
}

void WrongCat:: makeSound()const
{
    std::cout << "Wrong Meow Meow";
    std::cout <<std::endl;
}
