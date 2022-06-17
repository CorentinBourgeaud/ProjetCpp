using namespace std ;
#ifndef __MyDrawingPanel_h__
#define __MyDrawingPanel_h__

#include "include.hpp"
#include "includeform.hpp"
#include "../Modele/Dessin.hpp"


//------------------------------------------------------------------------
class MyDrawingPanel: public wxPanel
//------------------------------------------------------------------------
{
public:
	MyDrawingPanel( wxWindow *parent ) ;
	void OpenFile(wxString fileName) ;
	void SaveFile(wxString fileName) ;
	void SetEtat(int x){this->etat = x;} ;;
private:
	void OnMouseMove(wxMouseEvent &event) ;
	void OnMouseLeftDown(wxMouseEvent &event) ;
	void OnPaint(wxPaintEvent &event) ;
	void OnCheckEtat(wxCommandEvent &event) ;
	wxPoint m_mousePoint ;
	wxPoint m_onePoint ;
	
	//variable clickLeft est incrémenter si click gauche de la souris
	int clickLeft = 0;
	// variable MouseMouve passe à true quand curseur de souris bouge
	bool MouseMove = false;
	//etat de MyDrawingPanel qui l'oblige à dessiner la forme ordonné par MyControlPanel
	int etat = 0;
	//objet Dessin qui stocke les formes et permet de redessiner les formes déjà implémentéesà chaque appel de OnPaint
	Dessin objDessin;

};

#endif