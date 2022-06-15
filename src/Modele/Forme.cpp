#include <iostream>
#include "Forme.h"

using namespace std;

Forme::Forme()
{

}

Forme::Forme(const std::string& label)
{

}

Forme::Forme(const Forme& other)
{
    
}

// virtual
Forme::~Forme()
{

}

Forme& Forme::operator=(const Forme& other)
{
    // On renvoit une r�f�rence sur l'objet courant
    return *(this);
}
