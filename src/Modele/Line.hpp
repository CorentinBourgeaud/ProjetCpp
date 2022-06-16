#ifndef __LINE_H__
#define __LINE_H__

#include "Point.h"
#include "Forme.h"
#include <iostream>

class Line : public Forme
{
public:
// Construction par d�faut, par copie, avec param�tres
    Line() = default;
    Line(const Line &other);
    Line(int x1, int y1, int x2, int y2);
    Line(Point p1, Point p2);

    // Destructeur virtuel car on peut d�river cette classe
    ~Line() = default;

    // Op�rateur d'affectation
    Line &operator=(const Line &other);
    
    //getter 
    Point GetLineP1();
    Point GetLineP2();
    //setter 
    void SetLineP1(int x1, int y1); //inverser x1 x2 ?
    void SetLineP2(int x2, int y2);

    // M�thodes virtuelles pour surcharger celles de la classe M�re
    /*virtual float Surface() const override;
    virtual float Perimeter() const override;*/
    virtual void Display() const;
    virtual void Draw(wxPaintDC* dc) const;

private:
    Point m_p1;
    Point m_p2;
};

#endif
