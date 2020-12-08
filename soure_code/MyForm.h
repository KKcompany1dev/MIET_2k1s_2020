#pragma once

namespace KURSA4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->initListBox_selectSort();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ загрузитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сохранитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView_mainSheet;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_download;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Button^ button_update;
	private: System::Windows::Forms::Button^ button_add;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::ListBox^ listBox_selectSort;
	private: System::Windows::Forms::Button^ button_sort;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox_update;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientFullName_1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientFullName_2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientFullName_3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ contractID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ contactData;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientEmail;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientAdress;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientInteractionNumber;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_amountOfRequests;

	private: System::Windows::Forms::PictureBox^ pictureBox_findAmountOfRequests;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ button_findAdress;
	private: System::Windows::Forms::TextBox^ textBox_findAdress;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Button^ button_findConractDate;
	private: System::Windows::Forms::TextBox^ textBox_findContractDate;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->загрузитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView_mainSheet = (gcnew System::Windows::Forms::DataGridView());
			this->clientID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientFullName_1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientFullName_2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientFullName_3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contractID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contactData = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientEmail = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientAdress = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientInteractionNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_download = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button_sort = (gcnew System::Windows::Forms::Button());
			this->listBox_selectSort = (gcnew System::Windows::Forms::ListBox());
			this->pictureBox_update = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_amountOfRequests = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox_findAmountOfRequests = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button_findAdress = (gcnew System::Windows::Forms::Button());
			this->textBox_findAdress = (gcnew System::Windows::Forms::TextBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->button_findConractDate = (gcnew System::Windows::Forms::Button());
			this->textBox_findContractDate = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_mainSheet))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_update))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_findAmountOfRequests))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->файлToolStripMenuItem,
					this->справкаToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1322, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->загрузитьToolStripMenuItem,
					this->сохранитьToolStripMenuItem, this->выходToolStripMenuItem
			});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// загрузитьToolStripMenuItem
			// 
			this->загрузитьToolStripMenuItem->Name = L"загрузитьToolStripMenuItem";
			this->загрузитьToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->загрузитьToolStripMenuItem->Text = L"Загрузить";
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->сохранитьToolStripMenuItem->Text = L"Сохранить";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->выходToolStripMenuItem->Text = L"Выход";
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->справкаToolStripMenuItem->Text = L"Справка";
			// 
			// dataGridView_mainSheet
			// 
			this->dataGridView_mainSheet->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_mainSheet->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->clientID,
					this->clientFullName_1, this->clientFullName_2, this->clientFullName_3, this->contractID, this->contactData, this->clientEmail,
					this->clientAdress, this->clientInteractionNumber
			});
			this->dataGridView_mainSheet->Location = System::Drawing::Point(183, 57);
			this->dataGridView_mainSheet->Name = L"dataGridView_mainSheet";
			this->dataGridView_mainSheet->Size = System::Drawing::Size(1118, 551);
			this->dataGridView_mainSheet->TabIndex = 1;
			// 
			// clientID
			// 
			this->clientID->HeaderText = L"ID клиента";
			this->clientID->Name = L"clientID";
			// 
			// clientFullName_1
			// 
			this->clientFullName_1->HeaderText = L"Фамилия";
			this->clientFullName_1->Name = L"clientFullName_1";
			this->clientFullName_1->Width = 150;
			// 
			// clientFullName_2
			// 
			this->clientFullName_2->HeaderText = L"Имя";
			this->clientFullName_2->Name = L"clientFullName_2";
			this->clientFullName_2->Width = 150;
			// 
			// clientFullName_3
			// 
			this->clientFullName_3->HeaderText = L"Отчество";
			this->clientFullName_3->Name = L"clientFullName_3";
			this->clientFullName_3->Width = 150;
			// 
			// contractID
			// 
			this->contractID->HeaderText = L"ID договора";
			this->contractID->Name = L"contractID";
			// 
			// contactData
			// 
			this->contactData->HeaderText = L"Сроки договора";
			this->contactData->Name = L"contactData";
			// 
			// clientEmail
			// 
			this->clientEmail->HeaderText = L"Почта";
			this->clientEmail->Name = L"clientEmail";
			// 
			// clientAdress
			// 
			this->clientAdress->HeaderText = L"Адрес";
			this->clientAdress->Name = L"clientAdress";
			// 
			// clientInteractionNumber
			// 
			this->clientInteractionNumber->HeaderText = L"Кол-во обращений";
			this->clientInteractionNumber->Name = L"clientInteractionNumber";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_delete);
			this->groupBox1->Controls->Add(this->button_update);
			this->groupBox1->Controls->Add(this->button_add);
			this->groupBox1->Controls->Add(this->button_download);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(165, 228);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Действия";
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(6, 175);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(153, 46);
			this->button_delete->TabIndex = 3;
			this->button_delete->Text = L"Удалить";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &MyForm::button_delete_Click);
			// 
			// button_update
			// 
			this->button_update->Location = System::Drawing::Point(6, 123);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(153, 46);
			this->button_update->TabIndex = 2;
			this->button_update->Text = L"Обновить";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Click += gcnew System::EventHandler(this, &MyForm::button_update_Click);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(6, 71);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(153, 46);
			this->button_add->TabIndex = 1;
			this->button_add->Text = L"Добавить";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::button_add_Click);
			// 
			// button_download
			// 
			this->button_download->Location = System::Drawing::Point(6, 19);
			this->button_download->Name = L"button_download";
			this->button_download->Size = System::Drawing::Size(153, 46);
			this->button_download->TabIndex = 0;
			this->button_download->Text = L"Загрузить";
			this->button_download->UseVisualStyleBackColor = true;
			this->button_download->Click += gcnew System::EventHandler(this, &MyForm::button_download_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->button_sort);
			this->groupBox2->Controls->Add(this->listBox_selectSort);
			this->groupBox2->Location = System::Drawing::Point(12, 261);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(165, 150);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Сортировка";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(153, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button_sort
			// 
			this->button_sort->Location = System::Drawing::Point(6, 94);
			this->button_sort->Name = L"button_sort";
			this->button_sort->Size = System::Drawing::Size(154, 46);
			this->button_sort->TabIndex = 4;
			this->button_sort->Text = L"Отсортировать";
			this->button_sort->UseVisualStyleBackColor = true;
			this->button_sort->Click += gcnew System::EventHandler(this, &MyForm::button_sort_Click);
			// 
			// listBox_selectSort
			// 
			this->listBox_selectSort->FormattingEnabled = true;
			this->listBox_selectSort->Location = System::Drawing::Point(6, 45);
			this->listBox_selectSort->Name = L"listBox_selectSort";
			this->listBox_selectSort->Size = System::Drawing::Size(153, 43);
			this->listBox_selectSort->TabIndex = 0;
			// 
			// pictureBox_update
			// 
			this->pictureBox_update->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_update.Image")));
			this->pictureBox_update->Location = System::Drawing::Point(183, 27);
			this->pictureBox_update->Name = L"pictureBox_update";
			this->pictureBox_update->Size = System::Drawing::Size(23, 24);
			this->pictureBox_update->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_update->TabIndex = 4;
			this->pictureBox_update->TabStop = false;
			this->pictureBox_update->Click += gcnew System::EventHandler(this, &MyForm::pictureBox_update_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(240, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Кол-во обращений от:";
			// 
			// textBox_amountOfRequests
			// 
			this->textBox_amountOfRequests->Location = System::Drawing::Point(360, 30);
			this->textBox_amountOfRequests->Name = L"textBox_amountOfRequests";
			this->textBox_amountOfRequests->Size = System::Drawing::Size(30, 20);
			this->textBox_amountOfRequests->TabIndex = 6;
			this->textBox_amountOfRequests->Text = L"5";
			this->textBox_amountOfRequests->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_amountOfRequests_TextChanged);
			// 
			// pictureBox_findAmountOfRequests
			// 
			this->pictureBox_findAmountOfRequests->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_findAmountOfRequests.Image")));
			this->pictureBox_findAmountOfRequests->Location = System::Drawing::Point(391, 25);
			this->pictureBox_findAmountOfRequests->Name = L"pictureBox_findAmountOfRequests";
			this->pictureBox_findAmountOfRequests->Size = System::Drawing::Size(30, 31);
			this->pictureBox_findAmountOfRequests->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_findAmountOfRequests->TabIndex = 7;
			this->pictureBox_findAmountOfRequests->TabStop = false;
			this->pictureBox_findAmountOfRequests->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->groupBox5);
			this->groupBox3->Controls->Add(this->groupBox4);
			this->groupBox3->Location = System::Drawing::Point(12, 417);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(165, 191);
			this->groupBox3->TabIndex = 8;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Поиск";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button_findAdress);
			this->groupBox4->Controls->Add(this->textBox_findAdress);
			this->groupBox4->Location = System::Drawing::Point(6, 19);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(154, 78);
			this->groupBox4->TabIndex = 10;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Адрес";
			// 
			// button_findAdress
			// 
			this->button_findAdress->Location = System::Drawing::Point(6, 45);
			this->button_findAdress->Name = L"button_findAdress";
			this->button_findAdress->Size = System::Drawing::Size(142, 25);
			this->button_findAdress->TabIndex = 6;
			this->button_findAdress->Text = L"Найти";
			this->button_findAdress->UseVisualStyleBackColor = true;
			this->button_findAdress->Click += gcnew System::EventHandler(this, &MyForm::button_findAdress_Click);
			// 
			// textBox_findAdress
			// 
			this->textBox_findAdress->Location = System::Drawing::Point(6, 19);
			this->textBox_findAdress->Name = L"textBox_findAdress";
			this->textBox_findAdress->Size = System::Drawing::Size(142, 20);
			this->textBox_findAdress->TabIndex = 9;
			this->textBox_findAdress->Text = L"Москва";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->button_findConractDate);
			this->groupBox5->Controls->Add(this->textBox_findContractDate);
			this->groupBox5->Location = System::Drawing::Point(6, 103);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(154, 78);
			this->groupBox5->TabIndex = 11;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Сроки договора";
			// 
			// button_findConractDate
			// 
			this->button_findConractDate->Location = System::Drawing::Point(6, 45);
			this->button_findConractDate->Name = L"button_findConractDate";
			this->button_findConractDate->Size = System::Drawing::Size(142, 25);
			this->button_findConractDate->TabIndex = 6;
			this->button_findConractDate->Text = L"Найти";
			this->button_findConractDate->UseVisualStyleBackColor = true;
			this->button_findConractDate->Click += gcnew System::EventHandler(this, &MyForm::button_findConractDate_Click);
			// 
			// textBox_findContractDate
			// 
			this->textBox_findContractDate->Location = System::Drawing::Point(6, 19);
			this->textBox_findContractDate->Name = L"textBox_findContractDate";
			this->textBox_findContractDate->Size = System::Drawing::Size(142, 20);
			this->textBox_findContractDate->TabIndex = 9;
			this->textBox_findContractDate->Text = L"12.12.2021";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1322, 620);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->pictureBox_findAmountOfRequests);
			this->Controls->Add(this->textBox_amountOfRequests);
			this->Controls->Add(this->pictureBox_update);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView_mainSheet);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"Информационная система \"РЕКЛАМА\"";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_mainSheet))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_update))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_findAmountOfRequests))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void initListBox_selectSort();

private: System::Void button_download_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_update_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_sort_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureBox_update_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox_amountOfRequests_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_findAdress_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_findConractDate_Click(System::Object^ sender, System::EventArgs^ e);
};
}
