#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Testing correct Animal with virtual functions ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->get_type() << " " << std::endl;
    std::cout << i->get_type() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    
    std::cout << std::endl << "=== Testing WrongAnimal without virtual functions ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->get_type() << " " << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    return 0;
}
