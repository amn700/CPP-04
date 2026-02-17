#include "WrongAnimal.hpp"

std::string WrongAnimal:: get_type() const
{
    return this->type;
}

WrongAnimal:: WrongAnimal()
{
    type = "wrong animal";
    std::cout << "default WrongAnimal constructor called!";
    std::cout <<std::endl;
}

WrongAnimal:: WrongAnimal(const WrongAnimal& obj)
{
    type = obj.type;
    std::cout << "WrongAnimal copy constructor called!";
    std::cout <<std::endl;
}

void WrongAnimal:: makeSound() const
{
    std::cout << "WrongAnimal sound !!";
    std::cout <<std::endl;
}

 WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
    if (&obj != this)
    {
        std::cout << "WrongAnimal copy asignement operator called!";
        std::cout <<std::endl;
        this->type = obj.type;
    }
    else
    {
        std::cout << "WrongAnimal copy assignment of the same object";
        std::cout <<std::endl;
    }
    return *this;
}

WrongAnimal:: ~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called!";
    std::cout <<std::endl; 
}
