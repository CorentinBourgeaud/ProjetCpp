#include <iostream>
#include <cstdlib>
#include <cmath> // pour sqrt

// Inutile d'include Point.h car il est inclut dans Rectangle.h
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
// attention, cette version appelle le constructeur par d�faut de Point
// comme le compilateur ne l?a pas cr��, il faut le rajouter dans Point
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
//-------------------------------------------
// cette version n'appelle pas le constructeur par d�faut de Point
// car on utilise la liste d'initialisation
// On aurait pu simplifier en cr�ant un constructeur par copie pour la classe Point
{}

//-------------------------------------------
Rectangle::~Rectangle()
//-------------------------------------------
{}

//-------------------------------------------
void Rectangle::SetCorner(const Point& p)
//-------------------------------------------
{
    // On utilise operator= d�finit automatiquement par le compilateur
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
    // Retourne une r�f�rence const sur m_corner
    // pour �viter une copie d'objet
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

/*
//-------------------------------------------
void Rectangle::Display() const
//-------------------------------------------
{
    // On affiche le nom
    std::cout << "Rectangle " << GetLabel() << "= (";
    m_corner.Display();
    cout << " w=" << m_w << " h=" << m_h << ")"
    << " P=" << Perimeter() << " S=" << Surface() << endl;
}*/

//-------------------------------------------
void Rectangle::Move(int dX, int dY)
//-------------------------------------------
{
    m_corner.Move(dX, dY);
}

/*
//-------------------------------------------
bool Rectangle::IsInside(const Rectangle &r) const
//-------------------------------------------
// retourne true si le rectangle est enti�rement � l'int�rieur (inclus) dans le Rectangle r
// si r1 est inclus dans r2
{
    // On r�cup�re les valeurs des points du rectangle
    int x1r1 = GetCorner().GetX();
    int y1r1 = GetCorner().GetY();
    int x2r1 = x1r1 + m_w;
    int y2r1 = y1r1 + m_h;
    int x1r2 = r.GetCorner().GetX();
    int y1r2 = r.GetCorner().GetY();
    int x2r2 = x1r2 + r.GetWidth();
    int y2r2 = y1r2 + r.GetHeight();

    // On v�rifier que r est inclus dans ce Rectangle (this)
    return ((x1r1 > x1r2 && x1r1 < x2r2) || (x1r1 < x1r2 && x1r1 > x2r2)) &&
           ((x1r1 > x1r2 && x1r1 < x2r2) || (x1r1 < x1r2 && x1r1 > x2r2));
}

// On red�finit les m�thodes virtuelles pour les affiner
float Rectangle::Surface() const
{
    return (float)(m_w * m_h);
}

float Rectangle::Perimeter() const
{
    return (float)(2*m_w + 2*m_h);;
}
*/