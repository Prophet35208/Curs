#pragma once
#include <math.h>
#include "Layer.h"
#include "SetMaket.h"
/*
c_str - перевод string в const char
	string a("fafa");
	String^ st = gcnew String(a.c_str());

	ToCharArray - перевод от String^ к string (через char*)
*/
namespace Курс {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		int f = 0;
	public: Bitmap^ b;
	private: System::Windows::Forms::Button^ button_finish;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	public:
	public:
		PictureBox^ settings_form_picture_box;
	private:
		// Функция обновления порядка слоёв по индексу
		void RefreshTable() {
			for (int i = layer_list->Count-1; i >=0; i--)
			{
				layer_list[i]->GetPictureBox()->BringToFront();
			}
		}
	private: Int64^ width=gcnew Int64(0);
	private: Int64^ height= gcnew Int64(0);
		// Необходимые переменные для корректного редкатирования размеров изображений (перетягиванием границ)
		// Радиус прилипания к краю макета
		int sticking_rad = 5;
		// Индикатор прилипания
		bool f_stick = false;
		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: PictureBox^ current_picture_box;
		   //
		System::Windows::Forms::Button^ button_121414;
		int create_image = 0;
		int create_image_with_text = 0;
		int mouse_down = 0;
		Rectangle rectProposedSize = Rectangle::Empty;
		// Коллекция изображений без текста 
		// List<System::Windows::Forms::PictureBox^>^ picture_list = gcnew List<System::Windows::Forms::PictureBox^>();
		// Коллекция слоёв
		List<Layer^>^ layer_list = gcnew List<Layer^>();

	private: System::Windows::Forms::Button^ button_recreate_main;
	private: System::Windows::Forms::PictureBox^ main_element;
	private: System::Windows::Forms::Button^ button_set_image_to_object;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip_delete_main_element;
	private: System::Windows::Forms::ToolStripMenuItem^ удалитьToolStripMenuItem;



	private: System::Windows::Forms::PictureBox^ pictureBox_main_object;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_name;
	private: System::Windows::Forms::DataGridViewButtonColumn^ button_settings;
	private: System::Windows::Forms::DataGridViewButtonColumn^ up;
	private: System::Windows::Forms::DataGridViewButtonColumn^ down;
	private: System::Windows::Forms::DataGridViewButtonColumn^ delete_line;




















	private: System::Windows::Forms::DataGridView^ main_table;
		   //

	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			main_table->Rows->Add("Макет");
			
			SetMaket^ sm = gcnew SetMaket();
			sm->height = height;
			sm->width = width;
			sm->ShowDialog();
			if (*height != 0 && *width != 0) {
				pictureBox_main_object->Height = *height;
				pictureBox_main_object->Width = *width;
			}
			

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_create_picture;
	protected:

