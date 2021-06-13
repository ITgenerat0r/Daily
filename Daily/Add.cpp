#include "Add.h"
#include "MainForm.h"
//#include <iostream>
#include "function.h"
#include <string>
#include <fstream>



System::Void Daily::Add::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    //std::string date;
    //date = Convert::ToString(numericUpDown3->Value) + "-";
    //date += Convert::ToString(numericUpDown2->Value) + "-";
    //date += Convert::ToString(numericUpDown1->Value);
    std::ofstream file("control.dt");
    std::string ev = "";
    Convert_String_to_string(textBox1->Text, ev);
    //System::String^ text = Convert_string_to_String_r(ev);
    //MessageBox::Show(text, "Info");
    file << "Add " << Convert::ToInt32(numericUpDown3->Value) << "-" << Convert::ToInt32(numericUpDown2->Value) << "-" << Convert::ToInt32(numericUpDown1->Value) << " ";
    file << ev << std::endl;
    
    file.close();
    MainForm^ form = gcnew MainForm();
    this->Hide();
    form->Show();
    this->Close();
}

System::Void Daily::Add::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    MainForm^ form = gcnew MainForm();
    this->Hide();
    form->Show();
    this->Close();
}

System::Void Daily::Add::numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    numericUpDown1->Maximum = CheckDay(Convert::ToInt32(numericUpDown2->Value), Convert::ToInt32(numericUpDown3->Value));
    return System::Void();
}

System::Void Daily::Add::numericUpDown3_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    numericUpDown1->Maximum = CheckDay(Convert::ToInt32(numericUpDown2->Value), Convert::ToInt32(numericUpDown3->Value));
    return System::Void();
}

System::Void Daily::Add::Add_Shown(System::Object^ sender, System::EventArgs^ e)
{
    std::ifstream input("date.dt");
    std::string tmp;
    System::String^ temp;
    // year
    if (input) {
        std::getline(input, tmp);
        temp = Convert_string_to_String_r(tmp);
        numericUpDown3->Value = Convert::ToDecimal(temp);
    }
    // month
    if (input) {
        std::getline(input, tmp);
        temp = Convert_string_to_String_r(tmp);
        numericUpDown2->Value = Convert::ToDecimal(temp);
    }
    // day
    if (input) {
        std::getline(input, tmp);
        temp = Convert_string_to_String_r(tmp);
        numericUpDown1->Value = Convert::ToDecimal(temp);
    }
    input.close();
    return System::Void();
}
