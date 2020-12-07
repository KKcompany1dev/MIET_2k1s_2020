#include "MyForm.h"

#include <list>
#include <string>

#include "workWithString.h"
#include "ConfigAccess.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;


[STAThread]
void main(array <String^>^ arg) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	KURSA4::MyForm form;
	Application::Run(% form);
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
