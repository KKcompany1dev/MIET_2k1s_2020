#include "MyForm.h"

#include <list>
#include <string>

#include "workWithString.h"
#include "ConfigAccess.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

// Глобальные переменные
std::list<std::wstring> listboxCollection;		// Для сортировки
int rows = 0;									// Для корректного изменения dataGridView

[STAThread]
void main(array <String^>^ arg) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	KURSA4::MyForm form;
	Application::Run(% form);
}

// Инициализация

System::Void KURSA4::MyForm::initListBox_selectSort()
{
	fillListFromConfigFile(listboxCollection, L"Data/Configuration/access.cfg", L"[Поля]");

	for (auto str : listboxCollection)
	{
		listBox_selectSort->Items->Add(gcnew String(str.c_str()));
	}

	return System::Void();
}


// События ////////////////////////////////////

// Загрузка БД
System::Void KURSA4::MyForm::button_download_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ query = "SELECT * FROM [Клиенты]";
	String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Клиенты.accdb";

	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();

	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

	if (dbReader->HasRows == false) 
	{
		MessageBox::Show("Невозможно загрузить таблицу!", "Внимание!");
	}
	else
	{
		// Заполняем информацию о полях (кол-во и названия)
		std::list<std::wstring> data;
		fillListFromConfigFile(data, L"Data/Configuration/access.cfg", L"[Поля]");

		while (dbReader->Read())
		{
			// Делаем массив запросов dbReader для datagridview
			array<System::Object^>^ dbReaderRequest;
			Array::Resize(dbReaderRequest, data.size());

			// Сохраняем данные в dbReaderRequest
			int i = 0;
			for (auto el : data)	dbReaderRequest[i++] = dbReader[gcnew System::String(el.c_str())];

			dataGridView_mainSheet->Rows->Add();
			dataGridView_mainSheet->Rows->Insert(0, dbReaderRequest);
			rows++;
		}
	}

	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

// Добавление нового клиента в БД
System::Void KURSA4::MyForm::button_add_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Нужно выбрать строку
	if (dataGridView_mainSheet->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите строку для добавления","Внимание!");
		return System::Void();
	}

	// Выбранная строка
	int index = dataGridView_mainSheet->SelectedRows[0]->Index;

	// Проверка на ввод данных в строке
	std::list<std::wstring> data;
	fillListFromConfigFile(data, L"Data/Configuration/access.cfg", L"[Поля]");
	for (size_t i = 0; i < data.size(); i++)
		if (dataGridView_mainSheet->Rows[index]->Cells[i]->Value == nullptr)
		{
			MessageBox::Show("Введите все данные!", "Внмиание!");
			return System::Void();
		}

	// Считывание данных
	array<String^>^ cols;
	System::Array::Resize(cols, data.size());
	for (size_t i = 0; i < cols->Length; i++) cols[i] = dataGridView_mainSheet->Rows[index]->Cells[i]->Value->ToString();	

	// Устанавливаем соединение
	String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Клиенты.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();

	// Формируем запрос
	std::list<std::wstring> types;
	fillListFromConfigFile(types, L"Data/Configuration/access.cfg", L"[Типы полей]");

	// Переводим String cols в wstring cols
	std::list<std::wstring> wcols;
	for (size_t i = 0; i < cols->Length; i++) wcols.push_back(convertSystemStringToWString(cols[i]));

	String^ temp = makeQueryFromList(wcols, types);
	String^ query = "INSERT INTO [Клиенты] VALUES (" + temp +  ")";
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);


	if (dbCommand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	}
	else
	{
		MessageBox::Show("Готово! Данные добавлены!", "Готов!");
	}

	dbConnection->Close();
	return System::Void();
}

// Изменить данные (Обновить)
System::Void KURSA4::MyForm::button_update_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Нужно выбрать строку
	if (dataGridView_mainSheet->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите строку для добавления", "Внимание!");
		return System::Void();
	}

	// Выбранная строка
	int index = dataGridView_mainSheet->SelectedRows[0]->Index;

	// Проверка на ввод данных в строке
	std::list<std::wstring> data;
	fillListFromConfigFile(data, L"Data/Configuration/access.cfg", L"[Поля]");
	for (size_t i = 0; i < data.size(); i++)
		if (dataGridView_mainSheet->Rows[index]->Cells[i]->Value == nullptr)
		{
			MessageBox::Show("Введите все данные!", "Внмиание!");
			return System::Void();
		}

	// Считывание данных
	array<String^>^ cols;
	System::Array::Resize(cols, data.size());
	for (size_t i = 0; i < cols->Length; i++) cols[i] = dataGridView_mainSheet->Rows[index]->Cells[i]->Value->ToString();

	// Устанавливаем соединение
	String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Клиенты.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();

	// Формируем запрос
	std::list<std::wstring> types;
	fillListFromConfigFile(types, L"Data/Configuration/access.cfg", L"[Типы полей]");

	// Переводим String cols в wstring cols
	std::list<std::wstring> wcols;
	for (size_t i = 0; i < cols->Length; i++) wcols.push_back(convertSystemStringToWString(cols[i]));

	String^ temp = makeQueryFromList(wcols, types);
	temp = makeQueryUpdateFromSystemString(data, temp);
	String^ query = "UPDATE [Клиенты] SET " + temp;
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

	if (dbCommand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	}
	else
	{
		MessageBox::Show("Готово! Данные изменены!", "Готов!");
	}

	dbConnection->Close();
	return System::Void();
}

