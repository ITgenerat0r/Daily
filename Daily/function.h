#pragma once

#include "Dt.h"

using namespace System;




std::string& Convert_String_to_string(String^ s, std::string& os); // ������������ System::string^ � std::string
String^ Convert_string_to_String(std::string& os, String^ s); // ������������ std::string � System::string^
std::string& Convert_String_to_string_r(String^ s); // ������������ System::string^ � std::string
String^ Convert_string_to_String_r(std::string& os); // ������������ std::string � System::string^
System::String^ Convert_char_to_String(char ch); // ������������ char � System::string^
char* Convert_String_to_char(System::String^ string); // ������������ System::string^ � char*
System::String^ Convert_char_to_String(char* ch); // ������������ char* � System::string^

void control(Database& db);
int CheckDay(int m, int y);