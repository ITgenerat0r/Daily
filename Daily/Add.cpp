#include "Add.h"
#include "MainForm.h"
//#include <iostream>
#include "function.h"
#include <string>


System::Void Daily::Add::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string date;
    Convert_String_to_string(textBox1->Text->ToString(), date);
    //System::String^ date = textBox1->Text->ToString();

    MessageBox::Show("Добавлено!", "Info");
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
