#include "Find.h"
#include "MainForm.h"
#include <fstream>
#include <string>
#include "function.h""

System::Void Daily::Find::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::ofstream file("control.dt");
    //System::String^ text = Convert_string_to_String_r(ev);
    //MessageBox::Show(text, "Info");
    file << "Find " << Convert::ToInt32(numericUpDown3->Value) << "-" << Convert::ToInt32(numericUpDown2->Value) << "-" << Convert::ToInt32(numericUpDown1->Value) << std::endl;

    MainForm^ form = gcnew MainForm();
    this->Hide();
    form->Show();
}

System::Void Daily::Find::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    MainForm^ form = gcnew MainForm();
    this->Hide();
    form->Show();
}

System::Void Daily::Find::Find_Shown(System::Object^ sender, System::EventArgs^ e)
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
    return System::Void();
}
