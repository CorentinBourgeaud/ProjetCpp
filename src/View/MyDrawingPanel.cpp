using namespace std ;
#include <iostream>
#include <cstdlib>

#include "constants.hpp"
#include "ID.hpp"
#include "MyDrawingPanel.hpp"
#include "MyFrame.hpp"
#include <math.h>

#include "../Modele/Point.h"
#include "../View/includeform.hpp"


//************************************************************************
//************************************************************************
// MyDrawingPanel class (where drawings are displayed)
//************************************************************************
//************************************************************************

//------------------------------------------------------------------------
MyDrawingPanel::MyDrawingPanel(wxWindow *parent) : wxPanel(parent)
//------------------------------------------------------------------------
// In this constructor, bind some mouse events and the paint event with the appropriate methods
{
	int w, h ;
	GetParent()->GetClientSize(&w,&h) ;
	SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH,0), wxPoint(w, h))) ;
	SetBackgroundColour(wxColour(0xFF,0xFF,0xFF)) ;
	Bind(wxEVT_MOTION, &MyDrawingPanel::OnMouseMove, this);
	Bind(wxEVT_LEFT_DOWN, &MyDrawingPanel::OnMouseLeftDown, this);
	Bind(wxEVT_PAINT, &MyDrawingPanel::OnPaint, this) ;
	m_onePoint.x = (w-WIDGET_PANEL_WIDTH)/2 ;
	m_onePoint.y = h/2 ;
	m_mousePoint = m_onePoint ;

}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseMove(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse is moved
{
	m_mousePoint.x = event.m_x ;
	m_mousePoint.y = event.m_y ;
	MouseMove = true;
	Refresh() ;	// send an event that calls the OnPaint method
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftDown(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse left button is pressed
{
	m_onePoint.x = event.m_x ;
	m_onePoint.y = event.m_y ;
	clickLeft = clickLeft +1;
	Refresh() ; // send an event that calls the OnPaint method
}

//------------------GetWidth()------------------------------------------------------
void MyDrawingPanel::OnPaint(wxPaintEvent &event)
//------------------------------------------------------------------------
// called automatically when the panel is shown for the first time or
// when the panel is resized
// You have to call OnPaint with Refresh() when you need to update the panel content
{
	
	
	// permet de lire les valeurs dans le controleur 
	
	MyFrame* frame =  (MyFrame*)GetParent() ;
	//int radius = frame->GetControlPanel()->GetSliderValue() ;

	//on verifie l'éat des boutons radio pour adapter la methode draw lors de l'édition d'un nouveau dessin 
	bool check = frame->GetControlPanel()->GetCheckBoxValue() ;
	bool radioTrait = frame->GetControlPanel()->GetRadioTrait() ;
	bool radioRect = frame->GetControlPanel()->GetRadioRect() ;
	bool radioCercle = frame->GetControlPanel()->GetRadioCercle() ;
	
	//initialisationGetWidth() du wxPaintDC pour dessiner
	wxPaintDC dc(this);

	//Lecture de l'objet dessin pour ré afficher les formes déjà existantes
	objDessin.Draw(&dc);
	
	//variable statiques communes à toutes instances objets 
	static int x1, y1, x2, y2;

	if (etat == 1)
		{
			printf("bonjour bonjour");
		}

	if(radioTrait)
	{
		////////////////////////////////////	
		//METHODE POUR DESSINER UN TRAIT
		
		if (clickLeft == 1)
		{
			//récuperation du premier point
			x1 = m_onePoint.x;
			y1 = m_onePoint.y;
			//dessin du trait temporaire
			dc.DrawLine(x1, y1, m_mousePoint.x,m_mousePoint.y);
		}
		if(clickLeft == 2 )
		{
			x2 = m_onePoint.x;
			y2 = m_onePoint.y;
			//dessin du trait temporaire pour masquer le décalage de refresh()
			dc.DrawLine(x1, y1, x2, y2);

			//Ajout de l'objet Line dans le dessin
			Line* tmpLine = new Line(x1, y1, x2, y2);
			objDessin.AddForme(tmpLine);
			//réinitialisation de clickLeft et MouseMove à la fin du dessin de la figure
			clickLeft = 0;
		}
	}
	else if(radioRect)
	{
		////////////////////////////////////	
		//METHODE POUR DESSINER UN RECTANGLE
		
		if (clickLeft == 1)
		{
			//récuperation du premier point
			x1 = m_onePoint.x;
			y1 = m_onePoint.y;
			//dessin du rectangle temporaire
			int xF = m_mousePoint.x;
			int yF = m_mousePoint.y;

			int largeur;
			int longueur;

			largeur = xF - x1;
			longueur = yF-y1;

			dc.DrawRectangle(x1, y1, largeur, longueur);
			
		}
		if(clickLeft == 2 )
		{
			int largeur = 0;
			int longueur = 0;

			int x2 = m_onePoint.x;
			int y2 = m_onePoint.y;

			largeur = x2 - x1;
			longueur = y2 - y1;

			//dessin du rectangle temporaire pour masquer le décalage de refresh()
			dc.DrawRectangle(x1, y1, largeur, longueur);

			//Ajout de l'objet Rectangle dans le dessin
			Rectangle* tmpRect = new Rectangle(x1, y1, largeur, longueur);
			objDessin.AddForme(tmpRect);
			//réinitialisation de clickLeft et MouseMove à la fin du dessin de la figure
			clickLeft = 0;
		}
	}
	else
	{
		////////////////////////////////////
		//METHODE POUR DESSINER UN CERCLE
	
		if (clickLeft == 1)
		{
			//récuperation du premier point
			x1 = m_onePoint.x;
			y1 = m_onePoint.y;

			int xF = m_mousePoint.x;
			int yF = m_mousePoint.y;
			int rayon = sqrt((xF-x1)*(xF-x1)+(yF-y1)*(yF-y1));

			//dessin du cercle temporaire
			dc.DrawCircle(x1, y1, rayon);
			
		}
		if(clickLeft == 2 )
		{
			int x2 = m_onePoint.x;
			int y2 = m_onePoint.y;

			int rayon = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
			//dessin du rectangle temporaire pour masquer le décalage de refresh()
			dc.DrawCircle(x1, y1, rayon);

			//Ajout de l'objet Cercle dans le dessin
			Cercle* tmpCercle = new Cercle(x1, y1, rayon);
			objDessin.AddForme(tmpCercle);

			//réinitialisation de clickLeft et MouseMove à la fin du dessin de la figure
			clickLeft = 0;
		}
	}

	/*
	dc.DrawLine(m_mousePoint, m_onePoint) ;
	dc.DrawRectangle(wxPoint(m_onePoint.x-radius/2, m_onePoint.y-radius/2), wxSize(radius,radius)) ;
	dc.DrawCircle(wxPoint(m_mousePoint), radius/2) ;
	*/
	
}

//------------------------------------------------------------------------
void MyDrawingPanel::OpenFile(wxString fileName)
//------------------------------------------------------------------------
{
	// just to open (and close) any file
	FILE* f = fopen(fileName, "r") ;
	if (f)
	{
		wxMessageBox(wxT("The file was opened then closed")) ;
		fclose(f) ;
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::SaveFile(wxString fileName)
//------------------------------------------------------------------------
{
	// just to create a tiny file
	FILE* f = fopen(fileName, "w") ;
	if (!f)
		wxMessageBox(wxT("Cannot save file"));
	else
	{
		fprintf(f, "S1102 software can create and write a file") ;
		wxMessageBox(wxT("The file was saved")) ;
		
		fclose(f) ;
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnCheckEtat(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

