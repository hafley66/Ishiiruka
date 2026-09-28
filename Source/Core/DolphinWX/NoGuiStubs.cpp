// Headless arm64 build: Main.cpp (the wx app) is left out, so the two globals the GUI
// code still links against live here. main_frame stays null; nothing opens a window.
#include "DolphinWX/Frame.h"
#include "DolphinWX/Main.h"

CFrame* main_frame = nullptr;

CFrame* DolphinApp::GetCFrame()
{
	return main_frame;
}

// wxIMPLEMENT_APP in Main.cpp normally defines this; headless there is no wx app instance.
DolphinApp& wxGetApp()
{
	return *static_cast<DolphinApp*>(wxApp::GetInstance());
}
