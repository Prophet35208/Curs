#pragma once
#include <math.h>
#include "SettingsForm.h"
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
	private:
		//
			// Необходимые переменные для корректного редкатирования размеров изображений (перетягиванием границ)
		// Радиус прилипания к краю макета
		int sticking_rad = 5;
		// Индикатор прилипания
		bool f_stick = false;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: PictureBox^ current_picture_box;
		   //
		System::Windows::Forms::Button^ button_121414;
		int creating_p_b = 0;
		int mouse_down = 0;
		Rectangle rectProposedSize = Rectangle::Empty;
		// Коллекция изображений без текста 
		List<System::Windows::Forms::PictureBox^>^ picture_list = gcnew List<System::Windows::Forms::PictureBox^>();
		// Коллекция изображений с текстом 
		List<System::Windows::Forms::PictureBox^>^ picture_and_words_list = gcnew List<System::Windows::Forms::PictureBox^>();
		//
	private: System::Windows::Forms::PictureBox^ main_element;
		//
	private: System::Windows::Forms::Button^ button_set_image_to_object;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip_delete_main_element;
	private: System::Windows::Forms::ToolStripMenuItem^ удалитьToolStripMenuItem;



	private: System::Windows::Forms::PictureBox^ pictureBox_main_object;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_name;
	private: System::Windows::Forms::DataGridViewButtonColumn^ button_settings;
	private: System::Windows::Forms::DataGridViewButtonColumn^ up;
	private: System::Windows::Forms::DataGridViewButtonColumn^ down;





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
	private: System::Windows::Forms::Button^ button_put_main_element;
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
			this->button_put_main_element = (gcnew System::Windows::Forms::Button());
			this->button_set_image_to_object = (gcnew System::Windows::Forms::Button());
			this->main_table = (gcnew System::Windows::Forms::DataGridView());
			this->contextMenuStrip_delete_main_element = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->удалитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox_main_object = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Column_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button_settings = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->up = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->down = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->BeginInit();
			this->contextMenuStrip_delete_main_element->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_object))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button_put_main_element
			// 
			this->button_put_main_element->Location = System::Drawing::Point(578, 42);
			this->button_put_main_element->Name = L"button_put_main_element";
			this->button_put_main_element->Size = System::Drawing::Size(97, 57);
			this->button_put_main_element->TabIndex = 0;
			this->button_put_main_element->Text = L"Создать главную";
			this->button_put_main_element->UseVisualStyleBackColor = true;
			this->button_put_main_element->Click += gcnew System::EventHandler(this, &MainForm::button_put_main_element_Click);
			// 
			// button_set_image_to_object
			// 
			this->button_set_image_to_object->Location = System::Drawing::Point(578, 105);
			this->button_set_image_to_object->Name = L"button_set_image_to_object";
			this->button_set_image_to_object->Size = System::Drawing::Size(97, 57);
			this->button_set_image_to_object->TabIndex = 3;
			this->button_set_image_to_object->Text = L"Установить изображение";
			this->button_set_image_to_object->UseVisualStyleBackColor = true;
			// 
			// main_table
			// 
			this->main_table->AllowUserToAddRows = false;
			this->main_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->main_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column_name,
					this->button_settings, this->up, this->down
			});
			this->main_table->Location = System::Drawing::Point(681, 12);
			this->main_table->Name = L"main_table";
			this->main_table->Size = System::Drawing::Size(544, 555);
			this->main_table->TabIndex = 4;
			this->main_table->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::main_table_CellContentClick);
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
			this->pictureBox_main_object->Location = System::Drawing::Point(255, 144);
			this->pictureBox_main_object->MinimumSize = System::Drawing::Size(30, 30);
			this->pictureBox_main_object->Name = L"pictureBox_main_object";
			this->pictureBox_main_object->Size = System::Drawing::Size(238, 267);
			this->pictureBox_main_object->TabIndex = 5;
			this->pictureBox_main_object->TabStop = false;
			this->pictureBox_main_object->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseDown);
			this->pictureBox_main_object->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseMove);
			this->pictureBox_main_object->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseUp);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(83, 114);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(103, 96);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
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
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1423, 656);
			this->Controls->Add(this->pictureBox_main_object);
			this->Controls->Add(this->main_table);
			this->Controls->Add(this->button_set_image_to_object);
			this->Controls->Add(this->button_put_main_element);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->EndInit();
			this->contextMenuStrip_delete_main_element->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_object))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_put_main_element_Click(System::Object^ sender, System::EventArgs^ e) {
		creating_p_b = 1;
	}

