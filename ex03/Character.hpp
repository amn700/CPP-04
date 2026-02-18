#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

struct Node
{
    AMateria* material;
    Node* next;
};

class Character : public ICharacter
{
private:
    std::string name;
    AMateria* inventory[4];
    Node* head;

    void clearInventory();
    void clearLinkedList();
    void copyLinkedList(const Character& other);

public:
    Character();
    Character(std::string const& name);
    Character(const Character& obj);
    Character& operator=(const Character& obj);
    ~Character();

    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    void addToFloor(AMateria* mat);
};

#endif
