using namespace std ;
#ifndef __MyFrame_h__
#define __MyFrame_h__

#include "include.hpp"
#include "MyControlPanel.hpp"
#include "MyDrawingPanel.hpp"

//------------------------------------------------------------------------
class MyFrame: public wxFrame
//------------------------------------------------------------------------
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	MyControlPanel* GetControlPanel(){return m_controlPanel ;} ;
	MyDrawingPanel* GetDrawingPanel(){return m_drawingPanel ;} ;
	void RefreshDrawing(){m_drawingPanel->Refresh() ;} ;

protected:
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnOpenFile(wxCommandEvent& WXUNUSED(event) ) ;
	void OnSaveFile(wxCommandEvent & WXUNUSED(event)) ;
	void OnClose(wxCloseEvent& event) ;
	void OnSize(wxSizeEvent &event) ;

	MyControlPanel *m_controlPanel; // the panel with controls
	MyDrawingPanel *m_drawingPanel; // the panel in which we draw
} ;

#endif