#include "pch.h"


//using namespace FtoC;
using namespace System;
using namespace System::Windows::Forms;

	[STAThreadAttribute]
int main(array<System::String ^> ^args)
{

	
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	Application::Run(gcnew Form());
	return 0;
	
}
