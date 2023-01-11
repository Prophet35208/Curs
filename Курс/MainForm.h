#pragma once
#include <math.h>
#include "Layer.h"
#include "SetMaket.h"
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
	private: System::Windows::Forms::Button^ button_finish;
	public:	PictureBox^ settings_form_picture_box;
	private:
		// Функция обновления порядка слоёв по индексу
		void RefreshTable() {
			for (int i = layer_list->Count-1; i >=0; i--)
			{
				layer_list[i]->GetPictureBox()->BringToFront();
			}
		}
	// Ширина и высота, которые передаются в форму SetMaket для обновления размеров макета в пискелях 
	private: Int64^ width=gcnew Int64(0);
	private: Int64^ height= gcnew Int64(0);
		// Радиус прилипания к краю макета
		int sticking_rad = 5;
		// Индикатор прилипания
		bool f_stick = false;
		// Текущий обрабатываемый picture box. Под обработкой понимать добавление элемента на макет и последующее создание слоя
		private: PictureBox^ current_picture_box;
		// Флаги для распознования вида создаваемого элемента
		int create_image = 0;
		int create_image_with_text = 0;
		int mouse_down = 0;
		// Прямоугольник, в котором сохраняется и после используется размер слоя
		Rectangle rectProposedSize = Rectangle::Empty;
		// Коллекция слоёв
		List<Layer^>^ layer_list = gcnew List<Layer^>();

	private: System::Windows::Forms::Button^ button_recreate_main;
	private: System::Windows::Forms::PictureBox^ main_element;
	private: System::Windows::Forms::Button^ button_set_image_to_object;
	private: System::Windows::Forms::PictureBox^ pictureBox_main_object;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_name;
	private: System::Windows::Forms::DataGridViewButtonColumn^ button_settings;
	private: System::Windows::Forms::DataGridViewButtonColumn^ up;
	private: System::Windows::Forms::DataGridViewButtonColumn^ down;
	private: System::Windows::Forms::DataGridViewButtonColumn^ delete_line;
	private: System::Windows::Forms::DataGridView^ main_table;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->button_create_picture = (gcnew System::Windows::Forms::Button());
			this->button_set_image_to_object = (gcnew System::Windows::Forms::Button());
			this->main_table = (gcnew System::Windows::Forms::DataGridView());
			this->Column_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button_settings = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->up = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->down = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->delete_line = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->pictureBox_main_object = (gcnew System::Windows::Forms::PictureBox());
			this->button_recreate_main = (gcnew System::Windows::Forms::Button());
			this->button_finish = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_object))->BeginInit();
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
			// pictureBox_main_object
			// 
			this->pictureBox_main_object->BackColor = System::Drawing::SystemColors::HighlightText;
			this->pictureBox_main_object->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox_main_object->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_main_object.Image")));
			this->pictureBox_main_object->Location = System::Drawing::Point(93, 93);
			this->pictureBox_main_object->MinimumSize = System::Drawing::Size(30, 30);
			this->pictureBox_main_object->Name = L"pictureBox_main_object";
			this->pictureBox_main_object->Size = System::Drawing::Size(523, 404);
			this->pictureBox_main_object->TabIndex = 5;
			this->pictureBox_main_object->TabStop = false;
			this->pictureBox_main_object->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseDown);
			this->pictureBox_main_object->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseMove);
			this->pictureBox_main_object->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseUp);
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
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1399, 661);
			this->Controls->Add(this->button_finish);
			this->Controls->Add(this->button_recreate_main);
			this->Controls->Add(this->pictureBox_main_object);
			this->Controls->Add(this->main_table);
			this->Controls->Add(this->button_set_image_to_object);
			this->Controls->Add(this->button_create_picture);
			this->Name = L"MainForm";
			this->Text = L"Главное меню";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::MainForm_Paint_1);
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_object))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
// Устанвока флагов для последующего создания слоя
private: System::Void button_create_picture_Click(System::Object^ sender, System::EventArgs^ e);
// Проверка состояния флагов и начало создания слоя. Обеспечено прилипание к границам макета при рисовании прямоугольника. В зависимости от наличия прилипания сазадётся начальная точка прямоугольника
private: System::Void pictureBox_main_object_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
// Рисвования пунктирного треугольника при движении зажатой мыши
private: System::Void pictureBox_main_object_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
// Заврешение обработки элемента макета
private: System::Void pictureBox_main_object_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
// Обработка нажатий по таблице. Таблица поддерживает настройку слоёв, смену их чередования и удаление
private: System::Void main_table_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
// Создания слоя с текстом
private: System::Void button_set_image_to_object_Click(System::Object^ sender, System::EventArgs^ e);
// Корректная обработка размера макета при изменение размера окна
private: System::Void MainForm_Resize(System::Object^ sender, System::EventArgs^ e);
// Корректная обработка размера окна в соответствии с размером макета
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
// Пересоздание макета с целью изменения его размеров
private: System::Void button_recreate_main_Click(System::Object^ sender, System::EventArgs^ e);
// Вызов формы для конечной обработки и сохранения
private: System::Void button_finish_Click(System::Object^ sender, System::EventArgs^ e);
// Корректная обработка размера макета при необходимости
private: System::Void MainForm_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
// Рисование экземпляра текста в слое с текстом. Текст статичен
private: System::Void LayerWitnText_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
};
}
