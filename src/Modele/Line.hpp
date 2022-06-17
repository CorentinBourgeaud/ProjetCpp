#ifndef __LINE_H__
#define __LINE_H__

#include "Point.h"
#include "Forme.h"
#include <iostream>

class Line : public Forme
{
public:
// Construction par défaut, par copie, avec paramètres
    Line() = default;
    Line(const Line &other);
    Line(int x1, int y1, int x2, int y2);
    Line(Point p1, Point p2);

    // Destructeur virtuel car on peut dériver cette classe
    ~Line() = default;

    // Opérateur d'affectation
    Line &operator=(const Line &other);
    
    //getter 
    Point GetLineP1();
    Point GetLineP2();
    //setter 
    void SetLineP1(int x1, int y1); //inverser x1 x2 ?
    void SetLineP2(int x2, int y2);

    // Méthodes virtuelles pour surcharger celles de la classe Mère
    virtual void Display() const;
    virtual void Draw(wxDC* dc) const;

private:
    Point m_p1;
    Point m_p2;
};

#endif
