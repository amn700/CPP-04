#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "default Ice constructor called!";
    std::cout << std::endl;
}

Ice::Ice(const Ice& obj) : AMateria(obj)
{
    std::cout << "Ice copy constructor called!";
    std::cout << std::endl;
}

Ice& Ice::operator=(const Ice& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
        std::cout << "Ice copy asignement operator called!";
        std::cout << std::endl;
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called!";
    std::cout << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *";
    std::cout << std::endl;
}
