#pragma once

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
		// Начальные значения picture_box_main_form
		int first_top;
		int first_left;
		int first_right;
		int first_bottom;
		int starting_Width;
		Point first_rigth_bottom_point;
		//
		int resizing_mod=0;
		System::Drawing::Size^ startSize; 
		int starting_x = 0;
		int starting_y = 0;
		Point starting_location;
		int resizingMargin = 5;
		bool resizing_picture_box;	
		Point startDraggingPoint_1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


		   //
		System::Windows::Forms::Button^ button_121414;
		void MakeStringInTable();
		int creating_base = 0;
		int mouse_down = 0;
		Rectangle rectProposedSize = Rectangle::Empty;
		Point startDraggingPoint;
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_name;
	private: System::Windows::Forms::DataGridViewButtonColumn^ up;
	private: System::Windows::Forms::DataGridViewButtonColumn^ down;
	private: System::Windows::Forms::PictureBox^ pictureBox_main_object;

	private: System::Windows::Forms::DataGridView^ main_table;
		   //

	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			starting_location = pictureBox_main_object->Location;
			first_top = this->PointToScreen(pictureBox_main_object->Location).Y - this->PointToScreen(Point(0, 0)).Y;
			first_left = pictureBox_main_object->Location.X-Point(0,0).X;
			starting_Width = pictureBox_main_object->Size.Width;
			first_right = pictureBox_main_object->Right;
			first_bottom = pictureBox_main_object->Bottom;
			first_rigth_bottom_point = Point(pictureBox_main_object->Location.X + pictureBox_main_object->Width,
				pictureBox_main_object->Location.Y + pictureBox_main_object->Height);
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
			this->Column_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->up = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->down = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->contextMenuStrip_delete_main_element = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->удалитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox_main_object = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->BeginInit();
			this->contextMenuStrip_delete_main_element->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_object))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button_put_main_element
			// 
			this->button_put_main_element->Location = System::Drawing::Point(702, 25);
			this->button_put_main_element->Name = L"button_put_main_element";
			this->button_put_main_element->Size = System::Drawing::Size(97, 57);
			this->button_put_main_element->TabIndex = 0;
			this->button_put_main_element->Text = L"Создать главную";
			this->button_put_main_element->UseVisualStyleBackColor = true;
			this->button_put_main_element->Click += gcnew System::EventHandler(this, &MainForm::button_put_main_element_Click);
			// 
			// button_set_image_to_object
			// 
			this->button_set_image_to_object->Location = System::Drawing::Point(702, 88);
			this->button_set_image_to_object->Name = L"button_set_image_to_object";
			this->button_set_image_to_object->Size = System::Drawing::Size(97, 57);
			this->button_set_image_to_object->TabIndex = 3;
			this->button_set_image_to_object->Text = L"Установить изображение";
			this->button_set_image_to_object->UseVisualStyleBackColor = true;
			// 
			// main_table
			// 
			this->main_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->main_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column_name,
					this->up, this->down
			});
			this->main_table->Location = System::Drawing::Point(805, 12);
			this->main_table->Name = L"main_table";
			this->main_table->Size = System::Drawing::Size(445, 555);
			this->main_table->TabIndex = 4;
			// 
			// Column_name
			// 
			this->Column_name->HeaderText = L"Название слоя";
			this->Column_name->MaxInputLength = 30;
			this->Column_name->MinimumWidth = 70;
			this->Column_name->Name = L"Column_name";
			this->Column_name->Width = 200;
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
			this->pictureBox_main_object->Location = System::Drawing::Point(409, 238);
			this->pictureBox_main_object->MinimumSize = System::Drawing::Size(30, 30);
			this->pictureBox_main_object->Name = L"pictureBox_main_object";
			this->pictureBox_main_object->Size = System::Drawing::Size(98, 96);
			this->pictureBox_main_object->TabIndex = 5;
			this->pictureBox_main_object->TabStop = false;
			this->pictureBox_main_object->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseDown);
			this->pictureBox_main_object->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseMove);
			this->pictureBox_main_object->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseUp);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(76, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(103, 96);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
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
			creating_base = 1;
	}

