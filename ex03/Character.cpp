#include "Character.hpp"

Character::Character()
{
    this->name = "";
    this->head = NULL;
    int i = 0;
    while (i < 4)
    {
        inventory[i] = NULL;
        i++;
    }
}

Character::Character(std::string const& name)
{
    this->name = name;
    this->head = NULL;
    int i = 0;
    while (i < 4)
    {
        inventory[i] = NULL;
        i++;
    }
}

Character::Character(const Character& obj)
{
    this->name = obj.name;
    this->head = NULL;
    int i = 0;
    while (i < 4)
    {
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone();
        else
            inventory[i] = NULL;
        i++;
    }
    copyLinkedList(obj);
}

Character& Character::operator=(const Character& obj)
{
    if (this != &obj)
    {
        name = obj.name;
        clearInventory();
        clearLinkedList();
        int i = 0;
        while (i < 4)
        {
            if (obj.inventory[i])
                inventory[i] = obj.inventory[i]->clone();
            else
                inventory[i] = NULL;
            i++;
        }
        copyLinkedList(obj);
    }
    return *this;
}

Character::~Character()
{
    clearInventory();
    clearLinkedList();
}

std::string const& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    int i = 0;
    while (i < 4)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
        i++;
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    addToFloor(inventory[idx]);
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}

void Character::addToFloor(AMateria* mat)
{
    Node* newnode = new Node();
    newnode->material = mat;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void Character::clearInventory()
{
    int i = 0;
    while (i < 4)
    {
        if (inventory[i])
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
        i++;
    }
}

void Character::clearLinkedList()
{
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current->material;
        delete current;
        current = next;
    }
    head = NULL;
}

void Character::copyLinkedList(const Character& other)
{
    Node* current = other.head;
    while (current != NULL)
    {
        addToFloor(current->material->clone());
        current = current->next;
    }
}
