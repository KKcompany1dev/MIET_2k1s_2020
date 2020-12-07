#ifndef WORK_WITH_STRING_H
#define WORK_WITH_STRING_H

#include <string>
#include <list>
#include <msclr\marshal_cppstd.h>

// System::String^ mask_phone(System::String^ phone);
// System::String^ mask_date_deleteTime(System::String^ date);
System::String^ makeQueryFromList(const std::list<std::wstring>& fields_values, const std::list<std::wstring>& fields_types);
System::String^ makeQueryUpdateFromSystemString(const std::list<std::wstring>& fields_values, System::String^ str);

std::string convertSystemStringToStdString(System::String^ str);
std::wstring convertSystemStringToWString(System::String^ str);

bool wstringStartWith(const std::wstring& str1, const std::wstring& str2);

#endif // !WORK_WITH_STRING_H