// Удаление макета
private: System::Void удалитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	delete main_element;
	button_put_main_element->Enabled = 1;
}
private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
	mouse_down = 1;
	rectProposedSize.X = this->pictureBox_main_object->PointToScreen(e->Location).X;
	rectProposedSize.Y = this->pictureBox_main_object->PointToScreen(e->Location).Y;

	// Левый верхний угол
	if ((e->X >= 0 && e->X <= resizingMargin) &&
		(e->Y >= 0 && e->Y <= resizingMargin)) 
	{
		this->pictureBox_main_object->Cursor = Cursors::SizeNWSE;
		resizing_picture_box = true;
		resizing_mod = 1;
		// Привязывает курсор к границам доступной области
		this->Cursor->Clip = Rectangle(this->PointToScreen(Point(50, 50)), System::Drawing::Size(first_left -50, first_top -50));

	}
		
	// Верхняя часть
	if ((e->X > resizingMargin && e->X < pictureBox_main_object->Width - resizingMargin) &&
		(e->Y >= 0 && e->Y <= resizingMargin)) {
		resizing_picture_box = true;
		resizing_mod = 2;
	}
		

	// Правый верхний угол
	if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= pictureBox_main_object->Width) &&
		(e->Y >= 0 && e->Y <= resizingMargin)) {
		resizing_picture_box = true;
		resizing_mod = 3;
	}
	// Правая часть
	if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= pictureBox_main_object->Width) &&
		(e->Y > resizingMargin && e->Y < pictureBox_main_object->Height - resizingMargin)) {
		resizing_picture_box = true;
		resizing_mod = 4;
	}
	// Правый нижний угол
	if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= e->X <= pictureBox_main_object->Width) &&
		(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height)) {
		resizing_picture_box = true;
		resizing_mod = 5;
		this->Cursor->Clip = Rectangle(this->PointToScreen(first_rigth_bottom_point), System::Drawing::Size(first_right - 50, first_bottom - 50));
	}
	// Нижняя часть
	if ((e->X >= resizingMargin && e->X < pictureBox_main_object->Width - resizingMargin) &&
		(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height)) {
		resizing_picture_box = true;
		resizing_mod = 6;
	}
	// Нижний левый угол
	if ((e->X >= 0 && e->X <= resizingMargin) &&
		(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height)) {
		resizing_picture_box = true;
		resizing_mod = 7;
	}
	// Левая часть
	if ((e->X >= 0 && e->X <= resizingMargin) &&
		(e->Y > resizingMargin && e->Y < pictureBox_main_object->Height - resizingMargin)) {
		resizing_picture_box = true;
		resizing_mod = 8;
	}
	//

	starting_x = this->PointToScreen(e->Location).X;
	starting_y = this->PointToScreen(e->Location).Y;
}
private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
	if (mouse_down && creating_base) {
		if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0)
			ControlPaint::DrawReversibleFrame(rectProposedSize, this->ForeColor, FrameStyle::Dashed);
		// calculate rect new size
		rectProposedSize.Width = this->pictureBox_main_object->PointToScreen(e->Location).X - rectProposedSize.X;
		rectProposedSize.Height = this->pictureBox_main_object->PointToScreen(e->Location).Y - rectProposedSize.Y;
		// draw rect
		if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0)
			ControlPaint::DrawReversibleFrame(rectProposedSize, this->ForeColor, FrameStyle::Dashed);
	}

	if (resizing_picture_box!=true) {
		// Блок для изменения иконки мыши на границах picturebox 
		// Левый верхний угол
		if ((e->X >= 0 && e->X <= resizingMargin) &&
			(e->Y >= 0 && e->Y <= resizingMargin))
			pictureBox_main_object->Cursor = Cursors::SizeNWSE;
		
		// Правый нижний угол
		if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= e->X <= pictureBox_main_object->Width) &&
			(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height))
			pictureBox_main_object->Cursor = Cursors::SizeNWSE;
		// Центр
		if ((e->X > resizingMargin && e->X < pictureBox_main_object->Width - resizingMargin) &&
			(e->Y > resizingMargin && e->Y < pictureBox_main_object->Height - resizingMargin))
			pictureBox_main_object->Cursor = Cursors::Default;
		//
	}
	if (resizing_picture_box)
	{
		int delta_x=0;
		int delta_y=0;
		switch (resizing_mod)
		{
		case 1:
			 delta_x = this->PointToScreen(e->Location).X - starting_x;
			 delta_y = this->PointToScreen(e->Location).Y - starting_y;
			pictureBox_main_object->Top += delta_y;
			pictureBox_main_object->Left += delta_x;
			pictureBox_main_object->Height -= delta_y;
			pictureBox_main_object->Width -= delta_x;
			break;
		case 5:
			delta_x = this->PointToScreen(e->Location).X - starting_x;
			delta_y = this->PointToScreen(e->Location).Y - starting_y;
			pictureBox_main_object->Height =e->Y;
			pictureBox_main_object->Width = e->X;
			break;
		}
	}
}
private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->Cursor->Clip=Rectangle(Point(0, 0), System::Drawing::Size(10000, 10000));
	if (pictureBox_main_object->Height < 30) {
		pictureBox_main_object->Location = starting_location;
		pictureBox_main_object->Height = 30;
	}
	if (pictureBox_main_object->Width < 30) {
		pictureBox_main_object->Location = starting_location;
		pictureBox_main_object->Width = 30;
	}
	if (pictureBox_main_object->Top < 0) {
		pictureBox_main_object->Height += pictureBox_main_object->Top;
		pictureBox_main_object->Top = 0;
	}
	if (pictureBox_main_object->Left < 0) {
		pictureBox_main_object->Width += pictureBox_main_object->Left;
		pictureBox_main_object->Left = 0;
	}

	resizing_picture_box = 0;
	this->startDraggingPoint_1 = Point::Empty;
	this->Cursor = Cursors::Default;

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
		this->picture_list[picture_list->Count-1] = (gcnew System::Windows::Forms::PictureBox());
		this->picture_list[picture_list->Count - 1]->Location = Control::PointToClient(rectProposedSize.Location);
		this->picture_list[picture_list->Count - 1]->Name = L"pictureBox1";
		this->picture_list[picture_list->Count - 1]->Size = rectProposedSize.Size;
		this->picture_list[picture_list->Count - 1]->TabIndex = 1;
		this->picture_list[picture_list->Count - 1]->TabStop = false;
		this->picture_list[picture_list->Count - 1]->Image = image;
		this->Controls->Add(this->picture_list[picture_list->Count - 1]);
		this->picture_list[picture_list->Count - 1]->ContextMenuStrip = this->contextMenuStrip_delete_main_element;
		this->picture_list[picture_list->Count - 1]->BringToFront();
		// Передача макета в таблицу
		//
		rectProposedSize.Width = 0;
		rectProposedSize.Height = 0;



		creating_base = 0;
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	delete pictureBox_main_object;
}
};
}
