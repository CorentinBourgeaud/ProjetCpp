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

//mettre 
int clickLeft = 0;
int MouseMouve = 0;

Point* m_corner = new Point();
Rectangle* rectangle = new Rectangle();
Line* line = new Line();
Cercle* cercle = new Cercle();

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
	MouseMouve = MouseMouve + 1;
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
	
	
	// read the control values
	MyFrame* frame =  (MyFrame*)GetParent() ;
	//int radius = frame->GetControlPanel()->GetSliderValue() ;

	//on verifie l'éat des boutons radio pour adapter la methode draw
	bool check = frame->GetControlPanel()->GetCheckBoxValue() ;
	bool radioTrait = frame->GetControlPanel()->GetRadioTrait() ;
	bool radioRect = frame->GetControlPanel()->GetRadioRect() ;
	bool radioCercle = frame->GetControlPanel()->GetRadioCercle() ;
	
	//initialisationGetWidth() du wxPaintDC pour dessiner 
	wxPaintDC dc(this);
	
	//variable statiques communes à toutes instances objets 
	static int x1, y1, x2, y2;

	
	//(const wxPoint &pt, const wxSize &sz)
	
	dc.DrawRectangle(m_corner->GetX(), m_corner->GetY(), rectangle->GetWidth(),rectangle->GetHeight());
	dc.DrawLine(line->GetLineP1().GetX(), line->GetLineP1().GetY(), line->GetLineP2().GetX(), line->GetLineP2().GetY());
	dc.DrawCircle(cercle->GetCenter().GetX(), cercle->GetCenter().GetY(), cercle->GetRadius());
	if(radioTrait)
	{
		////////////////////////////////////	
		//METHODE POUR DESSINER UN TRAIT
		
		if(clickLeft == 1)
		{
			x1 = m_onePoint.x;
			y1 = m_onePoint.y;
			
		}
		if (clickLeft == 1 && MouseMouve != 0)
		{
			dc.DrawLine(x1, y1, m_mousePoint.x,m_mousePoint.y);
		}
		if(clickLeft == 2 )
		{
			x2 = m_onePoint.x;
			y2 = m_onePoint.y;
			line->SetLineP1( x1, y1);
			line->SetLineP2( x2, y2);

			//dc.DrawLine(x1, y1, x2, y2);
			dc.DrawLine(x1, y1, x2, y2);

			clickLeft = 0;
			MouseMouve = 0;
		}
	}
	else if(radioRect)
	{
		////////////////////////////////////	
		//METHODE POUR DESSINER UN RECTANGLE

		if(clickLeft == 1)
		{
			m_corner->SetX(m_onePoint.x);
    		m_corner->SetY(m_onePoint.y);
			x1 = m_onePoint.x;
			y1 = m_onePoint.y;
		}
		if (clickLeft == 1 && MouseMouve != 0)
		{
			int largeur;
			int longueur;
			int xF = m_mousePoint.x;
			int yF = m_mousePoint.y;
			largeur = xF - x1;
			longueur = yF-y1;
			dc.DrawRectangle(x1, y1, largeur, longueur);
			
		}
		if(clickLeft == 2 )
		{
			int largeur = 0;
			int longueur = 0;
			m_corner->SetX(x1);
    		m_corner->SetY(y1);
			int x2 = m_onePoint.x;
			int y2 = m_onePoint.y;
			largeur = x2 - x1;
			longueur = y2 - y1;
			rectangle->SetWidth(largeur);
			rectangle->SetHeight(longueur);
			dc.DrawRectangle(x1, y1, largeur, longueur);
			clickLeft = 0;
			MouseMouve = 0;
		}
	}
	else
	{
		////////////////////////////////////
		//METHODE POUR DESSINER UN CERCLE
	
		if(clickLeft == 1)
		{
			
			x1 = m_onePoint.x;
			y1 = m_onePoint.y;
			 
		}
		if (clickLeft == 1 && MouseMouve != 0)
		{
			
			int xF = m_mousePoint.x;
			int yF = m_mousePoint.y;
			int rayon = sqrt((xF-x1)*(xF-x1)+(yF-y1)*(yF-y1));
			dc.DrawCircle(x1, y1, rayon);
			
		}
		if(clickLeft == 2 )
		{
			int xF = m_onePoint.x;
			int yF = m_onePoint.y;
			Point* point = new Point(x1, y1);
			cercle->SetCenter(*point);
			int rayon = sqrt((xF-x1)*(xF-x1)+(yF-y1)*(yF-y1));
			cercle->SetRadius(rayon);
			dc.DrawCircle(x1, y1, rayon);
			clickLeft = 0;
			MouseMouve = 0;
		}

	}

	/*
	dc.DrawLine(m_mousePoint, m_onePoint) ;
	dc.DrawRectangle(wxPoint(m_onePoint.x-radius/2, m_onePoint.y-radius/2), wxSize(radius,radius)) ;
	dc.DrawCircle(wxPoint(m_mousePoint), radius/2) ;
	*/
	if (check)
	{
		wxString coordinates ;
		coordinates.sprintf(wxT("(%d,%d)"), m_mousePoint.x, m_mousePoint.y) ;
		dc.DrawText(coordinates, wxPoint(m_mousePoint.x, m_mousePoint.y+20)) ;
	}
	
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