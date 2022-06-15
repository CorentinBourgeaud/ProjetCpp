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
	bool GetRadioTrait() {return m_radioTrait->GetValue() ;} ;
	bool GetRadioRect() {return m_radioRectangle->GetValue() ;} ;
	bool GetRadioCercle() {return m_radioCercle->GetValue() ;} ;
	void GetRadioB(wxCommandEvent &event);
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