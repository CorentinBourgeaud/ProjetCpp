#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <string>

#include "Forme.h"
#include "Point.h"

//-------------------------------------------
class Rectangle : public Forme
//-------------------------------------------
{
public:                                     // interface publique de la classe
    // Ici on rajoute une label
    Rectangle();
    Rectangle(int x, int y, int w, int h);  // constructeur
    Rectangle(const Point& p, int w, int h);// constructeur
    ~Rectangle();                           // destructeur

    // Setters
    void SetCorner(const Point& p);
    void SetWidth(int w);
    void SetHeight(int h);

    // Getters
    const Point& GetCorner() const;         // On retourne une r�f�rence const sur m_corner
    int GetWidth() const;
    int GetHeight() const;

    // Fonction utilitaires
    void Move(int dX, int dY);                  // d�place le rectangle


    
    virtual void Display() const;      // affiche les coordonn�es du rectangle
    virtual void Draw(wxClientDC* dc) const;         //
/*
    // On rajoute les autres m�thodes virtuelles
    virtual float Surface() const override;
    virtual float Perimeter() const override;
*/

private: // invisible � l?utilisateur de la classe
    Point m_corner;         // Le point
    int m_w;                // les dimensions
    int m_h;                // du rectangle
};

#endif // __RECTANGLE_H__
