#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    ~Brain();
    Brain(const Brain& obj);
    Brain& operator=(const Brain& obj);

    std::string getIdea(int index) const;
    void setIdea(int index, const std::string& idea);
};

#endif
