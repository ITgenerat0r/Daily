#include "Add.h"
#include "MainForm.h"
#include <iostream>



System::Void Daily::Add::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::String^ date = textBox1->Text->ToString();
    MainForm^ form = gcnew MainForm();
    this->Hide();
    form->Show();
}

System::Void Daily::Add::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    MainForm^ form = gcnew MainForm();
    this->Hide();
    form->Show();
}
