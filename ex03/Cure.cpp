#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "default Cure constructor called!";
    std::cout << std::endl;
}

Cure::Cure(const Cure& obj) : AMateria(obj)
{
    std::cout << "Cure copy constructor called!";
    std::cout << std::endl;
}

Cure& Cure::operator=(const Cure& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
        std::cout << "Cure copy asignement operator called!";
        std::cout << std::endl;
    }
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called!";
    std::cout << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *";
    std::cout << std::endl;
}
