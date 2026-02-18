#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
    std::cout << "default AMateria constructor called!";
    std::cout << std::endl;
}

AMateria::AMateria(std::string const& type)
{
    this->type = type;
    std::cout << "AMateria parameter constructor called!";
    std::cout << std::endl;
}

AMateria::AMateria(const AMateria& obj)
{
    this->type = obj.type;
    std::cout << "AMateria copy constructor called!";
    std::cout << std::endl;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
        std::cout << "AMateria copy asignement operator called!";
        std::cout << std::endl;
    }
    else
    {
        std::cout << "AMateria copy assignment of the same object";
        std::cout << std::endl;
    }
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called!";
    std::cout << std::endl;
}

std::string const& AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses an abstract materia on " << target.getName() << " *";
    std::cout << std::endl;
}
