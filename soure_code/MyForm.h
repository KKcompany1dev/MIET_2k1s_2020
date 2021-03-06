#pragma once

namespace KURSA4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView_mainSheet;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_download;
	private: System::Windows::Forms::Button^ button_delete;



	private: System::Windows::Forms::Button^ button_update;

	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientFullName_1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientFullName_2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientFullName_3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ contractID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientEmail;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientAdress;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clientInteractionNumber;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView_mainSheet = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_download = (gcnew System::Windows::Forms::Button());
			this->clientID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientFullName_1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientFullName_2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientFullName_3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contractID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientEmail = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientAdress = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clientInteractionNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_mainSheet))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem,
					this->�������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1187, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->���������ToolStripMenuItem,
					this->���������ToolStripMenuItem, this->�����ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// dataGridView_mainSheet
			// 
			this->dataGridView_mainSheet->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_mainSheet->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->clientID,
					this->clientFullName_1, this->clientFullName_2, this->clientFullName_3, this->contractID, this->clientEmail, this->clientAdress,
					this->clientInteractionNumber
			});
			this->dataGridView_mainSheet->Location = System::Drawing::Point(184, 45);
			this->dataGridView_mainSheet->Name = L"dataGridView_mainSheet";
			this->dataGridView_mainSheet->Size = System::Drawing::Size(995, 431);
			this->dataGridView_mainSheet->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_delete);
			this->groupBox1->Controls->Add(this->button_update);
			this->groupBox1->Controls->Add(this->button_add);
			this->groupBox1->Controls->Add(this->button_download);
			this->groupBox1->Location = System::Drawing::Point(13, 45);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(165, 431);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"��������";
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(6, 253);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(153, 46);
			this->button_delete->TabIndex = 3;
			this->button_delete->Text = L"�������";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &MyForm::button_delete_Click);
			// 
			// button_update
			// 
			this->button_update->Location = System::Drawing::Point(6, 180);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(153, 46);
			this->button_update->TabIndex = 2;
			this->button_update->Text = L"��������";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Click += gcnew System::EventHandler(this, &MyForm::button_update_Click);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(6, 104);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(153, 46);
			this->button_add->TabIndex = 1;
			this->button_add->Text = L"��������";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::button_add_Click);
			// 
			// button_download
			// 
			this->button_download->Location = System::Drawing::Point(6, 30);
			this->button_download->Name = L"button_download";
			this->button_download->Size = System::Drawing::Size(153, 46);
			this->button_download->TabIndex = 0;
			this->button_download->Text = L"���������";
			this->button_download->UseVisualStyleBackColor = true;
			this->button_download->Click += gcnew System::EventHandler(this, &MyForm::button_download_Click);
			// 
			// clientID
			// 
			this->clientID->HeaderText = L"ID �������";
			this->clientID->Name = L"clientID";
			// 
			// clientFullName_1
			// 
			this->clientFullName_1->HeaderText = L"�������";
			this->clientFullName_1->Name = L"clientFullName_1";
			this->clientFullName_1->Width = 150;
			// 
			// clientFullName_2
			// 
			this->clientFullName_2->HeaderText = L"���";
			this->clientFullName_2->Name = L"clientFullName_2";
			this->clientFullName_2->Width = 150;
			// 
			// clientFullName_3
			// 
			this->clientFullName_3->HeaderText = L"��������";
			this->clientFullName_3->Name = L"clientFullName_3";
			this->clientFullName_3->Width = 150;
			// 
			// contractID
			// 
			this->contractID->HeaderText = L"ID ��������";
			this->contractID->Name = L"contractID";
			// 
			// clientEmail
			// 
			this->clientEmail->HeaderText = L"�����";
			this->clientEmail->Name = L"clientEmail";
			// 
			// clientAdress
			// 
			this->clientAdress->HeaderText = L"�����";
			this->clientAdress->Name = L"clientAdress";
			// 
			// clientInteractionNumber
			// 
			this->clientInteractionNumber->HeaderText = L"���-�� ���������";
			this->clientInteractionNumber->Name = L"clientInteractionNumber";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1187, 488);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView_mainSheet);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"�������������� ������� \"�������\"";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_mainSheet))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_download_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_update_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e);
};
}
