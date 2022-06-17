#ifndef __CERCLE_H__
#define __CERCLE_H__

#include "Forme.h"
#include "Point.h"
#include <iostream>

class Cercle : public Forme
{
public:
    Cercle();
    Cercle(const Cercle &other);
    Cercle(int x1, int y1, int radius);
    Cercle(Point centre, int radius);

    ~Cercle() = default;

    // Op�rateur d'affectation
    Cercle &operator=(const Cercle &other);

    virtual void Display() const;
    virtual void Draw(wxDC* dc) const;
    //getters 
    Point GetCenter();
    int GetRadius();
    //setters
    void SetCenter(Point p);
    void SetRadius(int radius);


private:
    Point m_center;
    int m_radius;
};
#endif // __CERCLE_H__