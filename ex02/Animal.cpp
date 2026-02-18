#include "Animal.hpp"

std::string Animal::get_type() const
{
    return this->type;
}

Animal::Animal()
{
    type = "default";
    std::cout << "default Animal constructor called!";
    std::cout << std::endl;
}

Animal::Animal(const Animal& obj)
{
    type = obj.type;
    std::cout << "Animal copy constructor called!";
    std::cout << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
    if (&obj != this)
    {
        std::cout << "Animal copy asignement operator called!";
        std::cout << std::endl;
        this->type = obj.type;
    }
    else
    {
        std::cout << "Animal copy assignment of the same object";
        std::cout << std::endl;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called!";
    std::cout << std::endl;
}
