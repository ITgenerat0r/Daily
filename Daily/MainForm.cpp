
#include "MainForm.h"
#include "Add.h"
#include "Delete.h"
#include "Find.h"
#include <iomanip>
//#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

Database db;



[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Daily::MainForm form;
	Application::Run(% form); 
}

System::Void Daily::MainForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Сохранить данные в файл перев выходом?","Внимание!", MessageBoxButtons::YesNo) != System::Windows::Forms::DialogResult::No) {
		db.Save();
	}
	Application::Exit();
}

System::Void Daily::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	DateTime dtTmp = DateTime::Now;
	std::ofstream os("date.dt");
	std::string tmp;
	Convert_String_to_string(dtTmp.Year.ToString(), tmp);
	os << tmp << std::endl;
	Convert_String_to_string(dtTmp.Month.ToString(), tmp);
	os << tmp << std::endl;
	Convert_String_to_string(dtTmp.Day.ToString(), tmp);
	os << tmp << std::endl;
	//os << Convert_String_to_string_r(dtTmp.Month.ToString()) << std::endl;
	//os << Convert_String_to_string_r(dtTmp.Day.ToString()) << std::endl;
	os.close();
	Add^ form = gcnew Add();
	this->Hide();
	form->Show();
}

System::Void Daily::MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->RowCount<2) { 
		return System::Void();
	}
	int num = dataGridView1->CurrentCell->RowIndex;
	if (num+1 >= dataGridView1->RowCount) {
		return System::Void();
	}
	System::String ^ text1, ^ text2;
	std::string dt_black, dt_white, ev, y, m, d;
	text1 = dataGridView1->Rows[num]->Cells[0]->Value->ToString();
	text2 = dataGridView1->Rows[num]->Cells[1]->Value->ToString();
	Convert_String_to_string(text1, dt_black);
	Convert_String_to_string(text2, ev);
	Date date;
	std::stringstream si(dt_black);
	std::stringstream so("");
	getline(si, d, '.');
	getline(si, m, '.');
	getline(si, y);
	so << y << '-' << m << '-' << d;
	so >> dt_white;
	if (date.setDatefromString(dt_white)) {
		if (MessageBox::Show("Удалить все события за выбранную дату?", "Внимание!", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::No) {
			db.DeleteEvent(date, ev);
		}
		else {
			db.DeleteDate(date);
		}
	}
	else {
		return System::Void();
	}

	dataGridView1->ReadOnly = true;
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();

	Header();

	dataGridView1->RowCount = db.Size() + 1;
	dataGridView1->ColumnCount = 2;

	Show(db);

	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();
	
	return System::Void();
}

System::Void Daily::MainForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (db.Size() == 0) {
		MessageBox::Show("Нет никаких событий!", "Информация");
		return System::Void();
	}
	
	DateTime dtTmp = DateTime::Now;
	std::ofstream os("date.dt");
	std::string tmp;
	Convert_String_to_string(dtTmp.Year.ToString(), tmp);
	os << tmp << std::endl;
	Convert_String_to_string(dtTmp.Month.ToString(), tmp);
	os << tmp << std::endl;
	Convert_String_to_string(dtTmp.Day.ToString(), tmp);
	os << tmp << std::endl;
	//os << Convert_String_to_string_r(dtTmp.Month.ToString()) << std::endl;
	//os << Convert_String_to_string_r(dtTmp.Day.ToString()) << std::endl;
	os.close();
	Find^ form = gcnew Find();
	this->Hide();
	form->Show();
}

System::Void Daily::MainForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Designed by ITgenerat0r", "Info");
}

System::Void Daily::MainForm::MainForm_Shown(System::Object^ sender, System::EventArgs^ e)
{
	Database print;
	print = control(db);
	// clear control.dt
	std::ofstream of("control.dt");
	of.close();

	dataGridView1->ReadOnly = true;
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();

	Header();
	if (print.Size() == 0) {

		dataGridView1->RowCount = db.Size() + 1;
		dataGridView1->ColumnCount = 2;

		Show(db);
	}
	else {
		dataGridView1->RowCount = print.Size() + 1;
		dataGridView1->ColumnCount = 2;

		Show(print);
	}

	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();

	timer1->Start();

	return System::Void();
}

void Daily::MainForm::Header()
{
	DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
	c1->Name = "Date";
	c1->HeaderText = "Дата";
	c1->Width = 300;
	dataGridView1->Columns->Add(c1);

	DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
	c2->Name = "Events";
	c2->HeaderText = "События";
	c2->Width = dataGridView1->Width - 300;
	dataGridView1->Columns->Add(c2);

	dataGridView1->TopLeftHeaderCell->Value = "Данные"; // Table name
	dataGridView1->AutoResizeColumns(); // Выравнивание столбцов
}

void Daily::MainForm::Show(Database& d)
{
	int i = 0;
	for (const auto& k : d.Print()) {
		Date dd = k.first;
		std::string first = dd.Out(".");
		for (const std::string& event : k.second) {
			//cout << k.first << " " << event << endl;
			dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			dataGridView1->Rows[i]->Cells[0]->Value = Convert_string_to_String_r(first);
			System::String^ text;
			std::string ee = event;
			Convert_string_to_String(ee, text);
			//MessageBox::Show(text, "info");
			dataGridView1->Rows[i]->Cells[1]->Value = Convert_string_to_String_r(ee);
			i++;
		}
	}
	
}

System::Void Daily::MainForm::сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	db.Save();
	return System::Void();
}

System::Void Daily::MainForm::загрузитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	db.Load();
	// MessageBox::Show(Convert::ToString(db.Size()), "info");
	dataGridView1->ReadOnly = true;
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();

	Header();

	dataGridView1->RowCount = db.Size() + 1;
	dataGridView1->ColumnCount = 2;

	Show(db);

	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();

	return System::Void();
}

System::Void Daily::MainForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	DateTime dtTmp = DateTime::Now;
	std::stringstream time("");
	System::String^ text;
	std::string tmp;

	// time
	time << std::setw(2) << std::setfill('0') << dtTmp.Hour << ':';
	time << std::setw(2) << std::setfill('0') << dtTmp.Minute << ':';
	time << std::setw(2) << std::setfill('0') << dtTmp.Second;
	time >> tmp;
	text = Convert_string_to_String_r(tmp);
	labelTime->Text = text;
	// date
	time.clear();
	time << std::setw(2) << std::setfill('0') << dtTmp.Day << '.';
	time << std::setw(2) << std::setfill('0') << dtTmp.Month << '.';
	time << std::setw(4) << std::setfill('0') << dtTmp.Year;
	time >> tmp;
	text = Convert_string_to_String_r(tmp);
	labelDate->Text = text;
}

System::Void Daily::MainForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string tmp;
	std::stringstream ss("");
	ss << db.Size();
	ss >> tmp;
	MessageBox::Show(Convert_string_to_String_r(tmp), "Debug");
	return System::Void();
}
