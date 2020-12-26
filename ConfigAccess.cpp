#include "ConfigAccess.h"
#include "workWithString.h"

void fillListFromConfigFile(std::list<std::wstring>& list, std::wstring filePath, std::wstring query)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Для чтения кириллицы wide юзаем
	std::wifstream ifs(filePath);
	ifs.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

	const std::wstring KEY1 = L"[Таблица]";			// Для поиска названия таблица только под данной записью
	const std::wstring KEY2 = L"[Поля]";			// Для поиска названий полей только под данной записью
	const std::wstring KEY3 = L"[Типы полей]";		// Для поиска названий полей только под данной записью

	// Проверка на запрос query
	if (!(query == KEY1 || query == KEY2 || query == KEY3))
	{
		std::cout << "Ошибка! Неправильно указано название секции файла конфигурации!\n";
		return;
	}

	// Проверка на открытие файла конфигурации
	if (!ifs.is_open())
	{
		System::Console::WriteLine(L"Ошибка открытия файла конфигурации!\n");
	}
	else
	{
		std::wstring temp;
		bool isReachedSection = false;

		// Ищем секцию с текущим query
		while (!ifs.eof()) 
		{
			std::getline(ifs, temp);
		
			// Внутри секции
			if (isReachedSection)
			{
				if (temp != L"")
					list.push_back(temp);
				else
					break;
			}
		
			// Дошли до секции => то что нам нужно
			if (temp == query) isReachedSection = true;
		}
	}

	ifs.close();
}