// Удалить данные из БД
System::Void KURSA4::MyForm::button_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Нужно выбрать строку
	if (dataGridView_mainSheet->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите строку для добавления", "Внимание!");
		return System::Void();
	}

	// Выбранная строка
	int index = dataGridView_mainSheet->SelectedRows[0]->Index;

	// Считывание данных
	String^ id = dataGridView_mainSheet->Rows[index]->Cells[0]->Value->ToString();

	// Устанавливаем соединение
	String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Клиенты.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();

	// Формируем запрос
	std::list<std::wstring> data;
	fillListFromConfigFile(data, L"Data/Configuration/access.cfg", L"[Поля]");
	String^ id_field;
	for (auto el : data) {
		id_field = gcnew String(el.c_str());
		break;
	}

	String^ query = "DELETE FROM [Клиенты] WHERE " + id_field + " = " + id;
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

	if (dbCommand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	}
	else
	{
		MessageBox::Show("Готово! Данные удалены!", "Готов!");
	}

	dbConnection->Close();
	return System::Void();
}

// Сортировка
System::Void KURSA4::MyForm::button_sort_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ query = listBox_selectSort->GetItemText(listBox_selectSort->SelectedItem);
	listBox_selectSort->ClearSelected();

	if (query != "")
	{
		////////// 1 ЭТАП ////////////////////////////////////////////////
		////////// Подготовка СД для сортировки //////////////////////////

		// Сохраняем данные в промежуточную СД
		std::list<std::wstring> temp;	fillListFromConfigFile(temp, L"Data/Configuration/access.cfg", L"[Поля]");
		std::list<std::wstring> types;	fillListFromConfigFile(types, L"Data/Configuration/access.cfg", L"[Типы полей]");


		int ROWS = rows, COLS = temp.size();
		array<String^, 2>^ data = gcnew array<String^, 2 >(ROWS, COLS);
		for (size_t i = 0; i < ROWS; i++)
		{
			for (size_t j = 0; j < COLS; j++)
			{
				data[i, j] = dataGridView_mainSheet->Rows[i]->Cells[j]->Value->ToString();
			}
		}
		

		// Получаем индекс столбца для сортировки
		int index = 0;
		for (auto str : temp)
		{
			if (query == gcnew String(str.c_str()))	break;
			index++;
		}

		// Хранит ли столбец числовой тип данных
		bool isNumber; int counter = 0;
		for (auto str : types)
		{
			if (counter++ == index)
			{
				if (str == L"Число") isNumber = true;
				else isNumber = false;
				break;
			}
		}


		////////// 2 ЭТАП ////////////////////////////////////////////////
		////////// Сортировка ///////////////////////////////////////////

		// Сортируем по столбцу
		if (!isNumber)	// Сортировка по строке
		{
			String^ t;
			for (size_t i = 0; i < ROWS - 1; i++)
			{
				for (size_t j = i + 1; j < ROWS; j++)
				{
					std::string t1 = convertSystemStringToStdString(data[i, index]->ToString());
					std::string t2 = convertSystemStringToStdString(data[j, index]->ToString());
					if (t1 < t2)
					{
						for (size_t k = 0; k < COLS; k++)
						{
							t = data[j, k];
							data[j, k] = data[i, k];
							data[i, k] = t;
						}
					}

				}
			}
		}
		else	// Сортировка по числу
		{
			String^ t;
			for (size_t i = 0; i < ROWS - 1; i++)
			{
				for (size_t j = i + 1; j < ROWS; j++)
				{
					int t1 = Int32::Parse(data[i, index]);
					int t2 = Int32::Parse(data[j, index]);
					if (t1 < t2)
					{
						for (size_t k = 0; k < COLS; k++)
						{
							t = data[j, k];
							data[j, k] = data[i, k];
							data[i, k] = t;
						}
					}

				}
			}
		}


		////////// 3 ЭТАП ////////////////////////////////////////////////
		////////// Перезапись dataGridView ///////////////////////////////


		// Перезапись dataGridView
		this->dataGridView_mainSheet->Rows->Clear();

		array<System::Object^>^ writerRequest;
		Array::Resize(writerRequest, temp.size());

		for (size_t i = 0; i < ROWS; i++)
		{
			for (size_t j = 0; j < COLS; j++)
			{
				writerRequest[j] = data[i, j];
			}
			dataGridView_mainSheet->Rows->Add();
			dataGridView_mainSheet->Rows->Insert(0, writerRequest);
		}
	}
	else
	{
		MessageBox::Show("Выберете поле сортировки!","Внимание!");
		return System::Void();
	}

	return System::Void();
}

// Ввод для сортировки по:

System::Void KURSA4::MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	listBox_selectSort->Items->Clear();
	if (textBox1->Text != L"")
	{
		int k = 0;
		for (auto str : listboxCollection)
		{
			if (wstringStartWith(str, convertSystemStringToWString(textBox1->Text)))
			{
				listBox_selectSort->Items->Add(gcnew String(str.c_str()));
				k++;
			}
		}
		if (k = 0) listBox_selectSort->Items->Add(" "); // Чтобы не крашилось
	}
	else
	{
		for (auto str : listboxCollection)
		{
			listBox_selectSort->Items->Add(gcnew String(str.c_str()));
		}
	}
	return System::Void();
}
