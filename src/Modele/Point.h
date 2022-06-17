#ifndef __POINT_H__
#define __POINT_H__

//-------------------------------------------
class Point
//-------------------------------------------
{
public:
    Point();                   // constructeur par défaut
    Point(int x, int y);       // constructeur
    Point(int z);              // constructeur (x = y)
    ~Point() = default;        // destructeur
    void Move(int dX, int dY); // bouge le point

    // Setters
    void SetX(int x);
    void SetY(int y);

    // Getters
    int GetX() const;
    int GetY() const;

    void Display() const;      // affiche les coordonnées du point
    bool XEgalY() const;
    float Distance(const Point &p) const;
    float Distance(const Point *p) const;

private:
    int m_x;                    
    int m_y;                    
};

#endif
