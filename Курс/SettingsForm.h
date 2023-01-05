#pragma once
#include "MainForm.h"
namespace Курс {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Сводка для SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public: PictureBox^ current_picture_box;
	public: int mod;
	public: MainForm^ m_f;


	public: System::Windows::Forms::PictureBox^ pictureBox_main;
	private: System::Windows::Forms::Button^ button_confirm;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialogText;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button_attach_text;
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
			this->pictureBox_main = (gcnew System::Windows::Forms::PictureBox());
			this->button_attach_text = (gcnew System::Windows::Forms::Button());
			this->button_confirm = (gcnew System::Windows::Forms::Button());
			this->openFileDialogText = (gcnew System::Windows::Forms::OpenFileDialog());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main))->BeginInit();
			this->SuspendLayout();
			// 
			// button_change_picture
			// 
			this->button_change_picture->Location = System::Drawing::Point(12, 12);
			this->button_change_picture->Name = L"button_change_picture";
			this->button_change_picture->Size = System::Drawing::Size(124, 53);
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
			// pictureBox_main
			// 
			this->pictureBox_main->Location = System::Drawing::Point(253, 161);
			this->pictureBox_main->Name = L"pictureBox_main";
			this->pictureBox_main->Size = System::Drawing::Size(137, 83);
			this->pictureBox_main->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_main->TabIndex = 1;
			this->pictureBox_main->TabStop = false;
			// 
			// button_attach_text
			// 
			this->button_attach_text->Location = System::Drawing::Point(142, 12);
			this->button_attach_text->Name = L"button_attach_text";
			this->button_attach_text->Size = System::Drawing::Size(144, 53);
			this->button_attach_text->TabIndex = 2;
			this->button_attach_text->Text = L"Указать файл с текстом";
			this->button_attach_text->UseVisualStyleBackColor = true;
			this->button_attach_text->Click += gcnew System::EventHandler(this, &SettingsForm::button_attach_text_Click);
			// 
			// button_confirm
			// 
			this->button_confirm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_confirm->Location = System::Drawing::Point(479, 12);
			this->button_confirm->Name = L"button_confirm";
			this->button_confirm->Size = System::Drawing::Size(144, 53);
			this->button_confirm->TabIndex = 3;
			this->button_confirm->Text = L"Принять";
			this->button_confirm->UseVisualStyleBackColor = true;
			this->button_confirm->Click += gcnew System::EventHandler(this, &SettingsForm::button_confirm_Click);
			// 
			// openFileDialogText
			// 
			this->openFileDialogText->FileName = L"Выбрать файл с текстом";
			this->openFileDialogText->Filter = L"Текстовый файл| *.docx";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(444, 111);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(151, 172);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"";
			this->richTextBox1->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(101, 152);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SettingsForm::button1_Click);
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(635, 315);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button_confirm);
			this->Controls->Add(this->button_attach_text);
			this->Controls->Add(this->pictureBox_main);
			this->Controls->Add(this->button_change_picture);
			this->MinimumSize = System::Drawing::Size(650, 300);
			this->Name = L"SettingsForm";
			this->Text = L"Настройки";
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			this->Resize += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_change_picture_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialogImage->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox_main->Image = Image::FromFile(openFileDialogImage->FileName);
		}
	}
	private: System::Void SettingsForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		pictureBox_main->Left = ClientSize.Width / 2 - pictureBox_main->Width / 2;
		pictureBox_main->Top = ClientSize.Height / 2 - pictureBox_main->Height / 2;
	}
	private: System::Void SettingsForm_Load(System::Object^ sender, System::EventArgs^ e) {
		pictureBox_main->Left = ClientSize.Width / 2 - pictureBox_main->Width / 2;
		pictureBox_main->Top = ClientSize.Height / 2 - pictureBox_main->Height / 2;
		this->MinimumSize=System::Drawing::Size(200 + pictureBox_main->Width, 200 + pictureBox_main->Height);
		int min_width;
		int min_height;
		if (200 + pictureBox_main->Width < 650)
			min_width = 650;
		else
			min_width = 200 + pictureBox_main->Width;
		if (200 + pictureBox_main->Height < 300)
			min_height = 300;
		else
			min_height = 200 + pictureBox_main->Height;
		this->MinimumSize = System::Drawing::Size(min_width, min_height);

		if (mod == 2) {
			button_attach_text->Visible = 0;
		}
	}
private: System::Void button_confirm_Click(System::Object^ sender, System::EventArgs^ e) {
	current_picture_box->Image = pictureBox_main->Image;
	this->Close();
}
private: System::Void button_attach_text_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialogText->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		richTextBox1->Text = File::ReadAllText(openFileDialogText->FileName);
		int a;
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int a;
}
};
}
