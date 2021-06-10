#include "Delete.h"
#include "Delete.h"
#include "MainForm.h"

System::Void Daily::Delete::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    MainForm^ form = gcnew MainForm();
    this->Hide();
    form->Show();
}

System::Void Daily::Delete::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    MainForm^ form = gcnew MainForm();
    this->Hide();
    form->Show();
}

System::Void Daily::Delete::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if(checkBox1->Checked){
        //MessageBox::Show("true", "info");
        textBox1->Visible = false;
    }
    else {
        //MessageBox::Show("false", "info");
        textBox1->Visible = true;
    }
    return System::Void();
}
