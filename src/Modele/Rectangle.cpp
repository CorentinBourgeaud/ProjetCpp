#include <iostream>
#include <cstdlib>
#include <cmath> // pour sqrt

#include "Rectangle.h"

using namespace std;


//-------------------------------------------
Rectangle::Rectangle()   
//-------------------------------------------
{
    m_corner.SetX(0);
    m_corner.SetY(0);
    m_w = 0;
    m_h = 0;
}

//-------------------------------------------
Rectangle::Rectangle(int x, int y, int w, int h)   
//-------------------------------------------
{
    m_corner.SetX(x);
    m_corner.SetY(y);
    m_w = w;
    m_h = h;
}

//-------------------------------------------
Rectangle::Rectangle(const Point& p, int w, int h) :
    m_corner(p.GetX(),p.GetY()),
    m_w(w),
    m_h(h)

{}

//-------------------------------------------
Rectangle::~Rectangle()
//-------------------------------------------
{}

//-------------------------------------------
void Rectangle::SetCorner(const Point& p)
//-------------------------------------------
{
    m_corner = p;
}

//-------------------------------------------
void Rectangle::SetWidth(int w)
//-------------------------------------------
{
    m_w = w;
}

//-------------------------------------------
void Rectangle::SetHeight(int h)
//-------------------------------------------
{
    m_h = h;
}

//-------------------------------------------
const Point& Rectangle::GetCorner() const
//-------------------------------------------
{
    return m_corner;
}

//-------------------------------------------
int Rectangle::GetWidth() const
//-------------------------------------------
{
    return m_w;
}

//-------------------------------------------
int Rectangle::GetHeight() const
//-------------------------------------------
{
    return m_h;
}

//Méthode d'affichage, utiliser pour le debugage
//-------------------------------------------
void Rectangle::Display() const
//-------------------------------------------
{
    // On affiche le nom
    cout << "Rectangle (" << m_corner.GetX() << "," << m_corner.GetY() << ") w=" << m_w << " h=" << m_h << ")" << endl;
}

//Méthode de dessin de la forme via une méthode wx
void Rectangle::Draw(wxDC* dc) const
{
	dc->DrawRectangle(m_corner.GetX(), m_corner.GetY(), m_w, m_h);
}