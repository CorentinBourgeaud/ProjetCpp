using namespace std;
#include <iostream>
#include <cstdlib>

#include <list>
#include "Dessin.hpp"
#include "Forme.h"


//-------------------------------------------
Dessin::Dessin(const Dessin& other)
//-------------------------------------------
{
    dessin = other.dessin;
}

list<Forme*>& Dessin::GetList()
{
    return dessin;
}

void Dessin::AddForme(Forme* newforme)
{
    dessin.push_back(newforme);
}

void Dessin::Display()
{
    for(auto it = dessin.begin(); it != dessin.end(); it++)
    {
        (*it)->Display();
    }
}

void Dessin::Draw(wxDC* dc)
{
    //wxClientDC
    for(auto it = dessin.begin(); it != dessin.end(); it++)
    {
        (*it)->Draw(dc);
    }
}

void Dessin::saveImage(wxString fileName, int height, int width)
{

    wxSVGFileDC dcFile(fileName, width, height);
    dcFile.SetBrush(*wxWHITE_BRUSH);
    dcFile.DrawRectangle(0, 0, width, height);

    for(auto it = dessin.begin(); it != dessin.end(); it++)
    {
        (*it)->Draw(&dcFile);
    }

}