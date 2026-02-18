#include "Brain.hpp"

Brain::Brain()
{
    int i = 0;
    while (i < 100)
    {
        this->ideas[i] = "default idea";
        i++;
    }
    std::cout << "default Brain constructor called!";
    std::cout << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called!";
    std::cout << std::endl;
}

Brain& Brain::operator=(const Brain& obj)
{
    if (this != &obj)
    {
        int i = 0;
        while (i < 100)
        {
            this->ideas[i] = obj.ideas[i];
            i++;
        }
        std::cout << "Brain copy asignement operator called!";
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Brain copy assignment of the same object";
        std::cout << std::endl;
    }
    return *this;
}

Brain::Brain(const Brain& obj)
{
    int i = 0;
    while (i < 100)
    {
        this->ideas[i] = obj.ideas[i];
        i++;
    }
    std::cout << "Brain copy constructor called!";
    std::cout << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
    {
        return ideas[index];
    }
    return "";
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
    {
        ideas[index] = idea;
    }
}
