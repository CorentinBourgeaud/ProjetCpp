#include <iostream>
#include "Forme.h"

using namespace std;

Forme::Forme(const Forme& other)
{
    
}

Forme& Forme::operator=(const Forme& other)
{
    // On renvoit une r�f�rence sur l'objet courant
    return *(this);
}
