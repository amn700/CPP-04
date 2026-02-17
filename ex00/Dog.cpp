#include "Dog.hpp"

Dog:: Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "default Dog constructor called!";
    std::cout <<std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called!";
    std::cout <<std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Dog copy constructor called!";
    std::cout <<std::endl;
}

Dog& Dog:: operator=(const Dog &obj)
{
    if (this != &obj)
    {
        std::cout << "Dog copy assignement called!";
        std::cout <<std::endl;
        this->type = obj.type;   
    }
    else
    {
        std::cout << "Dog copy assignement called on same object!";
        std::cout <<std::endl;
    }    
    return *this;
}

void Dog:: makeSound()const
{
    std::cout << "Woof Woof";
    std::cout <<std::endl;
}
