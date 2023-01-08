#include <vector>
#include <string>
#include "SettingsForm.h"
#include "Finish.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace Курс;

[STAThread]
int main(cli::array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Курс::MainForm form;
	Application::Run(% form);
}
void OpenSettingsForm(int mod, Layer^ layer);
void MakePbTransparent(PictureBox^ down_pb, PictureBox^ upper_pb);
void DrawOnePbOnTopOfAnother(PictureBox^ down_pb, PictureBox^ upper_pb);
void DrawTextOnTheMiddleOfRectangleInPictureBox(PictureBox^ pb, Rectangle rect, Font^ font, String^ text, Graphics^ g);
System::Void Курс::MainForm::button_create_picture_Click(System::Object^ sender, System::EventArgs^ e)
{
	create_image = 1;
	create_image_with_text = 0;
}
System::Void Курс::MainForm::удалитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	delete contextMenuStrip_delete_main_element->SourceControl;

}
System::Void Курс::MainForm::pictureBox_main_object_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	// Point a, b, c,d;
	// a = (e->Location); // Точка ставится от начала экрана (правый верхний угол)
	// b = this->PointToScreen(e->Location); // Точка ставится на экране как если бы отсчёт координат был от главной формы
	// c= this->pictureBox_main_object->PointToScreen(e->Location); // Точка ставится там, где был клик (начало координат от угла picture box)
	// d = this->PointToClient(e->Location); // Предположительно принимает абсолютные экранные координаты и преобразует в координаты члена, который этот метод вызвал
	// this->Cursor->Clip = Rectangle(d, System::Drawing::Size(1, 1));
	// System::Threading::Thread::Sleep(10000);
	current_picture_box = (PictureBox^)sender;


	f_stick = false;
	Point place_to_stick_pb_coorinates;
	Point place_to_stick;
	// Прилипание к левой части
	if (abs(e->Location.X) <= sticking_rad) {
		Rectangle OldRect = Cursor->Clip;
		place_to_stick_pb_coorinates = Point(0, e->Location.Y);
		place_to_stick = current_picture_box->PointToScreen(place_to_stick_pb_coorinates);
		Cursor->Clip = Rectangle(place_to_stick, System::Drawing::Size(1, 1));
		Cursor->Clip = OldRect;
		f_stick = true;
	}
	// Прилипание к верхней части
	if (abs(e->Location.Y) < sticking_rad) {
		Rectangle OldRect = Cursor->Clip;
		place_to_stick_pb_coorinates = Point(e->Location.X, 0);
		place_to_stick = current_picture_box->PointToScreen(place_to_stick_pb_coorinates);
		Cursor->Clip = Rectangle(place_to_stick, System::Drawing::Size(1, 1));
		Cursor->Clip = OldRect;
		f_stick = true;
	}
	// Прилипание к левому верхнему углу
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
	if (create_image || create_image_with_text)
		if (f_stick)
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
System::Void Курс::MainForm::pictureBox_main_object_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{

	if (mouse_down && create_image || mouse_down && create_image_with_text) {
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
System::Void Курс::MainForm::pictureBox_main_object_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	this->pictureBox_main_object->Cursor->Clip = Rectangle(Point(0, 0), System::Drawing::Size(10000, 10000));
	mouse_down = 0;
	// Проверка положительная ли ширина прямоугольника
	if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0) {

		// erase rect
		ControlPaint::DrawReversibleFrame(rectProposedSize, this->ForeColor, FrameStyle::Dashed);

		// Создание  элемента в прямоугольнике
		Bitmap^ image = gcnew Bitmap(rectProposedSize.Width, rectProposedSize.Height);
		for (int i = 0; i < image->Width; i++)
			for (int j = 0; j < image->Height; j++)
				image->SetPixel(i, j, Color::Black);
		


		//  Создание экземпляра слоя и приведение его характеристик. Создаётся либо изображение с текстом, либо без него. В начале изображение чёрное
		PictureBox^ pb = gcnew PictureBox();

		pb = (gcnew System::Windows::Forms::PictureBox());
		pb->Location = Control::PointToClient(rectProposedSize.Location);
		pb->Name = L"pictureBox1";
		pb->Size = rectProposedSize.Size;
		pb->TabIndex = 1;
		pb->TabStop = false;
		pb->Image = image;
		pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		Controls->Add(pb);
		pb->ContextMenuStrip = this->contextMenuStrip_delete_main_element;
		pb->BringToFront();


		pb->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseDown);
		pb->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseMove);
		pb->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_main_object_MouseUp);
		// Запуск окна с возможностью отредактировать элемент
		if (create_image) {
			layer_list->Insert(0, (% Layer(pb, layer_list->Count + 2)));
			OpenSettingsForm(1, layer_list[0]);
		}
		if (create_image_with_text) {
			//
			layer_list->Insert(0, (% Layer(pb, layer_list->Count + 2,0)));
			OpenSettingsForm(2, layer_list[0]);
		}



		// Передача слоя в таблицу


		int f = 0;
		Int64 i = 0;
		int j = 0;
		for (i = 1; i < 10000; i++) {
			f = 0;
			for (j = 1; j < main_table->RowCount; j++) {
				String^ st1 = gcnew String(main_table->Rows[j]->Cells[0]->Value->ToString());
				String^ st2 = gcnew String("Новый слой " + i.ToString());
				if (main_table->Rows[j]->Cells[0]->Value->ToString() == ("Новый слой " + i.ToString())) {
					f = 1;
					break;
				}
			}
			if (f);
			else
			{
				main_table->Rows->Insert(1, "Новый слой " + i.ToString());
				break;
			}

		}
		//
		rectProposedSize.Width = 0;
		rectProposedSize.Height = 0;

		create_image = 0;
		create_image_with_text = 0;

	}
	current_picture_box = nullptr;
}
System::Void Курс::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	delete pictureBox_main_object;
}
System::Void Курс::MainForm::main_table_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (e->RowIndex != 0) {
		if (e->ColumnIndex == 1) {
			if(layer_list[e->RowIndex - 1]->HaveText())
				OpenSettingsForm(1,layer_list[e->RowIndex - 1]);
			else
				OpenSettingsForm(2,layer_list[e->RowIndex - 1]);
		}
		if (e->ColumnIndex == 2) {
			if (e->RowIndex > 1) {
				// Изменение в таблице
				DataGridViewRow^ buf = main_table->Rows[e->RowIndex];
				main_table->Rows->Remove(buf);
				main_table->Rows->Insert(e->RowIndex - 1, buf);
				main_table->ClearSelection();
				main_table->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Selected = true;
				// Изменение в списке
				Layer^ bufl;
				bufl = layer_list[e->RowIndex-1];
				bufl->GetUp();
				layer_list->RemoveAt(e->RowIndex-1);
				layer_list->Insert(e->RowIndex-2, bufl);
				RefreshTable();

			}
		}
		if (e->ColumnIndex == 3) {
			if (e->RowIndex < layer_list->Count) {
				// Изменение в таблице
				DataGridViewRow^ buf = main_table->Rows[e->RowIndex];
				main_table->Rows->Remove(buf);
				main_table->Rows->Insert(e->RowIndex + 1, buf);

				main_table->ClearSelection();
				main_table->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Selected = true;
				// Изменение в списке
				Layer^ bufl;
				bufl = layer_list[e->RowIndex - 1];
				bufl->GetDown();
				layer_list->RemoveAt(e->RowIndex - 1);
				layer_list->Insert(e->RowIndex, bufl);
				RefreshTable();
			}
		}
		if (e->ColumnIndex == 4) {
			delete layer_list[e->RowIndex - 1]->GetPictureBox();
			layer_list->Remove(layer_list[e->RowIndex - 1]);
			main_table->Rows->RemoveAt(e->RowIndex);
		}
	}
}
System::Void Курс::MainForm::pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Graphics^ g = pictureBox1->CreateGraphics();
	StringFormat sf;
	sf.LineAlignment = StringAlignment::Center;
	sf.Alignment = StringAlignment::Center;
	Pen^ bluePen = gcnew Pen(Color::Blue, 1.0f);
	System::Drawing::Font^ fn = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 12.0F, FontStyle::Bold);

	SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
	Point a(100, 100);
	Rectangle^ rec = gcnew Rectangle();
	g->DrawString("afafawfawfawfaffafaf", fn, drawBrush, a, % sf);
	this->pictureBox1->Cursor->Clip = Rectangle(this->pictureBox1->PointToScreen(Point(100, 100)), System::Drawing::Size(1, 1)); 
}
System::Void Курс::MainForm::button_set_image_to_object_Click(System::Object^ sender, System::EventArgs^ e)
{
	create_image_with_text = 1;
	create_image = 0;

}
System::Void Курс::MainForm::MainForm_Resize(System::Object^ sender, System::EventArgs^ e)
{
	pictureBox_main_object->Left = (ClientSize.Width-main_table->Width) / 2 - pictureBox_main_object->Width / 2;
	pictureBox_main_object->Top = ClientSize.Height / 2 - pictureBox_main_object->Height / 2;
	main_table->Size.Height = this->Height - 56;

}
System::Void Курс::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	pictureBox_main_object->Left = (ClientSize.Width - main_table->Width) / 2 - pictureBox_main_object->Width / 2;
	pictureBox_main_object->Top = ClientSize.Height / 2 - pictureBox_main_object->Height / 2;
	this->MinimumSize = System::Drawing::Size(200 + pictureBox_main_object->Width+main_table->Width, 200 + pictureBox_main_object->Height);
}
System::Void Курс::MainForm::button_recreate_main_Click(System::Object^ sender, System::EventArgs^ e)
{
	layer_list->Clear();
	main_table->Rows->Clear();
	main_table->Rows->Add("Макет");
	SetMaket^ sm = gcnew SetMaket();
	sm->height = height;
	sm->width = width;
	sm->ShowDialog();
	if (*height != 0 && *width != 0) {
		pictureBox_main_object->Height = *height;
		pictureBox_main_object->Width = *width;
	}
	this->Validate();

}
System::Void Курс::MainForm::MainForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	pictureBox_main_object->Left = (ClientSize.Width - main_table->Width) / 2 - pictureBox_main_object->Width / 2;
	pictureBox_main_object->Top = ClientSize.Height / 2 - pictureBox_main_object->Height / 2;
	this->MinimumSize = System::Drawing::Size(200 + pictureBox_main_object->Width + main_table->Width, 200 + pictureBox_main_object->Height);
}
System::Void Курс::MainForm::button_finish_Click(System::Object^ sender, System::EventArgs^ e)
{ // Определение минимального кол-ва строк среди всех слоёв со строками. Жто число определяет ко-во финальных копий
	List<PictureBox^>^ pb_list = gcnew List<PictureBox^>();
	int max_str = 0;
	// Копия макета
	PictureBox^ maket_clone = gcnew PictureBox();
	maket_clone->Image = pictureBox_main_object->Image;
	maket_clone->Location = pictureBox_main_object->Location;
	maket_clone->Size = pictureBox_main_object->Size;
	maket_clone->Visible = 0;
	Controls->Add(maket_clone);
	for (size_t i = 0; i < layer_list->Count; i++)
	{
		if (layer_list[i]->HaveText()) {
			if (max_str == 0)
				max_str = layer_list[i]->GetStringList()->Count;
			if (layer_list[i]->GetStringList()->Count < max_str)
				max_str = layer_list[i]->GetStringList()->Count;

		}
	}
	if (max_str != 0) {
		for (size_t i = 0; i < max_str; i++)
		{
			PictureBox^ pb = gcnew PictureBox();
			Graphics^ g = pb->CreateGraphics();
			pb->Size = maket_clone->Size;
			for (size_t j = 0; j < layer_list->Count; j++) {
				if(layer_list[j]->HaveText())
					// Рисование текста с фоном
					if (*(layer_list[j]->GetTextHaveBackground())) {
						DrawOnePbOnTopOfAnother(maket_clone, layer_list[j]->GetPictureBox());
						// Прямоугольник, в котором нарисовать текст. Определяется относительно макета (pictureBOx_main_object)
						Rectangle^ rect = gcnew Rectangle(maket_clone->PointToClient(layer_list[j]->GetPictureBox()->PointToScreen(Point(0, 0))),layer_list[j]->GetPictureBox()->Size);
						//DrawTextOnTheMiddleOfRectangleInPictureBox(maket_clone, *rect, layer_list[j]->GetFont(), layer_list[j]->GetStringList()[i]);
					}
					else
						// Рисование текста без фона
					{
						Rectangle^ rect = gcnew Rectangle(maket_clone->PointToClient(layer_list[j]->GetPictureBox()->PointToScreen(Point(0, 0))), layer_list[j]->GetPictureBox()->Size);
						//DrawTextOnTheMiddleOfRectangleInPictureBox(maket_clone, *rect, layer_list[j]->GetFont(), layer_list[j]->GetStringList()[i]);
					}
				else
					// Рисование фона
				{
					DrawOnePbOnTopOfAnother(maket_clone, layer_list[j]->GetPictureBox());
				}
			}
			// Теперь добавление одного из готовых конечных изображений в конечный массив
			pb_list->Add(maket_clone);
		}
		Finish^ f = gcnew Finish();
		f->pb_list = pb_list;
		f->ShowDialog();
	}
}
System::Void Курс::MainForm::button1_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	f = 1;
	pictureBox2->Invalidate();

}

