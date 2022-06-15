using namespace std ;
#ifndef __MyControlPanel_h__
#define __MyControlPanel_h__

#include "include.hpp"

//------------------------------------------------------------------------
class MyControlPanel: public wxPanel
//------------------------------------------------------------------------
{
public:
	MyControlPanel( wxWindow *parent ) ;
	int GetSliderValue() {return m_slider->GetValue() ;} ;
	bool GetCheckBoxValue() {return m_checkBox->GetValue() ;} ;
	/*
	void OnTrait(wxCommandEvent &event);
	void OnRectangle(wxCommandEvent &event);
	void OnCercle(wxCommandEvent &event);
	*/
	void OnRadioB(wxCommandEvent &event);
private:
	void OnButton(wxCommandEvent &event) ;
	void OnSlider(wxScrollEvent &event) ;
	void OnCheckBox(wxCommandEvent &event) ;
	wxButton* m_button ;
	wxRadioButton* m_radioTrait;
	wxRadioButton* m_radioRectangle;
	wxRadioButton* m_radioCercle;
	wxSlider* m_slider ;
	wxCheckBox* m_checkBox ;
};

#endif