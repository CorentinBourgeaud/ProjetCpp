using namespace std ;
#ifndef __Dessin_h__
#define __Dessin_h__

#include <list>
#include "Forme.h"


//------------------------------------------------------------------------
class Dessin
//------------------------------------------------------------------------
{
public:
    Dessin() = default;
    Dessin(const Dessin& other);
    ~Dessin() = default;

    list<Forme*>& GetList();
    void AddForme(Forme* newforme);
    void Display();

private:
    list<Forme*> dessin;
};

#endif
