using namespace std;
#include <iostream>
#include <cstdlib>

#include <list>
#include "Dessin.hpp"
#include "Forme.h"


//-------------------------------------------
Dessin::Dessin(const Dessin& other)
//-------------------------------------------
{
    dessin = other.dessin;
}

list<Forme*>& Dessin::GetList()
{
    return dessin;
}

void Dessin::AddForme(Forme* newforme)
{
    dessin.push_back(newforme);
}

void Dessin::Display()
{
    for(auto it = dessin.begin(); it != dessin.end(); it++)
    {
        (*it)->Display();
    }
}