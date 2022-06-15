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
	m_buttonTrait = new wxButton(this, ID_BUTTON2, wxT("Trait"), wxPoint(10, y));
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButton, this, ID_BUTTON2);

	y += 35;
	m_buttonRectangle = new wxButton(this, ID_BUTTON3, wxT("Rectangle"), wxPoint(10, y));
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButton, this, ID_BUTTON3);

	y += 35;
	m_buttonCercle = new wxButton(this, ID_BUTTON4, wxT("Cercle"), wxPoint(10, y));
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButton, this, ID_BUTTON4);

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