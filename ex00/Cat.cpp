#include "Cat.hpp"

Cat:: Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "default Cat constructor called!";
    std::cout <<std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called!";
    std::cout <<std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
    std::cout << "Cat copy constructor called!";
    std::cout <<std::endl;
}

Cat& Cat:: operator=(const Cat &obj)
{
    if (this != &obj)
    {
        std::cout << "Cat copy assignement called!";
        std::cout <<std::endl;
        this->type = obj.type;   
    }
    else
    {
        std::cout << "Cat copy assignement called on same object!";
        std::cout <<std::endl;
    }    
    return *this;
}

void Cat:: makeSound()const
{
    std::cout << "Meow Meow";
    std::cout <<std::endl;
}
