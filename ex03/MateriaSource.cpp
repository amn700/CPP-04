#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    int i = 0;
    while (i < 4)
    {
        this->materias[i] = NULL;
        i++;
    }
}

MateriaSource::MateriaSource(const MateriaSource& obj) : IMateriaSource(obj)
{
    int i = 0;
    while (i < 4)
    {
        if (obj.materias[i])
            this->materias[i] = obj.materias[i]->clone();
        else
            this->materias[i] = NULL;
        i++;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
    if (this != &obj)
    {
        int i = 0;
        while (i < 4)
        {
            if (this->materias[i])
                delete this->materias[i];
            this->materias[i] = NULL;
            i++;
        }
        i = 0;
        while (i < 4)
        {
            if (obj.materias[i])
                this->materias[i] = obj.materias[i]->clone();
            else
                this->materias[i] = NULL;
            i++;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    int i = 0;
    while (i < 4)
    {
        if (this->materias[i])
            delete this->materias[i];
        i++;
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    int i = 0;
    while (i < 4)
    {
        if (!this->materias[i])
        {
            this->materias[i] = m;
            return;
        }
        i++;
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    int i = 0;
    while (i < 4)
    {
        if (this->materias[i] && this->materias[i]->getType() == type)
            return this->materias[i]->clone();
        i++;
    }
    return NULL;
}
