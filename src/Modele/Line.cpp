#include "Line.hpp"

#include <iostream>
#include <cstdlib>

using namespace std;

Line::Line() : m_p1(), m_p2()
{}

Line::Line(int x1, int y1, int x2, int y2) : m_p1(x1,y1), m_p2(x2,y2)
{}

Line::Line(Point p1, Point p2) : m_p1(p1), m_p2(p2)
{}

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