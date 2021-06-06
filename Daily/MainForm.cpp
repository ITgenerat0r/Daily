//#include "MyForm.h"

#include "MainForm.h"
#include "Add.h"
#include "Delete.h"
#include "Find.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Daily::MainForm form;
	Application::Run(% form); 
}

System::Void Daily::MainForm::âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Daily::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Add^ form = gcnew Add();
	this->Hide();
	form->Show();
}

System::Void Daily::MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	Delete^ form = gcnew Delete();
	this->Hide();
	form->Show();
}

System::Void Daily::MainForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	Find^ form = gcnew Find();
	this->Hide();
	form->Show();
}

System::Void Daily::MainForm::îÏğîãğàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Designed by ITgenerat0r", "Info");
}