System::Void Курс::MainForm::pictureBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	if (f == 1) {
		Drawing::Font^ f = gcnew Drawing::Font("Arial", 16);
		DrawOnePbOnTopOfAnother(pictureBox2, pictureBox3);
		DrawTextOnTheMiddleOfRectangleInPictureBox(pictureBox2, Rectangle((Point(0, 0)), pictureBox2->Size), f, "afafafawfafafwafaf", e->Graphics);
	}
}

void OpenSettingsForm(int mod ,Layer^ layer) {
	int num_str=0;
	SettingsForm^ sf = gcnew SettingsForm();
	sf->current_picture_box = layer->GetPictureBox();
	sf->mod = mod;
	sf->pictureBox_main->Image = layer->GetPictureBox()->Image;
	sf->pictureBox_main->Size = layer->GetPictureBox()->Size;
	sf->cur_font = layer->GetFont();
	sf->current_str_list = layer->GetStringList();
	sf->background_check = layer->GetTextHaveBackground();
	sf->num_str = &num_str;
	sf->ShowDialog();
	layer->SetNumStr(num_str);
}
// Позволяет сделать изображения верхнего Pb таким, чтобы он сливался с нижним Pb (Нужно переопределить, если буду пользоваться. Пока что это эксперементальная функция)
void DrawOnePbFropDownAnother(PictureBox^ down_pb, PictureBox^ upper_pb) {
	PictureBox^ pb_cur = upper_pb;
	Point p;
	Bitmap^ image = gcnew Bitmap(pb_cur->Width, pb_cur->Height);
	float stretch_X = down_pb->Image->Width / (float)down_pb->Width;
	float stretch_Y = down_pb->Image->Height / (float)down_pb->Height;
	for (int i = 0; i < pb_cur->Width; i++)
		for (int j = 0; j < pb_cur->Height; j++) {
			p = Point(i, j);
			Color c = ((Bitmap^)down_pb->Image)->GetPixel((down_pb->PointToClient(upper_pb->PointToScreen(p))).X * stretch_X, down_pb->PointToClient(upper_pb->PointToScreen(p)).Y * stretch_Y);
			image->SetPixel(i, j, c);
		}
	pb_cur->Image = image;
}
// Рисует одно изображение поверх другого. Если 
void DrawOnePbOnTopOfAnother(PictureBox^ down_pb, PictureBox^ upper_pb) {
	// Создание Bitmap-ов, соразмерных picturebox-ам. В них загружается соответствующее изображение
	Bitmap^ upper_bm = gcnew Bitmap(upper_pb->Image, upper_pb->Size);
	Bitmap^ down_bm = gcnew Bitmap(down_pb->Image, down_pb->Size);

	// Рисование одного Bitmap-а поверх другого (верхний поверх нижнего). Рисование относительного их 
	Point start(down_pb->PointToClient(upper_pb->PointToScreen(Point(0,0))));
		for (int i = 0; i < upper_bm->Width; i++)
			for (int j = 0; j < upper_bm->Height; j++) {
				if(i + start.X<down_bm->Width&& j + start.Y<down_bm->Height)
					down_bm->SetPixel(i + start.X, j + start.Y, upper_bm->GetPixel(i, j));
			}
	// Конечная установка изображения
		down_pb->Image = down_bm;
}
// Рисует строку в picture box-e, по центру предложенного прямоугольника (Location прямоугольника предоставляется относительно угла picture box) с заданным font
void DrawTextOnTheMiddleOfRectangleInPictureBox(PictureBox^ pb,Rectangle rect,Font^ font, String^ text,Graphics^ g) {
	SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
	StringFormat ^sf=gcnew StringFormat();
	sf->LineAlignment = StringAlignment::Center;
	sf->Alignment = StringAlignment::Center;
	g->DrawString(text, font, drawBrush, rect, sf);

}
/* Переменные для ратягивания
		int first_top;
		int first_left;
		int first_right;
		int first_bottom;
		int starting_Width;
		Point first_rigth_bottom_point;
		
		starting_location = pictureBox_main_object->Location;
			first_top = this->PointToScreen(pictureBox_main_object->Location).Y - this->PointToScreen(Point(0, 0)).Y;
			first_left = pictureBox_main_object->Location.X-Point(0,0).X;
			starting_Width = pictureBox_main_object->Size.Width;
			first_right = pictureBox_main_object->Right;
			first_bottom = pictureBox_main_object->Bottom;
			first_rigth_bottom_point = Point(pictureBox_main_object->Location.X + pictureBox_main_object->Width,
				pictureBox_main_object->Location.Y + pictureBox_main_object->Height);

				// Начальные значения picture_box_main_form
		//
		int resizing_mod=0;
		System::Drawing::Size^ startSize;
		int starting_x = 0;
		int starting_y = 0;
		Point starting_location;
		int resizingMargin = 5;
		bool resizing_picture_box;
		Point startDraggingPoint_1;
*/
/* Достпу к datagridview
* dataGridView.Rows[0].Cells[2].Value = recipe;
*/
/*Стик к нижней и правой частям
	// Стик к правой части
	if (abs(e->Location.X - pictureBox_main_object->Width) < sticking_rad) {
		Rectangle OldRect = Cursor->Clip;
		place_to_stick_pb_coorinates = Point(pictureBox_main_object->Width, e->Location.Y);
		place_to_stick = pictureBox_main_object->PointToScreen(Point(pictureBox_main_object->Width, e->Location.Y));
		Cursor->Clip = Rectangle(place_to_stick, System::Drawing::Size(1, 1));
		Cursor->Clip = OldRect;
		f_stick = true;
	}

		// Стик к нижней части
	if (abs(e->Location.Y - pictureBox_main_object->Height) < sticking_rad) {
		Rectangle OldRect = Cursor->Clip;
		place_to_stick_pb_coorinates = Point(e->Location.X, pictureBox_main_object->Height);
		place_to_stick = pictureBox_main_object->PointToScreen(Point(e->Location.X, pictureBox_main_object->Height));
		Cursor->Clip = Rectangle(place_to_stick, System::Drawing::Size(1, 1));
		Cursor->Clip = OldRect;
		f_stick = true;
	}
*/
/*
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
*/
/*Рисование на форме по кнопке
    private: System::Void MainForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        mouse_down = 1;
        rectProposedSize.X = Control::PointToScreen(e->Location).X;
        rectProposedSize.Y = Control::PointToScreen(e->Location).Y;

    }

        private: System::Void MainForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        if (mouse_down&& creating_base) {
            if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0)
                ControlPaint::DrawReversibleFrame(rectProposedSize, this->ForeColor, FrameStyle::Dashed);
            // calculate rect new size
            rectProposedSize.Width = Control::PointToScreen(e->Location).X- rectProposedSize.X;
            rectProposedSize.Height = Control::PointToScreen(e->Location).Y- rectProposedSize.Y;
            // draw rect
            if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0)
                ControlPaint::DrawReversibleFrame(rectProposedSize, this->ForeColor, FrameStyle::Dashed);
        }
    }

		private: System::Void MainForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
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
			// Передача макета в таблицу
			//
			rectProposedSize.Width = 0;
			rectProposedSize.Height = 0;


			creating_base = 0;
		}
	}
*/
/*// Блок для изменения иконки мыши на границах picturebox 
		// Левый верхний угол
		if ((e->X >= 0 && e->X <= resizingMargin) &&
			(e->Y >= 0 && e->Y <= resizingMargin))
			pictureBox_main_object->Cursor = Cursors::SizeNWSE;
		// Верхняя часть
		if ((e->X > resizingMargin && e->X < pictureBox_main_object->Width - resizingMargin) &&
			(e->Y >= 0 && e->Y <= resizingMargin))
			pictureBox_main_object->Cursor = Cursors::SizeNS;
		// Правый верхний угол
		if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= pictureBox_main_object->Width) &&
			(e->Y >= 0 && e->Y <= resizingMargin))
			pictureBox_main_object->Cursor = Cursors::SizeNESW;
		// Правая часть
		if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= pictureBox_main_object->Width) &&
			(e->Y > resizingMargin && e->Y < pictureBox_main_object->Height - resizingMargin))
			pictureBox_main_object->Cursor = Cursors::SizeWE;
		// Правый нижний угол
		if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= e->X <= pictureBox_main_object->Width) &&
			(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height))
			pictureBox_main_object->Cursor = Cursors::SizeNWSE;
		// Нижняя часть
		if ((e->X >= resizingMargin && e->X < pictureBox_main_object->Width - resizingMargin) &&
			(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height))
			pictureBox_main_object->Cursor = Cursors::SizeNS;
		// Нижний левый угол
		if ((e->X >= 0 && e->X <= resizingMargin) &&
			(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height))
			pictureBox_main_object->Cursor = Cursors::SizeNESW;
		// Левая часть
		if ((e->X >= 0 && e->X <= resizingMargin) &&
			(e->Y > resizingMargin && e->Y < pictureBox_main_object->Height - resizingMargin))
			pictureBox_main_object->Cursor = Cursors::SizeWE;
		// Центр
		if ((e->X > resizingMargin && e->X < pictureBox_main_object->Width - resizingMargin) &&
			(e->Y > resizingMargin && e->Y < pictureBox_main_object->Height - resizingMargin))
			pictureBox_main_object->Cursor = Cursors::Default;
		//*/
