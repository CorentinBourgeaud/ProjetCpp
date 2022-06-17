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

private:
	void OnMouseMove(wxMouseEvent &event) ;
	void OnMouseLeftDown(wxMouseEvent &event) ;
	void OnPaint(wxPaintEvent &event) ;
	wxPoint m_mousePoint ;
	wxPoint m_onePoint ;
	
	//variable clickLeft est incrémenter si click gauche de la souris
	int clickLeft = 0;
	// variable MouseMouve passe à true quand  curseur de souris bouge
	bool MouseMove = false;
	Dessin objDessin;
};

#endif