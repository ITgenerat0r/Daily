#pragma once

#include "Dt.h"

using namespace System;




std::string& Convert_String_to_string(String^ s, std::string& os); // конвертируем System::string^ в std::string
String^ Convert_string_to_String(std::string& os, String^ s); // конвертируем std::string в System::string^
std::string& Convert_String_to_string_r(String^ s); // конвертируем System::string^ в std::string
String^ Convert_string_to_String_r(std::string& os); // конвертируем std::string в System::string^
System::String^ Convert_char_to_String(char ch); // конвертируем char в System::string^
char* Convert_String_to_char(System::String^ string); // конвертируем System::string^ в char*
System::String^ Convert_char_to_String(char* ch); // конвертируем char* в System::string^

void control(Database& db);
int CheckDay(int m, int y);