#include "Cercle.h"
#include <iostream>
#include <cstdlib>

#define _USE_MATH_DEFINES   // To include PI value
#include <math.h>

using namespace std;

// Constructeur riche. On appelle une version sp�cifique du construceur
// de Forme et on initilise le centre et le radius de m�me
Cercle::Cercle(Point centre, int radius) :
    m_center(centre),
    m_radius(radius)
{}

Cercle::Cercle()
{}

Cercle::Cercle(int x1, int y1, int radius) : m_center(x1,y1), m_radius(radius)
{}

// constructeur de copie
Cercle::Cercle(const Cercle &other) : m_center(other.m_center), m_radius(other.m_radius)
{}

//getters 
Point Cercle::GetCenter(){
    return m_center;
}

int Cercle::GetRadius(){
    return m_radius;
}
//setters 
void Cercle::SetCenter(Point p)
{
    this->m_center = p;
}
void Cercle::SetRadius(int radius)
{
    this->m_radius = radius;
}


Cercle &Cercle::operator=(const Cercle &other)
{
    if (this == &other) return *this; // handle self assignment
    m_center = other.m_center;
    m_radius = other.m_radius;
    return *this;
}

//Méthode d'affichage, utiliser pour le debugage
void Cercle::Display() const
{
    cout << "Cercle = (" << m_center.GetX() << "," << m_center.GetY() << ") radius=" << m_radius << endl;
}

//Méthode de dessin de la forme via une méthode wx
void Cercle::Draw(wxDC* dc) const
{
    dc->DrawCircle(m_center.GetX(), m_center.GetY(), m_radius);
}