//#include <iostream>
//#include <sstream>
#include <string>
#include <fstream>
//#include <map>
#include <set>
//#include <iomanip>
//#include <algorithm>

#include "function.h"


// using namespace std;


// конвертируем System::string^ в std::string
std::string& Convert_String_to_string(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
};

// конвертируем std::string в System::string^
String^ Convert_string_to_String(std::string& os, String^ s) {
	s = gcnew System::String(os.c_str());
	return s;
};

// конвертируем System::string^ в std::string
std::string& Convert_String_to_string_r(String^ s) {
	std::string os;
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
};

// конвертируем std::string в System::string^
String^ Convert_string_to_String_r(std::string& os) {
	System::String^ s = gcnew String(os.c_str());

	return s;
};

// конвертируем char* в System::string^
System::String^ Convert_char_to_String(char ch) {
	char* chr = new char();
	chr[0] = ch;
	System::String^ str;
	for (int i = 0; chr[i] != '\0'; i++) {
		str += wchar_t(ch);
	}
	return str;
};

// конвертируем System::string^ в char*
char* Convert_String_to_char(System::String^ string) {
	using namespace System::Runtime::InteropServices;
	return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
};

// конвертируем char* в System::string^
System::String^ Convert_char_to_String(char* ch) {
	char* chr = new char();
	chr = ch;
	System::String^ str;
	for (int i = 0; chr[i] != '\0'; i++) {
		str += wchar_t(ch[i]);
	}
	return str;
};











Database control(Database& db) {
	std::ifstream file("control.dt");
	std::string command;
	Database pr;
	while (std::getline(file, command)) {
		// Считайте команды с потока ввода и обработайте каждую
		std::string cm;
		std::stringstream input(command);
		input >> cm;
		if (cm == "Add") {
			std::string dt, ev;
			input >> dt >> ev;
			while (input) {
				std::string tmp;
				input >> tmp;
				ev += " " + tmp;
			}
			Date date;
			if (date.setDatefromString(dt)) {
				db.AddEvent(date, ev);
				// System::Windows::Forms::MessageBox::Show("Событие добавлено!", "Info");
			}
			else {
				System::Windows::Forms::MessageBox::Show("Something went wrong!", "Error");
				file.close();
				return pr;
			}
			// cout << "Command: " << cm << "   Date: " << dt << "   Event: " << ev << endl;
		}
		else if (cm == "Del") {
			std::string dt, ev = "";
			input >> dt;
			Date date;
			if (date.setDatefromString(dt)) {
				if (input.peek() > -1) {
					// cout << "'" << input.peek() << "'" << endl;
					input >> ev;
					setlocale(LC_ALL, "Rus");
					if (db.DeleteEvent(date, ev)) {
						//cout << "Deleted successfully\n";
						System::Windows::Forms::MessageBox::Show("Deleted successfully!", "Info");
					}
					else {
						//cout << "Event not found\n";

					}
				}
				else {
					std::string text = "Deleted ";
					System::String^ msg = Convert_string_to_String_r(text) + Convert::ToString(db.DeleteDate(date));
					text = " successfuly!";
					msg += Convert_string_to_String_r(text);

					System::Windows::Forms::MessageBox::Show(msg, "Info");
				}
			}
			else {
				file.close();
				return pr;
			}
			// cout << "Command: " << cm << "   Date: " << dt << "   Event: " << ev << endl;
		}
		else if (cm == "Find") {
			std::string dt;
			input >> dt;
			Date date;
			if (date.setDatefromString(dt)) {
				std::set<std::string> tmp;
				tmp = db.Find(date);
				if (tmp.size()) {
					for (const auto& i : tmp) {
						pr.AddEvent(date, i);
					}
					file.close();
					return pr;
				}
			}
			else {
				file.close();
				return pr;
			}
			// cout << "Command: " << cm << "   Date: " << dt << endl;
			// cout << ValidDate(dt) << endl;
		}
		else if (cm == "Print") {
			//db.Print();
			// cout << "Command: " << cm << endl;
		}
		else if (cm != "") {
			//cout << "Unknown command: " << cm << std::endl;
			file.close();
			return pr;
		}
	}
	file.close();
	return	pr;
}



int CheckDay(int m, int y) {
	std::set<int> mm = {1, 3, 5, 7, 8, 10, 12};
	if (mm.count(m)) {
		return 31;
	}
	if (m == 2) {
		if (y % 4 == 0) {
			return 29;
		}
		return 28;
	}
	return 30;

}