using namespace std ;
#include <iostream>
#include <cstdlib>

#include "constants.hpp"
#include "ID.hpp"
#include "MyApp.hpp"
#include "MyFrame.hpp"

IMPLEMENT_APP(MyApp) // macro that contains the main() function

//------------------------------------------------------------------------
bool MyApp::OnInit()
//------------------------------------------------------------------------
{
	MyFrame *frame = new MyFrame(wxT(APP_NAME), wxDefaultPosition, wxSize(APPLICATION_WIDTH,APPLICATION_HEIGHT)) ;
	frame->Show(true) ;
	SetTopWindow(frame) ;
	return true ;
}