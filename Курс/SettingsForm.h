#pragma once
#include "MainForm.h"
#include "CreateStringList.h"
namespace Курс {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	// "Текущий" обозначает, что данный указатель ссылается непосредственно на экземпляр члена слоя (класса layer)
	// Текущий номер строк
	public: int* num_str;
	// Текущий PictureBox
	public: PictureBox^ current_picture_box;
	 // Текущая совокупность строк
	public: List<String^>^ current_str_list;
	// Локальная совокупность строк
	public: List<String^>^ locale_str_list = gcnew List<String^>();
	// Режим обработки (1-картинка без текста, 2-картинка с текстом)
	public: int mod;
	// Текущий шрифт
	public: System::Drawing::Font^ cur_font;
	// Локальынй фонт
	public: System::Drawing::Font^ locale_font;
	// Текущей указатель на член layer (поазывает, нужно ли в изображении с текстом применять фон в конечной компиляции)
	public: bool* background_check;

	public: System::Windows::Forms::PictureBox^ pictureBox_main;
	private: System::Windows::Forms::Button^ button_confirm;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialogText;
	private: System::Windows::Forms::Button^ button_change_color;
	private: System::Windows::Forms::CheckBox^ checkBox_background;
	private: System::Windows::Forms::ColorDialog^ colorDialog;
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
			this->button_change_color = (gcnew System::Windows::Forms::Button());
			this->checkBox_background = (gcnew System::Windows::Forms::CheckBox());
			this->colorDialog = (gcnew System::Windows::Forms::ColorDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main))->BeginInit();
			this->SuspendLayout();
			// 
			// button_change_picture
			// 
			this->button_change_picture->Location = System::Drawing::Point(12, 12);
			this->button_change_picture->Name = L"button_change_picture";
			this->button_change_picture->Size = System::Drawing::Size(113, 39);
			this->button_change_picture->TabIndex = 0;
			this->button_change_picture->Text = L"Сменить картинку (выбрать png)";
			this->button_change_picture->UseVisualStyleBackColor = true;
			this->button_change_picture->Click += gcnew System::EventHandler(this, &SettingsForm::button_change_picture_Click);
			// 
			// openFileDialogImage
			// 
			this->openFileDialogImage->FileName = L"Выбрать изображение";
			this->openFileDialogImage->Filter = L"Images|*.png;*.bmp;*.jpg";
			// 
			// pictureBox_main
			// 
			this->pictureBox_main->Location = System::Drawing::Point(248, 149);
			this->pictureBox_main->Name = L"pictureBox_main";
			this->pictureBox_main->Size = System::Drawing::Size(137, 83);
			this->pictureBox_main->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_main->TabIndex = 1;
			this->pictureBox_main->TabStop = false;
			// 
			// button_attach_text
			// 
			this->button_attach_text->Location = System::Drawing::Point(224, 12);
			this->button_attach_text->Name = L"button_attach_text";
			this->button_attach_text->Size = System::Drawing::Size(144, 39);
			this->button_attach_text->TabIndex = 2;
			this->button_attach_text->Text = L"Задать текст и его параметры";
			this->button_attach_text->UseVisualStyleBackColor = true;
			this->button_attach_text->Click += gcnew System::EventHandler(this, &SettingsForm::button_attach_text_Click);
			// 
			// button_confirm
			// 
			this->button_confirm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_confirm->Location = System::Drawing::Point(661, 12);
			this->button_confirm->Name = L"button_confirm";
			this->button_confirm->Size = System::Drawing::Size(144, 39);
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
			// button_change_color
			// 
			this->button_change_color->Location = System::Drawing::Point(131, 12);
			this->button_change_color->Name = L"button_change_color";
			this->button_change_color->Size = System::Drawing::Size(87, 39);
			this->button_change_color->TabIndex = 4;
			this->button_change_color->Text = L"Залить фон";
			this->button_change_color->UseVisualStyleBackColor = true;
			this->button_change_color->Click += gcnew System::EventHandler(this, &SettingsForm::button_change_color_Click);
			// 
			// checkBox_background
			// 
			this->checkBox_background->AutoSize = true;
			this->checkBox_background->Location = System::Drawing::Point(12, 57);
			this->checkBox_background->Name = L"checkBox_background";
			this->checkBox_background->Size = System::Drawing::Size(514, 17);
			this->checkBox_background->TabIndex = 5;
			this->checkBox_background->Text = L"Не учитывать фон в конечном изображении (в макете фон всё ещё будет показывать гр"
				L"аницы)";
			this->checkBox_background->UseVisualStyleBackColor = true;
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(817, 308);
			this->Controls->Add(this->checkBox_background);
			this->Controls->Add(this->button_change_color);
			this->Controls->Add(this->button_confirm);
			this->Controls->Add(this->button_attach_text);
			this->Controls->Add(this->pictureBox_main);
			this->Controls->Add(this->button_change_picture);
			this->MinimumSize = System::Drawing::Size(650, 300);
			this->Name = L"SettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Настройки";
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			this->Resize += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// Смена изображения слоя с помощью openFileDialog
private: System::Void button_change_picture_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialogImage->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox_main->Image = Image::FromFile(openFileDialogImage->FileName);
		}
	}
// Корректное отображение слоя на экране с учётом его размеров при изменении размеров окна
private: System::Void SettingsForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		pictureBox_main->Left = ClientSize.Width / 2 - pictureBox_main->Width / 2;
		pictureBox_main->Top = ClientSize.Height / 2 - pictureBox_main->Height / 2;
	}
// Корректное отображение слоя на экране с учётом его размеров после загрузки
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

		if (mod == 1) {
			button_attach_text->Visible = 0;
			checkBox_background->Visible = 0;
		}
	}
// Подтверерждение и применение всех настроек 
private: System::Void button_confirm_Click(System::Object^ sender, System::EventArgs^ e) {
	current_picture_box->Image = pictureBox_main->Image;
	current_str_list->Clear();
	current_str_list->AddRange(locale_str_list);
	if (checkBox_background->Checked == 1)
		*background_check = 0;
	this->Close();
}
// Прикрепить текст к слою
private: System::Void button_attach_text_Click(System::Object^ sender, System::EventArgs^ e) {
	CreateStringList^ csl = gcnew CreateStringList();
	csl->str_list_current = locale_str_list;
	csl->font_current = cur_font;
	csl->num_str = num_str;
	csl->ShowDialog();
	cur_font = csl->font_current;
	// if (openFileDialogText->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
	//	int a;
	// }
}
// Залить слой некоторым цветом
private: System::Void button_change_color_Click(System::Object^ sender, System::EventArgs^ e) {
	colorDialog->Color = Color::White;
	colorDialog->ShowDialog();
	Bitmap^ image = gcnew Bitmap(current_picture_box->Width, current_picture_box->Height);
	for (int i = 0; i < image->Width; i++)
		for (int j = 0; j < image->Height; j++)
			image->SetPixel(i, j, colorDialog->Color);
	pictureBox_main->Image = image;
}
// 
};
}
