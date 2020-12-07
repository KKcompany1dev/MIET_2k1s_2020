#include "ConfigAccess.h"
#include "workWithString.h"

void fillListFromConfigFile(std::list<std::wstring>& list, std::wstring filePath, std::wstring query)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ��� ������ ��������� wide �����
	std::wifstream ifs(filePath);
	ifs.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

	const std::wstring KEY1 = L"[�������]";			// ��� ������ �������� ������� ������ ��� ������ �������
	const std::wstring KEY2 = L"[����]";			// ��� ������ �������� ����� ������ ��� ������ �������
	const std::wstring KEY3 = L"[���� �����]";		// ��� ������ �������� ����� ������ ��� ������ �������

	// �������� �� ������ query
	if (!(query == KEY1 || query == KEY2 || query == KEY3))
	{
		std::cout << "������! ����������� ������� �������� ������ ����� ������������!\n";
		return;
	}

	// �������� �� �������� ����� ������������
	if (!ifs.is_open())
	{
		System::Console::WriteLine(L"������ �������� ����� ������������!\n");
	}
	else
	{
		std::wstring temp;
		bool isReachedSection = false;

		// ���� ������ � ������� query
		while (!ifs.eof()) 
		{
			std::getline(ifs, temp);
		
			// ������ ������
			if (isReachedSection)
			{
				if (temp != L"")
					list.push_back(temp);
				else
					break;
			}
		
			// ����� �� ������ => �� ��� ��� �����
			if (temp == query) isReachedSection = true;
		}
	}

	ifs.close();
}
