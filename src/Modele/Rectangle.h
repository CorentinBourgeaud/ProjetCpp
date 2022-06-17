#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <string>

#include "Forme.h"
#include "Point.h"

//-------------------------------------------
class Rectangle : public Forme
//-------------------------------------------
{
public:
    Rectangle();
    Rectangle(int x, int y, int w, int h);  // constructeur
    Rectangle(const Point& p, int w, int h);// constructeur
    ~Rectangle();                           // destructeur

    // Setters
    void SetCorner(const Point& p);
    void SetWidth(int w);
    void SetHeight(int h);

    // Getters
    const Point& GetCorner() const;         // On retourne une référence const sur m_corner
    int GetWidth() const;
    int GetHeight() const;

    // Fonction utilitaires
    void Move(int dX, int dY);              // déplace le rectangle


    
    void Display() const;
    void Draw(wxDC* dc) const;

private:
    Point m_corner;         // Le point
    int m_w;                // les dimensions
    int m_h;                // du rectangle
};

#endif
