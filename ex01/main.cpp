#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "=== Creating Animals with Brains ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl << "=== Testing makeSound ===" << std::endl;
    std::cout << j->get_type() << " says: ";
    j->makeSound();
    std::cout << i->get_type() << " says: ";
    i->makeSound();

    std::cout << std::endl << "=== Deleting Animals ===" << std::endl;
    delete j;
    delete i;

    std::cout << std::endl << "=== Testing Deep Copy ===" << std::endl;
    Dog basic;
    basic.setIdea(0, "I want a bone");
    basic.setIdea(1, "I want to play");
    {
        Dog tmp = basic;
        std::cout << "tmp idea[0]: " << tmp.getIdea(0) << std::endl;
        std::cout << "tmp idea[1]: " << tmp.getIdea(1) << std::endl;
        tmp.setIdea(0, "I want a treat");
        std::cout << "After modifying tmp:" << std::endl;
        std::cout << "tmp idea[0]: " << tmp.getIdea(0) << std::endl;
        std::cout << "basic idea[0]: " << basic.getIdea(0) << std::endl;
        std::cout << "Temporary dog will be destroyed" << std::endl;
    }
    std::cout << "Basic dog still exists after tmp destruction" << std::endl;
    std::cout << "basic idea[0]: " << basic.getIdea(0) << std::endl;

    std::cout << std::endl << "=== Array of Animals ===" << std::endl;
    const int arraySize = 4;
    Animal* animals[arraySize];

    for (int idx = 0; idx < arraySize; idx++)
    {
        if (idx < arraySize / 2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }

    std::cout << std::endl << "=== Making all animals sound ===" << std::endl;
    for (int idx = 0; idx < arraySize; idx++)
    {
        std::cout << animals[idx]->get_type() << " says: ";
        animals[idx]->makeSound();
    }

    std::cout << std::endl << "=== Deleting all animals ===" << std::endl;
    for (int idx = 0; idx < arraySize; idx++)
    {
        delete animals[idx];
    }

    return 0;
}
