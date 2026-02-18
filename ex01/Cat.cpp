#include "Cat.hpp"

Cat::Cat() : Animal()
{
    brain = new Brain();
    this->type = "Cat";
    std::cout << "default Cat constructor called!";
    std::cout << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called!";
    std::cout << std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj), brain(new Brain(*obj.brain))
{
    std::cout << "Cat copy constructor called!";
    std::cout << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
    if (this != &obj)
    {
        Animal::operator=(obj);
        delete this->brain;
        this->brain = new Brain(*obj.brain);
        std::cout << "Cat copy assignement called!";
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Cat copy assignement called on same object!";
        std::cout << std::endl;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow";
    std::cout << std::endl;
}

void Cat::setIdea(int index, std::string idea)
{
    this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index)
{
    return this->brain->getIdea(index);
}
