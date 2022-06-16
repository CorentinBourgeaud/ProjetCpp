#ifndef __FORME_H__
#define __FORME_H__

#include "../View/include.hpp"
#include <string>
#include <iostream>

class Forme
{
public:
    // Construction/Destruction
    Forme() = default;
    Forme(const Forme& other);          // Construction par recopie
    virtual ~Forme() = default;

    // Operator d'affectation
    Forme& operator=(const Forme& other);

    //Méthode d'affichage des infos et de dessin sur le drawpanel
    virtual void Display() const = 0 ;
    virtual void Draw(wxPaintDC* dc) const = 0;
    /*virtual float Surface() const { return 0.0f; }
    virtual float Perimeter() const { return 0.0f; }*/

//protected:

};

#endif 