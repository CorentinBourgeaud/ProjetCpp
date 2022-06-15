#ifndef __POINT_H__
#define __POINT_H__

//-------------------------------------------
class Point
//-------------------------------------------
{
public:                        // interface publique de la classe
    Point();                   // constructeur par d�faut
    Point(int x, int y);       // constructeur
    Point(int z);              // constructeur (x = y)
    ~Point() = default;                  // destructeur
    void Move(int dX, int dY); // bouge le point

    // Setters
    void SetX(int x);
    void SetY(int y);

    // Getters
    int GetX() const;
    int GetY() const;

    // M�thodes const (qui ne modifie pas l'objet)
    void Display() const;      // affiche les coordonn�es du point
    bool XEgalY() const;
    float Distance(const Point &p) const;
    float Distance(const Point *p) const;

private:                        // invisible � l?utilisateur de la classe
    int m_x;                    // les coordonn�es
    int m_y;                    // du point
};

#endif // __POINT_H__ : retour � la ligne obligatoire pour certains compilateurs
