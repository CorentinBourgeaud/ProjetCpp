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

//Ajout d'une forme à la liste
void Dessin::AddForme(Forme* newforme)
{
    dessin.push_back(newforme);
}

//Affche tout les élémentes de la liste
void Dessin::Display()
{
    for(auto it = dessin.begin(); it != dessin.end(); it++)
    {
        (*it)->Display();
    }
}

//Dessine tout les élémentes de la liste
void Dessin::Draw(wxDC* dc)
{
    //wxClientDC
    for(auto it = dessin.begin(); it != dessin.end(); it++)
    {
        (*it)->Draw(dc);
    }
}

//Permet la sauvgarde du dessin dans un fichier svg
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