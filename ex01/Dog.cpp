#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
    this->type = "Dog";
    std::cout << "default Dog constructor called!";
    std::cout << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called!";
    std::cout << std::endl;
}

Dog::Dog(const Dog& obj) : Animal(obj), brain(new Brain(*obj.brain))
{
    std::cout << "Dog copy constructor called!";
    std::cout << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
    {
        Animal::operator=(obj);
        *brain = *obj.brain;
        std::cout << "Dog copy assignement called!";
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Dog copy assignement called on same object!";
        std::cout << std::endl;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof";
    std::cout << std::endl;
}

void Dog::setIdea(int index, std::string idea)
{
    this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index)
{
    return this->brain->getIdea(index);
}
