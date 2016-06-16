// wxMinimal : wxWindows project sample

#include <wx/wx.h>

class MiniApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MiniApp)

bool MiniApp::OnInit()
{
	wxFrame *frame = new wxFrame(NULL, -1, "Minimal wxWindows");
	SetTopWindow(frame);
	frame->Show(true);
	
	return true;
}
