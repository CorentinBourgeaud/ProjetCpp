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
	void GetRadioB(wxCommandEvent &event);
private:
	void OnButton(wxCommandEvent &event) ;
	void OnSlider(wxScrollEvent &event) ;
	void OnCheckBox(wxCommandEvent &event) ;
	wxRadioButton* m_radioNavi ;
	wxRadioButton* m_radioTrait;
	wxRadioButton* m_radioRectangle;
	wxRadioButton* m_radioCercle;
};

#endif