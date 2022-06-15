using namespace std ;
#ifndef __Dessein_h__
#define __Dessein_h__

#include <list>
#include "Forme.h"


//------------------------------------------------------------------------
class Dessin
//------------------------------------------------------------------------
{
public:
    Dessin();

private:
    list<Forme> dessin;
};

#endif


//methode  à implémenter ajouter / supprimer / donner la liste entière  / sélectionner un objet forme précise 