/*// Левый верхний угол
	if ((e->X >= 0 && e->X <= resizingMargin) &&
		(e->Y >= 0 && e->Y <= resizingMargin))
		MessageBox::Show("");
	// Верхняя часть
	if ((e->X > resizingMargin && e->X < dragged_picture_box->Width - resizingMargin) &&
		(e->Y >= 0 && e->Y <= resizingMargin))
		MessageBox::Show("Верхняя часть");
	// Правый верхний угол
	if ((e->X >= dragged_picture_box->Width - resizingMargin && e->X <= dragged_picture_box->Width) &&
		(e->Y >= 0 && e->Y <= resizingMargin))
		MessageBox::Show("Правый верхний угол");
	// Правая часть
	if ((e->X >= dragged_picture_box->Width - resizingMargin && e->X <= dragged_picture_box->Width) &&
		(e->Y> resizingMargin && e->Y< dragged_picture_box->Height-resizingMargin))
		MessageBox::Show("Правая часть");
	// Правый нижний угол
	if ((e->X>=dragged_picture_box->Width - resizingMargin && e->X<= e->X <= dragged_picture_box->Width) &&
		(e->Y>= dragged_picture_box->Height - resizingMargin && e->Y<= dragged_picture_box->Height))
		MessageBox::Show("Правый нижный угол");
	// Нижняя часть
	if((e->X>=resizingMargin && e->X< dragged_picture_box->Width - resizingMargin) &&
		(e->Y>= dragged_picture_box->Height - resizingMargin && e->Y<= dragged_picture_box->Height))
		MessageBox::Show("Нижняя часть");
	// Нижний левый угол
	if ((e->X>=0&&e->X<= resizingMargin)&&
		(e->Y>= dragged_picture_box->Height - resizingMargin&&e->Y<= dragged_picture_box->Height))
		MessageBox::Show("Нижний левый угол");
	// Левая часть
	if ((e->X>=0&&e->X<= resizingMargin)&&
		(e->Y> resizingMargin&&e->Y< dragged_picture_box->Height - resizingMargin))
		MessageBox::Show("Левая часть");
	//*/
