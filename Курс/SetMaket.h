#pragma once

namespace Курс {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SetMaket
	/// </summary>
	public ref class SetMaket : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::TextBox^ textBox_width;
	public:
	private: System::Windows::Forms::TextBox^ textBox_height;
	private: System::Windows::Forms::Button^ button_confirm;
	public: Int64^ width;
	public: Int64^ height;
	public:
		SetMaket(void)
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
		~SetMaket()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_up;
	protected:


	private: System::Windows::Forms::Label^ label_width;
	private: System::Windows::Forms::Label^ label_height;

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
			this->label_up = (gcnew System::Windows::Forms::Label());
			this->label_width = (gcnew System::Windows::Forms::Label());
			this->label_height = (gcnew System::Windows::Forms::Label());
			this->textBox_width = (gcnew System::Windows::Forms::TextBox());
			this->textBox_height = (gcnew System::Windows::Forms::TextBox());
			this->button_confirm = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label_up
			// 
			this->label_up->AutoSize = true;
			this->label_up->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_up->Location = System::Drawing::Point(43, 9);
			this->label_up->Name = L"label_up";
			this->label_up->Size = System::Drawing::Size(342, 48);
			this->label_up->TabIndex = 0;
			this->label_up->Text = L"Установите высоту и ширину макета\r\n                   (в пикселях)";
			// 
			// label_width
			// 
			this->label_width->AutoSize = true;
			this->label_width->Location = System::Drawing::Point(72, 78);
			this->label_width->Name = L"label_width";
			this->label_width->Size = System::Drawing::Size(88, 13);
			this->label_width->TabIndex = 3;
			this->label_width->Text = L"0<Ширина<1000";
			// 
			// label_height
			// 
			this->label_height->AutoSize = true;
			this->label_height->Location = System::Drawing::Point(266, 78);
			this->label_height->Name = L"label_height";
			this->label_height->Size = System::Drawing::Size(81, 13);
			this->label_height->TabIndex = 4;
			this->label_height->Text = L"0<Высота<800";
			// 
			// textBox_width
			// 
			this->textBox_width->Location = System::Drawing::Point(60, 94);
			this->textBox_width->MaxLength = 4;
			this->textBox_width->Name = L"textBox_width";
			this->textBox_width->Size = System::Drawing::Size(100, 20);
			this->textBox_width->TabIndex = 5;
			this->textBox_width->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SetMaket::textBox_width_KeyPress);
			// 
			// textBox_height
			// 
			this->textBox_height->Location = System::Drawing::Point(247, 94);
			this->textBox_height->MaxLength = 4;
			this->textBox_height->Name = L"textBox_height";
			this->textBox_height->Size = System::Drawing::Size(100, 20);
			this->textBox_height->TabIndex = 6;
			// 
			// button_confirm
			// 
			this->button_confirm->Location = System::Drawing::Point(151, 172);
			this->button_confirm->Name = L"button_confirm";
			this->button_confirm->Size = System::Drawing::Size(107, 36);
			this->button_confirm->TabIndex = 7;
			this->button_confirm->Text = L"Принять";
			this->button_confirm->UseVisualStyleBackColor = true;
			this->button_confirm->Click += gcnew System::EventHandler(this, &SetMaket::button_confirm_Click);
			// 
			// SetMaket
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(425, 220);
			this->Controls->Add(this->button_confirm);
			this->Controls->Add(this->textBox_height);
			this->Controls->Add(this->textBox_width);
			this->Controls->Add(this->label_height);
			this->Controls->Add(this->label_width);
			this->Controls->Add(this->label_up);
			this->Name = L"SetMaket";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Установите размеры";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// Ограничение на ввод символов
private: System::Void textBox_width_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar.IsDigit(e->KeyChar)|| e->KeyChar==8);
		else
			e->Handled = 1;
	}
// Подтвержение с обработкой исключительных случаев
private: System::Void button_confirm_Click(System::Object^ sender, System::EventArgs^ e) {
	try{
	int width= Convert::ToInt64(textBox_width->Text);
	int height=Convert::ToInt64(textBox_height->Text);
		if (width > 0 && width <= 1000)
			if (height > 0 && height <= 800) {
				*this->width = width;
				*this->height = height;
				this->Close();
			}
			else {
				String^ str = gcnew String("WrongHeight");
				throw str;
			}
		else {
			String^ str = gcnew String("WrongWidth");
			throw str;
		}
	}
	catch (System::FormatException^ e) {
		MessageBox::Show("Неверный формат данных");
	}
	catch (String^ str) {
		if(str=="WrongHeight")
			MessageBox::Show("Неверная выстота");
		if(str=="WrongWidth")
			MessageBox::Show("Неверная ширина");
	}
}
};
}
