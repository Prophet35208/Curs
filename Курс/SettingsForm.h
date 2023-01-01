#pragma once
#include "MainForm.h"
namespace Курс {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public:
		PictureBox^ current_picture_box;
		MainForm^ m_f;
	public:
		SettingsForm(void)
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
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_change_picture;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialogImage;

	protected:

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
			this->button_change_picture = (gcnew System::Windows::Forms::Button());
			this->openFileDialogImage = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// button_change_picture
			// 
			this->button_change_picture->Location = System::Drawing::Point(12, 12);
			this->button_change_picture->Name = L"button_change_picture";
			this->button_change_picture->Size = System::Drawing::Size(161, 105);
			this->button_change_picture->TabIndex = 0;
			this->button_change_picture->Text = L"Сменить картинку";
			this->button_change_picture->UseVisualStyleBackColor = true;
			this->button_change_picture->Click += gcnew System::EventHandler(this, &SettingsForm::button_change_picture_Click);
			// 
			// openFileDialogImage
			// 
			this->openFileDialogImage->FileName = L"Выбрать изображение";
			this->openFileDialogImage->Filter = L"JPG | *.jpg";
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(651, 456);
			this->Controls->Add(this->button_change_picture);
			this->Name = L"SettingsForm";
			this->Text = L"Настройки";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_change_picture_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialogImage->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			current_picture_box->Image = Image::FromFile(openFileDialogImage->FileName);
	}
	};
}