/*private void button1_MouseDown(object sender, MouseEventArgs e)
        {
            draggedPiece = sender as Control;

            if ((e.X <= resizingMargin) || (e.X >= draggedPiece.Width - resizingMargin) ||
                (e.Y <= resizingMargin) || (e.Y >= draggedPiece.Height - resizingMargin))
            {
                resizing = true;

                // indicate resizing
                this.Cursor = Cursors.SizeNWSE;

                // starting size
                this.startSize = new Size(e.X, e.Y);
                // get the location of the picture box
                Point pt = this.PointToScreen(draggedPiece.Location);
                rectProposedSize = new Rectangle(pt, startSize);
                // draw rect
                ControlPaint.DrawReversibleFrame(rectProposedSize, this.ForeColor, FrameStyle.Dashed);
            }
            else
            {
                resizing = false;
                // indicate moving
                this.Cursor = Cursors.SizeAll;
            }

            // start point location
            this.startDraggingPoint = e.Location;
        }


        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
    }

        private void button1_MouseMove(object sender, MouseEventArgs e)
        {
            if (draggedPiece != null)
            {
                if (resizing)
                {
                    // erase rect
                    if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0)
                        ControlPaint.DrawReversibleFrame(rectProposedSize, this.ForeColor, FrameStyle.Dashed);
                    // calculate rect new size
                    rectProposedSize.Width = e.X - this.startDraggingPoint.X + this.startSize.Width;
                    rectProposedSize.Height = e.Y - this.startDraggingPoint.Y + this.startSize.Height;
                    // draw rect
                    if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0)
                        ControlPaint.DrawReversibleFrame(rectProposedSize, this.ForeColor, FrameStyle.Dashed);
                }
                else
                {
                    Point pt;
                    if (draggedPiece == sender)
                        pt = new Point(e.X, e.Y);
                    else
                        pt = draggedPiece.PointToClient((sender as Control).PointToScreen(new Point(e.X, e.Y)));

                    draggedPiece.Left += pt.X - this.startDraggingPoint.X;
                    draggedPiece.Top += pt.Y - this.startDraggingPoint.Y;
                }
            }
        }

        private void button1_MouseUp(object sender, MouseEventArgs e)
        {
            if (resizing)
            {
                if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0)
                {
                    // erase rect
                    ControlPaint.DrawReversibleFrame(rectProposedSize, this.ForeColor, FrameStyle.Dashed);
                }
                // compare to min width and size ?
                if (rectProposedSize.Width > 10 && rectProposedSize.Height > 10)
                {
                    // set size 
                    this.draggedPiece.Size = rectProposedSize.Size;
                }
                else
                {
                    // you might want to set some minimal size here
                    this.draggedPiece.Size = new Size((int)Math.Max(10, rectProposedSize.Width), Math.Max(10, rectProposedSize.Height));
                }
            }

            this.draggedPiece = null;
            this.startDraggingPoint = Point.Empty;
            this.Cursor = Cursors.Default;
        }*/

