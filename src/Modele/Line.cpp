#include "Line.hpp"

#include <iostream>
#include <cstdlib>

#include "Point.h"
#include "Forme.h"

using namespace std;

Line::Line(int x1, int y1, int x2, int y2) : m_p1(x1,y1), m_p2(x2,y2)
{}

Line::Line(Point p1, Point p2) : m_p1(p1), m_p2(p2)
{}

Point Line::GetLineP1(){ return m_p1; }
Point Line::GetLineP2(){ return m_p2; }

void Line::SetLineP1(int x1, int y1)
{ 
    m_p1.SetX(x1);
    m_p1.SetY(y1); 
}
void Line::SetLineP2(int x2, int y2)
{ 
    m_p2.SetX(x2);
    m_p2.SetY(y2); 
}

Line &Line::operator=(const Line &other)
{
    if (this == &other) return *this; // handle self assignment
    m_p1 = other.m_p1;
    m_p2 = other.m_p2;
    return *this;
}

void Line::Display() const
{
    cout << "Line = (" << m_p1.GetX() << "," << m_p1.GetY() << ") , (" << m_p2.GetX() << "," << m_p2.GetY() << ")" << endl;
}

void Line::Draw(wxClientDC* dc) const
{
    dc->DrawLine(m_p1.GetX(), m_p1.GetY(), m_p2.GetX(), m_p2.GetY());
}