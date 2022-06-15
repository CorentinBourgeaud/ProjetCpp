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
    ~Dessin();

    list<Forme*>& GetList();
    void AddForme(Forme* newforme);

private:
    list<Forme*> dessin;
};

#endif
