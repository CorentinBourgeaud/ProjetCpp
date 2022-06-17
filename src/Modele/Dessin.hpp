#ifndef __Dessin_h__
#define __Dessin_h__

#include "../View/include.hpp"
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

    std::list<Forme*>& GetList();
    void AddForme(Forme* newforme);
    void Display();
    void Draw(wxDC* dc);

    void saveImage(wxString filename, int height, int width);

private:
    std::list<Forme*> dessin;
};

#endif
