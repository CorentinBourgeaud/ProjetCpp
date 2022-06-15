#ifndef __FORME_H__
#define __FORME_H__

#include <string>
#include <iostream>

class Forme
{
public:
    // Construction/Destruction
    Forme();
    Forme(const std::string& label);    // Avec une string
    Forme(const Forme& other);          // Construction par recopie
    virtual ~Forme();

    // Operator d'affectation
    Forme& operator=(const Forme& other);

    virtual void Display() const = 0 ;
    /*virtual float Surface() const { return 0.0f; }
    virtual float Perimeter() const { return 0.0f; }*/

protected:  // ou private

};

#endif // __FORME_H__
