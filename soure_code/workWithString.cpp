#include "workWithString.h"

/// String^ mask_phone(String^ phone)
/// Переводит номер телефона в более красивый вид
/// +7(900)-000-00-00
/// Там где 0 - получаемая строка. Например 999999999 -> +7(999)-999-99-99
// System::String^ mask_phone(System::String^ phone)
// {
// 	System::String^ res = "+7(9" + phone[0] + phone[1] + ")-"
// 		+ phone[2] + phone[3] + phone[4]+ "-"
// 		+ phone[5] + phone[6] + "-"
// 		+ phone[7] + phone[8];
// 	return res;
// }


// String^ mask_date_deleteTime(String^ date)
// удаляет время после даты
// ДД.ММ.ГГГГ вместо ДД.ММ.ГГГГ ЧЧ:ММ
// Отрезает кусок после пробела
// System::String^ mask_date_deleteTime(System::String^ date)
// {
// 	System::String^ res = "";
// 	int i = 0;
// 	while (date[i].ToString() != " ")
// 	{
// 		res += date[i++];
// 	}
// 	return res;
// }

System::String^ makeQueryFromList(const std::list<std::wstring>& fields_values, const std::list<std::wstring>& fields_types)
{
	System::String^ res;
	std::wstring temp;
	
	// Подготовка массива "Строка или число"
	array<bool>^ isNumber;
	isNumber->Resize(isNumber, fields_types.size());

	int i = 0;
	for (auto it : fields_types)
		if (it == L"Строка")  isNumber[i++] = false;
		else isNumber[i++] = true;


	// Формирование запроса wstring
	i = 0;
	for (auto it : fields_values)
	{
		// Число
		if (isNumber[i++] == true)
		{
			temp += it + L", ";
		}

		// Строка
		else
		{
			temp += L"'" + it + L"', ";
		}
	}

	// Перенос в System::String^
	for (size_t i = 0; i < temp.size() - 2; i++)
		res += temp[i];

	return res;
}

System::String^ makeQueryUpdateFromSystemString(const std::list<std::wstring>& fields_values, System::String^ str)
{
	System::String^ res;
	std::wstring temp;

	// Спарсим строку str чтобы потом можно было удобно формировать запрос
	array<System::String^>^ pars;
	pars->Resize(pars, fields_values.size() - 1);	// -1 т.к. id не нужен в начале запроса, он нужен после WHERE id = id
	int count = 0;
	int k = 0;
	for (size_t i = 0; i < str->Length; i++)
	{
		if (str[i].ToString() == L" " && !count++)
		{
			temp = L"";
			continue;
		}

		if (str[i].ToString() == L" ")	// Элемент готов
		{
			pars[k++] = gcnew System::String(temp.c_str()) + L" ";
			temp = L"";
		}
		else	// Собираем элемент
		{
			temp += str[i];
		}
	}
	// Последний элемент
	pars[k++] = gcnew System::String(temp.c_str());


	// Формируем запрос
	temp = L""; k = 0;
	bool isFirst = false;
	for (auto it : fields_values) 
	{
		if (!isFirst) { isFirst = true; continue; }
		temp += it + L"=" + convertSystemStringToWString(pars[k++]);
	}

	// Дописываем WHERE id = id, при условии что id - всегда первое поле
	k = 0;

	System::String^ id;
	for (size_t i = 0; i < str->Length; i++)
	{
		if (str[i].ToString() == L",")	// Элемент готов
		{
			break;
		}
		else	// Собираем элемент
		{
			id += str[i];
		}
	}

	for (auto it : fields_values) {
		if (!k++)
			temp += L" WHERE " + it + L" = " + convertSystemStringToWString(id);
		else break;
	}

	res = gcnew System::String(temp.c_str());
	return res;
}


// Конвертирует System::String^ в std::string
std::string convertSystemStringToStdString(System::String^ str)
{
	return msclr::interop::marshal_as<std::string>(str);
}

// Конвертирует System::String^ в std::wstring
std::wstring convertSystemStringToWString(System::String^ str)
{
	return msclr::interop::marshal_as<std::wstring>(str);
}

// Строка является началом другой строки
bool wstringStartWith(const std::wstring& str1, const std::wstring& str2)
{
	for (size_t i = 0; i < str2.size(); i++)
		if (str1[i] == str2[i]);
		else return false;
	return true;
}
