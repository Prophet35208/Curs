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
	// Текущий номер строк. Указатель используется чтобы передавать данные между дочерними формами
	public: int* num_str;
	// Текущий (реальный для текущего слоя) и локальный список строк. Локальный переписывается в текущий только при применении настроек
	public: List<String^>^ str_list_current;
	public: List<String^>^ str_list_local = gcnew List<String^>();
	// Текущий шрифт. Необходимости в локальном нет
	public: System::Drawing::Font^ font_current;
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button_change_font_off_all;
	private: System::Windows::Forms::Label^ label_num_strings;





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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button_change_font_off_all = (gcnew System::Windows::Forms::Button());
			this->label_num_strings = (gcnew System::Windows::Forms::Label());
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
			this->richTextBox_all_strings->TextChanged += gcnew System::EventHandler(this, &CreateStringList::richTextBox_all_strings_TextChanged);
			// 
			// button_check
			// 
			this->button_check->Location = System::Drawing::Point(13, 29);
			this->button_check->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button_check->Name = L"button_check";
			this->button_check->Size = System::Drawing::Size(121, 42);
			this->button_check->TabIndex = 1;
			this->button_check->Text = L"Проверить количество строк";
			this->button_check->UseVisualStyleBackColor = true;
			this->button_check->Click += gcnew System::EventHandler(this, &CreateStringList::button_check_Click);
			// 
			// button_confirm
			// 
			this->button_confirm->Location = System::Drawing::Point(874, 477);
			this->button_confirm->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button_confirm->Name = L"button_confirm";
			this->button_confirm->Size = System::Drawing::Size(124, 48);
			this->button_confirm->TabIndex = 2;
			this->button_confirm->Text = L"Принять";
			this->button_confirm->UseVisualStyleBackColor = true;
			this->button_confirm->Click += gcnew System::EventHandler(this, &CreateStringList::button_confirm_Click);
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
			this->button_set_font->Location = System::Drawing::Point(383, 451);
			this->button_set_font->Name = L"button_set_font";
			this->button_set_font->Size = System::Drawing::Size(173, 60);
			this->button_set_font->TabIndex = 4;
			this->button_set_font->Text = L"Выбрать шрифт и задать его параметры";
			this->button_set_font->UseVisualStyleBackColor = true;
			this->button_set_font->Click += gcnew System::EventHandler(this, &CreateStringList::button_set_font_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(383, 27);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(123, 44);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Удалить все строки";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CreateStringList::button1_Click);
			// 
			// button_change_font_off_all
			// 
			this->button_change_font_off_all->Location = System::Drawing::Point(383, 391);
			this->button_change_font_off_all->Name = L"button_change_font_off_all";
			this->button_change_font_off_all->Size = System::Drawing::Size(173, 54);
			this->button_change_font_off_all->TabIndex = 6;
			this->button_change_font_off_all->Text = L"Применить первый встреченный шрифт ко всему тексту";
			this->button_change_font_off_all->UseVisualStyleBackColor = true;
			this->button_change_font_off_all->Click += gcnew System::EventHandler(this, &CreateStringList::button_change_font_off_all_Click);
			// 
			// label_num_strings
			// 
			this->label_num_strings->AutoSize = true;
			this->label_num_strings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_num_strings->Location = System::Drawing::Point(139, 39);
			this->label_num_strings->Name = L"label_num_strings";
			this->label_num_strings->Size = System::Drawing::Size(155, 20);
			this->label_num_strings->TabIndex = 7;
			this->label_num_strings->Text = L"Количество строк: ";
			// 
			// CreateStringList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1009, 537);
			this->Controls->Add(this->label_num_strings);
			this->Controls->Add(this->button_change_font_off_all);
			this->Controls->Add(this->button1);
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
// Установка шрифта из формы диалога
private: System::Void button_set_font_Click(System::Object^ sender, System::EventArgs^ e) {
	fontDialog->Font = richTextBox_all_strings->Font;
	if (System::Windows::Forms::DialogResult::OK == fontDialog->ShowDialog())
	{
		richTextBox_all_strings->Font = fontDialog->Font;
	}
}
// Применить шрифт
private: System::Void fontDialog_Apply(System::Object^ sender, System::EventArgs^ e) {
	richTextBox_all_strings->Font = fontDialog->Font;
}
// Проверка количества строк и обновление label-счётчика
private: System::Void button_check_Click(System::Object^ sender, System::EventArgs^ e) {
	str_list_local->Clear();
	String^ str = gcnew String("");
	str=richTextBox_all_strings->Text;
	cli::array<String^>^ arr = str->Split('\n');
	for (size_t i = 0; i < arr->Length; i++)
	{
		if(arr[i]!="")
			str_list_local->Add(arr[i]);
	}
	Int64 a;
	a = str_list_local->Count;
	label_num_strings->Text = "Количество строк: " + a.ToString();
}
	/* Не до конца реализованная система определения шрифтов каждой строки
private: System::Void richTextBox_all_strings_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	 //
	 В будущем возможно получение шрифта каждой строки
	RichTextBox2.Select(RichTextBox2.Lines(0).Length + 1, 
                    RichTextBox2.Lines(1).Length)
	font = RichTextBox2.SelectionFont.Name
	//
	if (richTextBox_all_strings->Enabled == 1) {
		richTextBox_all_strings->Select(richTextBox_all_strings->Lines[0]->Length + 1, richTextBox_all_strings->Lines[0]->Length + 1);
		System::Drawing::Font^ font = richTextBox_all_strings->SelectionFont;
		richTextBox_all_strings->Font = font;
	}
}*/
// Очистка поля ввода
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	richTextBox_all_strings->Clear();
}
// Примимение шрифта первого встречного символа, который позволяет определить шрифт. Используется для наглядности, т.к. программа пока что не поддерживает наличие нескольких шрифтов в одной строке
private: System::Void button_change_font_off_all_Click(System::Object^ sender, System::EventArgs^ e) {
	if (richTextBox_all_strings->Text->Length != 0) {
		System::Drawing::Font^ font;
		int i=0;
		while (font == nullptr) {
			richTextBox_all_strings->Select(i, 0);
			font = richTextBox_all_strings->SelectionFont;
			i++;
		}
		richTextBox_all_strings->Font = font;
		richTextBox_all_strings->SelectAll();
		richTextBox_all_strings->SelectionFont = font;
	}
}
// Очистка label-счётчика при написании 
private: System::Void richTextBox_all_strings_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	label_num_strings->Text = "Количество строк: ";
}
// Кнопка подтверждения. Определяется количетсво строк и они записываются в текущий набор строк. Первая часть кода практически идентична button_check_Click
private: System::Void button_confirm_Click(System::Object^ sender, System::EventArgs^ e) {
	str_list_local->Clear();
	String^ str = gcnew String("");
	str = richTextBox_all_strings->Text;
	cli::array<String^>^ arr = str->Split('\n');
	for (size_t i = 0; i < arr->Length; i++)
	{
		if (arr[i] != "")
			str_list_local->Add(arr[i]);
	}
	Int64 a;
	a = str_list_local->Count;
	label_num_strings->Text = "Количество строк: " + a.ToString();



	if (richTextBox_all_strings->Font != nullptr && str_list_local->Count > 0) {
		str_list_current->Clear();
		str_list_current->AddRange(str_list_local);
		str_list_current = str_list_local;
		font_current = richTextBox_all_strings->Font;
		*num_str = str_list_local->Count;
		this->Close();
	}
	else
	{
		MessageBox::Show("Шрифт или набор строк был задан некорректно");
	}
}
};
}
