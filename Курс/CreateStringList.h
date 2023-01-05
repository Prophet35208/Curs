#pragma once
#include <string>
#include <vector>
namespace Курс {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Сводка для CreateStringList
	/// </summary>
	public ref class CreateStringList : public System::Windows::Forms::Form
	{
	public: vector<string>* string_list;
	public:
		CreateStringList(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CreateStringList()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox_all_strings;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button_check;
	private: System::Windows::Forms::Button^ button_confirm;
	private: System::Windows::Forms::Label^ label_string_up;
	private: System::Windows::Forms::FontDialog^ fontDialog;









	private: System::Windows::Forms::Button^ button_set_font;





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
			this->richTextBox_all_strings = (gcnew System::Windows::Forms::RichTextBox());
			this->button_check = (gcnew System::Windows::Forms::Button());
			this->button_confirm = (gcnew System::Windows::Forms::Button());
			this->label_string_up = (gcnew System::Windows::Forms::Label());
			this->fontDialog = (gcnew System::Windows::Forms::FontDialog());
			this->button_set_font = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox_all_strings
			// 
			this->richTextBox_all_strings->Location = System::Drawing::Point(12, 75);
			this->richTextBox_all_strings->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->richTextBox_all_strings->Name = L"richTextBox_all_strings";
			this->richTextBox_all_strings->Size = System::Drawing::Size(366, 434);
			this->richTextBox_all_strings->TabIndex = 0;
			this->richTextBox_all_strings->Text = L"";
			// 
			// button_check
			// 
			this->button_check->Location = System::Drawing::Point(877, 473);
			this->button_check->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button_check->Name = L"button_check";
			this->button_check->Size = System::Drawing::Size(121, 38);
			this->button_check->TabIndex = 1;
			this->button_check->Text = L"Проверить количество строк";
			this->button_check->UseVisualStyleBackColor = true;
			this->button_check->Click += gcnew System::EventHandler(this, &CreateStringList::button_check_Click);
			// 
			// button_confirm
			// 
			this->button_confirm->Location = System::Drawing::Point(767, 475);
			this->button_confirm->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button_confirm->Name = L"button_confirm";
			this->button_confirm->Size = System::Drawing::Size(106, 36);
			this->button_confirm->TabIndex = 2;
			this->button_confirm->Text = L"Принять";
			this->button_confirm->UseVisualStyleBackColor = true;
			// 
			// label_string_up
			// 
			this->label_string_up->AutoSize = true;
			this->label_string_up->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_string_up->Location = System::Drawing::Point(10, 9);
			this->label_string_up->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_string_up->Name = L"label_string_up";
			this->label_string_up->Size = System::Drawing::Size(374, 17);
			this->label_string_up->TabIndex = 3;
			this->label_string_up->Text = L"Введите необходимое количество строк в форму снизу";
			// 
			// fontDialog
			// 
			this->fontDialog->ShowApply = true;
			this->fontDialog->ShowColor = true;
			this->fontDialog->Apply += gcnew System::EventHandler(this, &CreateStringList::fontDialog_Apply);
			// 
			// button_set_font
			// 
			this->button_set_font->Location = System::Drawing::Point(393, 449);
			this->button_set_font->Name = L"button_set_font";
			this->button_set_font->Size = System::Drawing::Size(173, 60);
			this->button_set_font->TabIndex = 4;
			this->button_set_font->Text = L"Выбрать шрифт и задать его параметры";
			this->button_set_font->UseVisualStyleBackColor = true;
			this->button_set_font->Click += gcnew System::EventHandler(this, &CreateStringList::button_set_font_Click);
			// 
			// CreateStringList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1009, 537);
			this->Controls->Add(this->button_set_font);
			this->Controls->Add(this->label_string_up);
			this->Controls->Add(this->button_confirm);
			this->Controls->Add(this->button_check);
			this->Controls->Add(this->richTextBox_all_strings);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.255555F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Name = L"CreateStringList";
			this->Text = L"Параметры текста";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_set_font_Click(System::Object^ sender, System::EventArgs^ e) {
	fontDialog->Font = richTextBox_all_strings->Font;
	fontDialog->ShowDialog();
}
private: System::Void fontDialog_Apply(System::Object^ sender, System::EventArgs^ e) {
	richTextBox_all_strings->Font = fontDialog->Font;
}
private: System::Void button_check_Click(System::Object^ sender, System::EventArgs^ e) {
	//
}
};
}
