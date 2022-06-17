using namespace std ;
#include <iostream>
#include <cstdlib>

#include "constants.hpp"
#include "ID.hpp"
#include "MyControlPanel.hpp"
#include "MyFrame.hpp"


//************************************************************************
//************************************************************************
// MyControlePanel class (where controls are displayed)
//************************************************************************
//************************************************************************

//------------------------------------------------------------------------
MyControlPanel::MyControlPanel(wxWindow *parent) : wxPanel(parent)
//------------------------------------------------------------------------
// In this constructor, create the controls and associate each of them (bind) a method
{
	int w, h, y ;
	GetParent()->GetSize(&w,&h) ;
	SetSize(wxRect(wxPoint(0,0), wxPoint(WIDGET_PANEL_WIDTH, h))) ;
	SetBackgroundColour(*wxLIGHT_GREY) ;

	y = WIDGET_Y0 ;
	m_radioNavi = new wxRadioButton(this, ID_RADIONAVIG, wxT("Navigation"), wxPoint(10, y)) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::GetRadioB, this, ID_RADIONAVIG) ;

	y += 40;
	m_radioTrait = new wxRadioButton(this, ID_RADIOTRAIT, wxT("Trait"), wxPoint(10, y));
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::GetRadioB, this, ID_RADIOTRAIT);

	y += 30;
	m_radioRectangle = new wxRadioButton(this, ID_RADIORECT, wxT("Rectangle"), wxPoint(10, y));
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::GetRadioB, this, ID_RADIORECT);

	y += 30;
	m_radioCercle = new wxRadioButton(this, ID_RADIOCERCL, wxT("Cercle"), wxPoint(10, y));
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::GetRadioB, this, ID_RADIOCERCL);

}

//------------------------------------------------------------------------
void MyControlPanel::GetRadioB(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	int etat;
	
	if(m_radioTrait->GetValue() )
	{
		
		etat = 1;
	}
	else if(m_radioRectangle->GetValue() )
	{
		etat = 2;
	}
	else if(m_radioCercle->GetValue() )
	{
		etat = 3;
	}
	else
	{
		etat = 0;
	}
	
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->GetDrawingPanel()->SetEtat(etat) ;
}
