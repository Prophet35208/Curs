#pragma once

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
	};
}