	private: System::ComponentModel::IContainer^ components;
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->button_create_picture = (gcnew System::Windows::Forms::Button());
			this->button_set_image_to_object = (gcnew System::Windows::Forms::Button());
			this->main_table = (gcnew System::Windows::Forms::DataGridView());
			this->Column_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button_settings = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->up = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->down = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->delete_line = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->contextMenuStrip_delete_main_element = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->удалитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox_main_object = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button_recreate_main = (gcnew System::Windows::Forms::Button());
			this->button_finish = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->BeginInit();
			this->contextMenuStrip_delete_main_element->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_object))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// button_create_picture
			// 
			this->button_create_picture->Location = System::Drawing::Point(12, 3);
			this->button_create_picture->Name = L"button_create_picture";
			this->button_create_picture->Size = System::Drawing::Size(143, 52);
			this->button_create_picture->TabIndex = 0;
			this->button_create_picture->Text = L"Создать изображение без текста";
			this->button_create_picture->UseVisualStyleBackColor = true;
			this->button_create_picture->Click += gcnew System::EventHandler(this, &MainForm::button_create_picture_Click);
			// 
			// button_set_image_to_object
			// 
			this->button_set_image_to_object->Location = System::Drawing::Point(161, 3);
			this->button_set_image_to_object->Name = L"button_set_image_to_object";
			this->button_set_image_to_object->Size = System::Drawing::Size(143, 52);
			this->button_set_image_to_object->TabIndex = 3;
			this->button_set_image_to_object->Text = L"Создать изображение \r\nс текстом";
			this->button_set_image_to_object->UseVisualStyleBackColor = true;
			this->button_set_image_to_object->Click += gcnew System::EventHandler(this, &MainForm::button_set_image_to_object_Click);
			// 
			// main_table
			// 
			this->main_table->AllowUserToAddRows = false;
			this->main_table->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->main_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->main_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column_name,
					this->button_settings, this->up, this->down, this->delete_line
			});
			this->main_table->Location = System::Drawing::Point(741, 5);
			this->main_table->Name = L"main_table";
			this->main_table->Size = System::Drawing::Size(646, 644);
			this->main_table->TabIndex = 4;
			this->main_table->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::main_table_CellContentClick);
			// 
			// Column_name
			// 
			this->Column_name->HeaderText = L"Название слоя";
			this->Column_name->MaxInputLength = 30;
			this->Column_name->MinimumWidth = 70;
			this->Column_name->Name = L"Column_name";
			this->Column_name->Width = 200;
			// 
			// button_settings
			// 
			this->button_settings->HeaderText = L"Настройки";
			this->button_settings->Name = L"button_settings";
			this->button_settings->Text = L"Настройки";
			this->button_settings->UseColumnTextForButtonValue = true;
			// 
			// up
			// 
			this->up->HeaderText = L"Выше";
			this->up->Name = L"up";
			this->up->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->up->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// down
			// 
			this->down->HeaderText = L"Ниже";
			this->down->Name = L"down";
			this->down->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->down->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// delete_line
			// 
			this->delete_line->HeaderText = L"Удалить";
			this->delete_line->Name = L"delete_line";
			this->delete_line->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->delete_line->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// contextMenuStrip_delete_main_element
			// 
			this->contextMenuStrip_delete_main_element->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->удалитьToolStripMenuItem });
			this->contextMenuStrip_delete_main_element->Name = L"contextMenuStrip1";
			this->contextMenuStrip_delete_main_element->Size = System::Drawing::Size(119, 26);
			// 
			// удалитьToolStripMenuItem
			// 
			this->удалитьToolStripMenuItem->Name = L"удалитьToolStripMenuItem";
			this->удалитьToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->удалитьToolStripMenuItem->Text = L"Удалить";
			this->удалитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::удалитьToolStripMenuItem_Click);
			// 
			// pictureBox_main_object
			// 
			this->pictureBox_main_object->BackColor = System::Drawing::SystemColors::HighlightText;
			this->pictureBox_main_object->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox_main_object->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_main_object.Image")));
			this->pictureBox_main_object->Location = System::Drawing::Point(117, 167);
			this->pictureBox_main_object->MinimumSize = System::Drawing::Size(30, 30);
			this->pictureBox_main_object->Name = L"pictureBox_main_object";
			this->pictureBox_main_object->Size = System::Drawing::Size(523, 404);
			this->pictureBox_main_object->TabIndex = 5;
			this->pictureBox_main_object->TabStop = false;
			this->pictureBox_main_object->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseDown);
			this->pictureBox_main_object->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseMove);
			this->pictureBox_main_object->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseUp);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(525, 74);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(210, 97);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainForm::pictureBox1_Click);
			// 
			// button_recreate_main
			// 
			this->button_recreate_main->Location = System::Drawing::Point(310, 3);
			this->button_recreate_main->Name = L"button_recreate_main";
			this->button_recreate_main->Size = System::Drawing::Size(143, 52);
			this->button_recreate_main->TabIndex = 7;
			this->button_recreate_main->Text = L"Удалить все слои и заново назначить размер макета";
			this->button_recreate_main->UseVisualStyleBackColor = true;
			this->button_recreate_main->Click += gcnew System::EventHandler(this, &MainForm::button_recreate_main_Click);
			// 
			// button_finish
			// 
			this->button_finish->Location = System::Drawing::Point(459, 3);
			this->button_finish->Name = L"button_finish";
			this->button_finish->Size = System::Drawing::Size(116, 52);
			this->button_finish->TabIndex = 8;
			this->button_finish->Text = L"Перейти к сборке";
			this->button_finish->UseVisualStyleBackColor = true;
			this->button_finish->Click += gcnew System::EventHandler(this, &MainForm::button_finish_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(919, 251);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(234, 168);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBox2_Paint);
			// 
			// pictureBox3
			// 
			this->pictureBox3->ContextMenuStrip = this->contextMenuStrip_delete_main_element;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(992, 187);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(253, 184);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 10;
			this->pictureBox3->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(641, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(328, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 12;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1399, 661);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button_finish);
			this->Controls->Add(this->button_recreate_main);
			this->Controls->Add(this->pictureBox_main_object);
			this->Controls->Add(this->main_table);
			this->Controls->Add(this->button_set_image_to_object);
			this->Controls->Add(this->button_create_picture);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->EndInit();
			this->contextMenuStrip_delete_main_element->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_object))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_create_picture_Click(System::Object^ sender, System::EventArgs^ e);
// Удаление макета
private: System::Void удалитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureBox_main_object_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void pictureBox_main_object_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void pictureBox_main_object_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void main_table_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	  
	   // Font: 
	   // Height - междустрочный интервал
	   // Italic - курсив
	   // Underline - подчёркивание

private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_set_image_to_object_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MainForm_Resize(System::Object^ sender, System::EventArgs^ e);
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_recreate_main_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MainForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
private: System::Void button_finish_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	pictureBox2->Image = b;
}
};
}
