#include "MyForm1.h"


using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main2(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	practic::MyForm1 form;
	Application::Run(% form);
}