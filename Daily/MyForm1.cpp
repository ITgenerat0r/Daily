#include "MyForm1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Daily::MyForm form;
	Application::Run(% form); 
}

System::Void Daily::MyForm::‚˚ıÓ‰ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Daily::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Daily::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Daily::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
