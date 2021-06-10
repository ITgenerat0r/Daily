#include "MainForm.h"
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

System::Void Daily::MainForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("�� ������������� ������ �����?","��������!", MessageBoxButtons::YesNo) != System::Windows::Forms::DialogResult::No) {
		Application::Exit();
	}
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

System::Void Daily::MainForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Designed by ITgenerat0r", "Info");
}

System::Void Daily::MainForm::MainForm_Shown(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();

	Header();

	dataGridView1->RowCount = 5 + 1;
	dataGridView1->ColumnCount = 2;

	Show();

	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();


	return System::Void();
}

void Daily::MainForm::Header()
{
	DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
	c1->Name = "Date";
	c1->HeaderText = "����";
	c1->Width = 300;
	dataGridView1->Columns->Add(c1);

	DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
	c2->Name = "Events";
	c2->HeaderText = "�������";
	c2->Width = 700;
	dataGridView1->Columns->Add(c2);

	dataGridView1->TopLeftHeaderCell->Value = "������"; // Table name
	dataGridView1->AutoResizeColumns(); // ������������ ��������
}

void Daily::MainForm::Show()
{
	for (int i = 0; i < dataGridView1->RowCount - 1; i++) {
		dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);


	}
}
