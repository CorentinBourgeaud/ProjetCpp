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

private:
	void OnButton(wxCommandEvent &event) ;
	void OnSlider(wxScrollEvent &event) ;
	void OnCheckBox(wxCommandEvent &event) ;
	wxButton* m_button ;
	wxButton* m_buttonCarre;
	wxSlider* m_slider ;
	wxCheckBox* m_checkBox ;
};

#endif