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
	m_button = new wxButton(this, ID_BUTTON1, wxT("Click me"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButton, this, ID_BUTTON1) ;

	y += 70;
	m_radioTrait = new wxRadioButton(this, ID_RADIOTRAIT, wxT("Trait"), wxPoint(10, y));
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::GetRadioB, this, ID_RADIOTRAIT);

	y += 30;
	m_radioRectangle = new wxRadioButton(this, ID_RADIORECT, wxT("Rectangle"), wxPoint(10, y));
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::GetRadioB, this, ID_RADIORECT);

	y += 30;
	m_radioCercle = new wxRadioButton(this, ID_RADIOCERCL, wxT("Cercle"), wxPoint(10, y));
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::GetRadioB, this, ID_RADIOCERCL);

	y+= WIDGET_Y_STEP ;
	wxStaticText* text1 = new wxStaticText(this, wxID_ANY, wxT("Radius"), wxPoint(10, y)) ;

	y+= 25 ;
	m_slider = new wxSlider(this, ID_SLIDER1, 10, 2, 100, wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_SLIDER1) ;

	y+= WIDGET_Y_STEP ;
	m_checkBox = new wxCheckBox(this, ID_CHECKBOX1, "Show (x,y)", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX1) ;

}

//------------------------------------------------------------------------
void MyControlPanel::GetRadioB(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	int radioValue= 0;
	
	if(m_radioTrait->GetValue())
	{
		wxMessageBox(wxT("méthode pour les traits")) ;
		radioValue = 1;

	}
	else if(m_radioRectangle->GetValue())
	{
		wxMessageBox(wxT("méthode pour les rectangles")) ;
		radioValue = 2;
	}
	else
	{
		wxMessageBox(wxT("méthode pour les cercles")) ;
		radioValue = 3;
	}

	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
	
}


void MyControlPanel::OnButton(wxCommandEvent &event)
//------------------------------------------------------------------------
{
//	char* s = GetCString() ;
//	wxMessageBox(wxString::FromAscii(s)) ; // call a C function located in the sample.cp module
//	free(s) ;
	wxMessageBox(wxT("You just pressed the button!")) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnSlider(wxScrollEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnCheckBox(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}