#include "Cercle.h"
#include <iostream>
#include <cstdlib>

#define _USE_MATH_DEFINES   // To include PI value
#include <math.h>

using namespace std;    // jamais dans un .h(pp) !

// Constructeur riche. On appelle une version sp�cifique du construceur
// de Forme et on initilise le centre et le radius de m�me
Cercle::Cercle(Point centre, int radius) :
    m_center(centre),
    m_radius(radius)
{}
/* Alternative
Cercle::Cercle(Point centre, int radius, string label)
{
    m_center = centre;
    m_radius = radius;
    m_label = label;
    cout << "Cercle (riche)" << endl;
    SetLabel(label);
    m_circleCount++;
}
*/


// constructeur par d�faut, le constructeur par d�faut de
// Forme est automatiquement appel�
Cercle::Cercle()
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



/*
// Calcul de Surface en utilisant M_PI de #include <math.h>
float Cercle::Surface() const
{
    return m_radius * m_radius * (float)M_PI;
}

// Calcul de p�rim�tre
float Cercle::Perimeter() const
{
    return m_radius * (float)M_PI * 2.f;
}
*/
// virtual void Cercle::Display() const override
void Cercle::Display() const
{
    cout << "Cercle = (" << m_center.GetX() << "," << m_center.GetY() << ") radius=" << m_radius << endl;
}

void Cercle::Draw() const
{
    
}