// Удаление макета
private: System::Void удалитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	delete contextMenuStrip_delete_main_element->SourceControl;

}
private: System::Void pictureBox_main_object_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	// Point a, b, c,d;
	// a = (e->Location); // Точка ставится от начала экрана (правый верхний угол)
	// b = this->PointToScreen(e->Location); // Точка ставится на экране как если бы отсчёт координат был от главной формы
	// c= this->pictureBox_main_object->PointToScreen(e->Location); // Точка ставится там, где был клик (начало координат от угла picture box)
	// d = this->PointToClient(e->Location); // Предположительно принимает абсолютные экранные координаты и преобразует в координаты члена, который этот метод вызвал
	// this->Cursor->Clip = Rectangle(d, System::Drawing::Size(1, 1));
	// System::Threading::Thread::Sleep(10000);
	current_picture_box=(PictureBox^)sender;
	
	
	f_stick=false;
	Point place_to_stick_pb_coorinates;
	Point place_to_stick;
	// Стик к левой части
	if (abs(e->Location.X) <= sticking_rad) {
		Rectangle OldRect = Cursor->Clip;
		place_to_stick_pb_coorinates = Point(0, e->Location.Y);
		place_to_stick = current_picture_box->PointToScreen(place_to_stick_pb_coorinates);
		Cursor->Clip = Rectangle(place_to_stick, System::Drawing::Size(1, 1));
		Cursor->Clip = OldRect;
		f_stick = true;
	}
	// Стик к верхней части
	if (abs(e->Location.Y) < sticking_rad) {
		Rectangle OldRect = Cursor->Clip;
		place_to_stick_pb_coorinates = Point(e->Location.X, 0);
		place_to_stick = current_picture_box->PointToScreen(place_to_stick_pb_coorinates);
		Cursor->Clip = Rectangle(place_to_stick, System::Drawing::Size(1, 1));
		Cursor->Clip = OldRect;
		f_stick = true;
	}
	// Стик к левому верхнему углу
	if ((abs(e->Location.X) <= sticking_rad) && (abs(e->Location.Y) < sticking_rad)) {
		Rectangle OldRect = Cursor->Clip;
		place_to_stick_pb_coorinates = Point(0, 0);
		place_to_stick = current_picture_box->PointToScreen(place_to_stick_pb_coorinates);
		Cursor->Clip = Rectangle(place_to_stick, System::Drawing::Size(1, 1));
		Cursor->Clip = OldRect;
		f_stick = true;
	}
	mouse_down = 1;
	if (f_stick) 
	{
		rectProposedSize.X = place_to_stick.X;
		rectProposedSize.Y = place_to_stick.Y;
	}
	else
	{

		rectProposedSize.X = current_picture_box->PointToScreen(e->Location).X;
		rectProposedSize.Y = current_picture_box->PointToScreen(e->Location).Y;
	}
	if (creating_p_b)
		if(f_stick)
		{
			Rectangle rect = Rectangle(place_to_stick, System::Drawing::Size(pictureBox_main_object->Width - place_to_stick_pb_coorinates.X, pictureBox_main_object->Height - place_to_stick_pb_coorinates.Y));
			pictureBox_main_object->Cursor->Clip = rect;
		}
		else
		{
			Rectangle rect = Rectangle(pictureBox_main_object->PointToScreen(e->Location), System::Drawing::Size(pictureBox_main_object->Width - e->Location.X, pictureBox_main_object->Height - e->Location.Y));
			pictureBox_main_object->Cursor->Clip = rect;
		}

}
private: System::Void pictureBox_main_object_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
	if (mouse_down && creating_p_b) {
		if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0)
			ControlPaint::DrawReversibleFrame(rectProposedSize, this->ForeColor, FrameStyle::Dashed);
		// calculate rect new size
		rectProposedSize.Width = current_picture_box->PointToScreen(e->Location).X - rectProposedSize.X;
		rectProposedSize.Height = current_picture_box->PointToScreen(e->Location).Y - rectProposedSize.Y;
		// draw rect
		if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0)
			ControlPaint::DrawReversibleFrame(rectProposedSize, this->ForeColor, FrameStyle::Dashed);
	}
}
private: System::Void pictureBox_main_object_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	mouse_down = 0;
	// Проверка положительная ли ширина прямоугольника
	if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0) {

		// erase rect
		ControlPaint::DrawReversibleFrame(rectProposedSize, this->ForeColor, FrameStyle::Dashed);

		// Создание главного элемента в прямоугольнике
		Bitmap^ image = gcnew Bitmap(rectProposedSize.Width, rectProposedSize.Height);
		for (int i = 0; i < image->Width; i++)
			for (int j = 0; j < image->Height; j++)
				image->SetPixel(i, j, Color::Black);


		//  Создание макета
		picture_list->Add(gcnew Windows::Forms::PictureBox);
		this->picture_list[picture_list->Count - 1] = (gcnew System::Windows::Forms::PictureBox());
		this->picture_list[picture_list->Count - 1]->Location = Control::PointToClient(rectProposedSize.Location);
		this->picture_list[picture_list->Count - 1]->Name = L"pictureBox1";
		this->picture_list[picture_list->Count - 1]->Size = rectProposedSize.Size;
		this->picture_list[picture_list->Count - 1]->TabIndex = 1;
		this->picture_list[picture_list->Count - 1]->TabStop = false;
		this->picture_list[picture_list->Count - 1]->Image = image;
		this->Controls->Add(this->picture_list[picture_list->Count - 1]);
		this->picture_list[picture_list->Count - 1]->ContextMenuStrip = this->contextMenuStrip_delete_main_element;
		this->picture_list[picture_list->Count - 1]->BringToFront();


		 this->picture_list[picture_list->Count - 1]->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseDown);
		 this->picture_list[picture_list->Count - 1]->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseMove);
		 this->picture_list[picture_list->Count - 1]->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseUp);
		// Передача макета в таблицу
		int f = 0;
		Int64 i=0;
		int j = 0;
		for (i = 1; i < 10000; i++) {
			f = 0;
			for (j = 1; j < main_table->RowCount; j++) {
				String^ st1 = gcnew String(main_table->Rows[j]->Cells[0]->Value->ToString());
				String^ st2 = gcnew String("Новое изображение " + i.ToString());
				if (main_table->Rows[j]->Cells[0]->Value->ToString() == ("Новое изображение " + i.ToString())) {
					f = 1;
					break;
				}
			}
			if (f);
			else
			{
				main_table->Rows->Add("Новое изображение " + i.ToString());
				break;
			}

		}
		//
		rectProposedSize.Width = 0;
		rectProposedSize.Height = 0;

		creating_p_b = 0;

	}
	this->pictureBox_main_object->Cursor->Clip = Rectangle(Point(0, 0), System::Drawing::Size(10000, 10000));
	current_picture_box = nullptr;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	delete pictureBox_main_object;
}
private: System::Void main_table_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->ColumnIndex == 1) {
		SettingsForm^ sf = gcnew SettingsForm();
		sf->ShowDialog();
	}

}
};
}
