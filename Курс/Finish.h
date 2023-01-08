#pragma once
#include "Layer.h"
namespace Курс {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для Finish
	/// </summary>
	public ref class Finish : public System::Windows::Forms::Form
	{
	public: List<Image^>^ image_list;
	private: System::Windows::Forms::Button^ button_save;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;
	private: int count = 1;
	public: 
		Finish(void)
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
		~Finish()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox_finish;
	private: System::Windows::Forms::Button^ button_left;	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button_right;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_finish = (gcnew System::Windows::Forms::PictureBox());
			this->button_left = (gcnew System::Windows::Forms::Button());
			this->button_right = (gcnew System::Windows::Forms::Button());
			this->button_save = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_finish))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(220, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Предпросмотр";
			// 
			// pictureBox_finish
			// 
			this->pictureBox_finish->Location = System::Drawing::Point(254, 185);
			this->pictureBox_finish->Name = L"pictureBox_finish";
			this->pictureBox_finish->Size = System::Drawing::Size(100, 50);
			this->pictureBox_finish->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_finish->TabIndex = 1;
			this->pictureBox_finish->TabStop = false;
			// 
			// button_left
			// 
			this->button_left->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_left->Location = System::Drawing::Point(165, 9);
			this->button_left->Name = L"button_left";
			this->button_left->Size = System::Drawing::Size(49, 36);
			this->button_left->TabIndex = 2;
			this->button_left->Text = L"<";
			this->button_left->UseVisualStyleBackColor = true;
			this->button_left->Click += gcnew System::EventHandler(this, &Finish::button_left_Click);
			// 
			// button_right
			// 
			this->button_right->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_right->Location = System::Drawing::Point(371, 9);
			this->button_right->Name = L"button_right";
			this->button_right->Size = System::Drawing::Size(49, 36);
			this->button_right->TabIndex = 3;
			this->button_right->Text = L">";
			this->button_right->UseVisualStyleBackColor = true;
			this->button_right->Click += gcnew System::EventHandler(this, &Finish::button_right_Click);
			// 
			// button_save
			// 
			this->button_save->Location = System::Drawing::Point(539, 390);
			this->button_save->Name = L"button_save";
			this->button_save->Size = System::Drawing::Size(106, 54);
			this->button_save->TabIndex = 4;
			this->button_save->Text = L"Сохранить изображения в директорию";
			this->button_save->UseVisualStyleBackColor = true;
			this->button_save->Click += gcnew System::EventHandler(this, &Finish::button_save_Click);
			// 
			// Finish
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(657, 456);
			this->Controls->Add(this->button_save);
			this->Controls->Add(this->button_right);
			this->Controls->Add(this->button_left);
			this->Controls->Add(this->pictureBox_finish);
			this->Controls->Add(this->label1);
			this->Name = L"Finish";
			this->Text = L"Подготовка к сохранению";
			this->Load += gcnew System::EventHandler(this, &Finish::Finish_Load);
			this->Resize += gcnew System::EventHandler(this, &Finish::Finish_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_finish))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Finish_Resize(System::Object^ sender, System::EventArgs^ e) {
		pictureBox_finish->Left = ClientSize.Width / 2 - pictureBox_finish->Width / 2;
		pictureBox_finish->Top = ClientSize.Height / 2 - pictureBox_finish->Height / 2;
	}
	private: System::Void Finish_Load(System::Object^ sender, System::EventArgs^ e) {
		pictureBox_finish->Size = image_list[0]->Size;
		pictureBox_finish->Image = image_list[0];
		if (image_list->Count == 1) {
			button_right->Enabled = 0;
			button_left->Enabled = 0;
		}
		pictureBox_finish->Left = ClientSize.Width / 2 - pictureBox_finish->Width / 2;
		pictureBox_finish->Top = ClientSize.Height / 2 - pictureBox_finish->Height / 2;
		this->MinimumSize = System::Drawing::Size(200 + pictureBox_finish->Width, 200 + pictureBox_finish->Height);
		int min_width;
		int min_height;
		if (200 + pictureBox_finish->Width < 650)
			min_width = 650;
		else
			min_width = 200 + pictureBox_finish->Width;
		if (200 + pictureBox_finish->Height < 300)
			min_height = 300;
		else
			min_height = 200 + pictureBox_finish->Height;
		this->MinimumSize = System::Drawing::Size(min_width, min_height);
	}
	private: System::Void button_left_Click(System::Object^ sender, System::EventArgs^ e) {
		if (count >1) {
			pictureBox_finish->Image = image_list[count-2];
			count--;
		}
		if (count == 1)
			button_left->Enabled = 0;
		if (count < image_list->Count)
			button_right->Enabled = 1;
		this->pictureBox_finish->Image = image_list[count - 1];
	}
private: System::Void button_right_Click(System::Object^ sender, System::EventArgs^ e) {
	if (count < image_list->Count) {
		pictureBox_finish->Image = image_list[count];
		count++;
	}
	if (count == image_list->Count)
		button_right->Enabled = 0;
	if (count > 1) {
		button_left->Enabled = 1;
	}
	this->pictureBox_finish->Image = image_list[count - 1];
}
private: System::Void button_save_Click(System::Object^ sender, System::EventArgs^ e) {
	if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		;

}
};
}
