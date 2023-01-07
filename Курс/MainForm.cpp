#include <vector>
#include <string>
#include "SettingsForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace ����;

[STAThread]
int main(cli::array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	����::MainForm form;
	Application::Run(% form);
}
void OpenSettingsForm(int mod, Layer^ layer);
void MakePbTransparent(PictureBox^ down_pb, PictureBox^ upper_pb);
System::Void ����::MainForm::button_create_picture_Click(System::Object^ sender, System::EventArgs^ e)
{
	create_image = 1;
	create_image_with_text = 0;
}
System::Void ����::MainForm::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	delete contextMenuStrip_delete_main_element->SourceControl;

}
System::Void ����::MainForm::pictureBox_main_object_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	// Point a, b, c,d;
	// a = (e->Location); // ����� �������� �� ������ ������ (������ ������� ����)
	// b = this->PointToScreen(e->Location); // ����� �������� �� ������ ��� ���� �� ������ ��������� ��� �� ������� �����
	// c= this->pictureBox_main_object->PointToScreen(e->Location); // ����� �������� ���, ��� ��� ���� (������ ��������� �� ���� picture box)
	// d = this->PointToClient(e->Location); // ���������������� ��������� ���������� �������� ���������� � ����������� � ���������� �����, ������� ���� ����� ������
	// this->Cursor->Clip = Rectangle(d, System::Drawing::Size(1, 1));
	// System::Threading::Thread::Sleep(10000);
	current_picture_box = (PictureBox^)sender;


	f_stick = false;
	Point place_to_stick_pb_coorinates;
	Point place_to_stick;
	// ���������� � ����� �����
	if (abs(e->Location.X) <= sticking_rad) {
		Rectangle OldRect = Cursor->Clip;
		place_to_stick_pb_coorinates = Point(0, e->Location.Y);
		place_to_stick = current_picture_box->PointToScreen(place_to_stick_pb_coorinates);
		Cursor->Clip = Rectangle(place_to_stick, System::Drawing::Size(1, 1));
		Cursor->Clip = OldRect;
		f_stick = true;
	}
	// ���������� � ������� �����
	if (abs(e->Location.Y) < sticking_rad) {
		Rectangle OldRect = Cursor->Clip;
		place_to_stick_pb_coorinates = Point(e->Location.X, 0);
		place_to_stick = current_picture_box->PointToScreen(place_to_stick_pb_coorinates);
		Cursor->Clip = Rectangle(place_to_stick, System::Drawing::Size(1, 1));
		Cursor->Clip = OldRect;
		f_stick = true;
	}
	// ���������� � ������ �������� ����
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
System::Void ����::MainForm::pictureBox_main_object_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
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
System::Void ����::MainForm::pictureBox_main_object_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	this->pictureBox_main_object->Cursor->Clip = Rectangle(Point(0, 0), System::Drawing::Size(10000, 10000));
	mouse_down = 0;
	// �������� ������������� �� ������ ��������������
	if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0) {

		// erase rect
		ControlPaint::DrawReversibleFrame(rectProposedSize, this->ForeColor, FrameStyle::Dashed);

		// ��������  �������� � ��������������
		Bitmap^ image = gcnew Bitmap(rectProposedSize.Width, rectProposedSize.Height);
		for (int i = 0; i < image->Width; i++)
			for (int j = 0; j < image->Height; j++)
				image->SetPixel(i, j, Color::Black);
		


		//  �������� ���������� ���� � ���������� ��� �������������. �������� ���� ����������� � �������, ���� ��� ����. � ������ ����������� ������
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
		// ������ ���� � ������������ ��������������� �������
		if (create_image) {
			layer_list->Insert(0, (% Layer(pb, layer_list->Count + 2)));
			OpenSettingsForm(1, layer_list[0]);
		}
		if (create_image_with_text) {
			//
			layer_list->Insert(0, (% Layer(pb, layer_list->Count + 2)));
			OpenSettingsForm(2, layer_list[0]);
		}



		// �������� ���� � �������


		int f = 0;
		Int64 i = 0;
		int j = 0;
		for (i = 1; i < 10000; i++) {
			f = 0;
			for (j = 1; j < main_table->RowCount; j++) {
				String^ st1 = gcnew String(main_table->Rows[j]->Cells[0]->Value->ToString());
				String^ st2 = gcnew String("����� ���� " + i.ToString());
				if (main_table->Rows[j]->Cells[0]->Value->ToString() == ("����� ���� " + i.ToString())) {
					f = 1;
					break;
				}
			}
			if (f);
			else
			{
				main_table->Rows->Insert(1, "����� ���� " + i.ToString());
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
System::Void ����::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	delete pictureBox_main_object;
}
System::Void ����::MainForm::main_table_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
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
				// ��������� � �������
				DataGridViewRow^ buf = main_table->Rows[e->RowIndex];
				main_table->Rows->Remove(buf);
				main_table->Rows->Insert(e->RowIndex - 1, buf);
				main_table->ClearSelection();
				main_table->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Selected = true;
				// ��������� � ������
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
				// ��������� � �������
				DataGridViewRow^ buf = main_table->Rows[e->RowIndex];
				main_table->Rows->Remove(buf);
				main_table->Rows->Insert(e->RowIndex + 1, buf);

				main_table->ClearSelection();
				main_table->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Selected = true;
				// ��������� � ������
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
System::Void ����::MainForm::pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void ����::MainForm::button_set_image_to_object_Click(System::Object^ sender, System::EventArgs^ e)
{
	create_image_with_text = 1;
	create_image = 0;

}
System::Void ����::MainForm::pictureBox4_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	
}
void OpenSettingsForm(int mod ,Layer^ layer) {
	SettingsForm^ sf = gcnew SettingsForm();
	sf->current_picture_box = layer->GetPictureBox();
	sf->mod = mod;
	sf->pictureBox_main->Image = layer->GetPictureBox()->Image;
	sf->pictureBox_main->Size = layer->GetPictureBox()->Size;
	sf->cur_font = layer->GetFont();
	sf->str_list = layer->GetStringList();
	sf->ShowDialog();
}
// ��������� ������� ����������� �������� Pb �����, ����� �� �������� � ������ Pb
void MakePbTransparent(PictureBox^ down_pb, PictureBox^ upper_pb) {
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
/* ���������� ��� �����������
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

				// ��������� �������� picture_box_main_form
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
/* ������ � datagridview
* dataGridView.Rows[0].Cells[2].Value = recipe;
*/
/*���� � ������ � ������ ������
	// ���� � ������ �����
	if (abs(e->Location.X - pictureBox_main_object->Width) < sticking_rad) {
		Rectangle OldRect = Cursor->Clip;
		place_to_stick_pb_coorinates = Point(pictureBox_main_object->Width, e->Location.Y);
		place_to_stick = pictureBox_main_object->PointToScreen(Point(pictureBox_main_object->Width, e->Location.Y));
		Cursor->Clip = Rectangle(place_to_stick, System::Drawing::Size(1, 1));
		Cursor->Clip = OldRect;
		f_stick = true;
	}

		// ���� � ������ �����
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

	// ����� ������� ����
	if ((e->X >= 0 && e->X <= resizingMargin) &&
		(e->Y >= 0 && e->Y <= resizingMargin))
	{
		this->pictureBox_main_object->Cursor = Cursors::SizeNWSE;
		resizing_picture_box = true;
		resizing_mod = 1;
		// ����������� ������ � �������� ��������� �������
		this->Cursor->Clip = Rectangle(this->PointToScreen(Point(50, 50)), System::Drawing::Size(first_left -50, first_top -50));

	}

	// ������� �����
	if ((e->X > resizingMargin && e->X < pictureBox_main_object->Width - resizingMargin) &&
		(e->Y >= 0 && e->Y <= resizingMargin)) {
		resizing_picture_box = true;
		resizing_mod = 2;
	}


	// ������ ������� ����
	if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= pictureBox_main_object->Width) &&
		(e->Y >= 0 && e->Y <= resizingMargin)) {
		resizing_picture_box = true;
		resizing_mod = 3;
	}
	// ������ �����
	if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= pictureBox_main_object->Width) &&
		(e->Y > resizingMargin && e->Y < pictureBox_main_object->Height - resizingMargin)) {
		resizing_picture_box = true;
		resizing_mod = 4;
	}
	// ������ ������ ����
	if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= e->X <= pictureBox_main_object->Width) &&
		(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height)) {
		resizing_picture_box = true;
		resizing_mod = 5;
		this->Cursor->Clip = Rectangle(this->PointToScreen(first_rigth_bottom_point), System::Drawing::Size(first_right - 50, first_bottom - 50));
	}
	// ������ �����
	if ((e->X >= resizingMargin && e->X < pictureBox_main_object->Width - resizingMargin) &&
		(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height)) {
		resizing_picture_box = true;
		resizing_mod = 6;
	}
	// ������ ����� ����
	if ((e->X >= 0 && e->X <= resizingMargin) &&
		(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height)) {
		resizing_picture_box = true;
		resizing_mod = 7;
	}
	// ����� �����
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
		// ���� ��� ��������� ������ ���� �� �������� picturebox
		// ����� ������� ����
		if ((e->X >= 0 && e->X <= resizingMargin) &&
			(e->Y >= 0 && e->Y <= resizingMargin))
			pictureBox_main_object->Cursor = Cursors::SizeNWSE;

		// ������ ������ ����
		if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= e->X <= pictureBox_main_object->Width) &&
			(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height))
			pictureBox_main_object->Cursor = Cursors::SizeNWSE;
		// �����
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
	// �������� ������������� �� ������ ��������������
	if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0) {

		// erase rect
		ControlPaint::DrawReversibleFrame(rectProposedSize, this->ForeColor, FrameStyle::Dashed);

		// �������� �������� �������� � ��������������
		Bitmap^ image = gcnew Bitmap(rectProposedSize.Width, rectProposedSize.Height);
		for (int i = 0; i < image->Width; i++)
			for (int j = 0; j < image->Height; j++)
				image->SetPixel(i, j, Color::Black);


		//  �������� ������
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
		// �������� ������ � �������
		//
		rectProposedSize.Width = 0;
		rectProposedSize.Height = 0;



		creating_base = 0;
	}
}
*/
/*��������� �� ����� �� ������
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
		// �������� ������������� �� ������ ��������������
		if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0) {

			// erase rect
			ControlPaint::DrawReversibleFrame(rectProposedSize, this->ForeColor, FrameStyle::Dashed);

			// �������� �������� �������� � ��������������
			Bitmap^ image = gcnew Bitmap(rectProposedSize.Width, rectProposedSize.Height);
			for (int i = 0; i < image->Width; i++)
				for (int j = 0; j < image->Height; j++)
					image->SetPixel(i, j, Color::Black);
			//  �������� ������
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
			// �������� ������ � �������
			//
			rectProposedSize.Width = 0;
			rectProposedSize.Height = 0;


			creating_base = 0;
		}
	}
*/
/*// ���� ��� ��������� ������ ���� �� �������� picturebox 
		// ����� ������� ����
		if ((e->X >= 0 && e->X <= resizingMargin) &&
			(e->Y >= 0 && e->Y <= resizingMargin))
			pictureBox_main_object->Cursor = Cursors::SizeNWSE;
		// ������� �����
		if ((e->X > resizingMargin && e->X < pictureBox_main_object->Width - resizingMargin) &&
			(e->Y >= 0 && e->Y <= resizingMargin))
			pictureBox_main_object->Cursor = Cursors::SizeNS;
		// ������ ������� ����
		if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= pictureBox_main_object->Width) &&
			(e->Y >= 0 && e->Y <= resizingMargin))
			pictureBox_main_object->Cursor = Cursors::SizeNESW;
		// ������ �����
		if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= pictureBox_main_object->Width) &&
			(e->Y > resizingMargin && e->Y < pictureBox_main_object->Height - resizingMargin))
			pictureBox_main_object->Cursor = Cursors::SizeWE;
		// ������ ������ ����
		if ((e->X >= pictureBox_main_object->Width - resizingMargin && e->X <= e->X <= pictureBox_main_object->Width) &&
			(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height))
			pictureBox_main_object->Cursor = Cursors::SizeNWSE;
		// ������ �����
		if ((e->X >= resizingMargin && e->X < pictureBox_main_object->Width - resizingMargin) &&
			(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height))
			pictureBox_main_object->Cursor = Cursors::SizeNS;
		// ������ ����� ����
		if ((e->X >= 0 && e->X <= resizingMargin) &&
			(e->Y >= pictureBox_main_object->Height - resizingMargin && e->Y <= pictureBox_main_object->Height))
			pictureBox_main_object->Cursor = Cursors::SizeNESW;
		// ����� �����
		if ((e->X >= 0 && e->X <= resizingMargin) &&
			(e->Y > resizingMargin && e->Y < pictureBox_main_object->Height - resizingMargin))
			pictureBox_main_object->Cursor = Cursors::SizeWE;
		// �����
		if ((e->X > resizingMargin && e->X < pictureBox_main_object->Width - resizingMargin) &&
			(e->Y > resizingMargin && e->Y < pictureBox_main_object->Height - resizingMargin))
			pictureBox_main_object->Cursor = Cursors::Default;
		//*/
/*// ����� ������� ����
	if ((e->X >= 0 && e->X <= resizingMargin) &&
		(e->Y >= 0 && e->Y <= resizingMargin))
		MessageBox::Show("");
	// ������� �����
	if ((e->X > resizingMargin && e->X < dragged_picture_box->Width - resizingMargin) &&
		(e->Y >= 0 && e->Y <= resizingMargin))
		MessageBox::Show("������� �����");
	// ������ ������� ����
	if ((e->X >= dragged_picture_box->Width - resizingMargin && e->X <= dragged_picture_box->Width) &&
		(e->Y >= 0 && e->Y <= resizingMargin))
		MessageBox::Show("������ ������� ����");
	// ������ �����
	if ((e->X >= dragged_picture_box->Width - resizingMargin && e->X <= dragged_picture_box->Width) &&
		(e->Y> resizingMargin && e->Y< dragged_picture_box->Height-resizingMargin))
		MessageBox::Show("������ �����");
	// ������ ������ ����
	if ((e->X>=dragged_picture_box->Width - resizingMargin && e->X<= e->X <= dragged_picture_box->Width) &&
		(e->Y>= dragged_picture_box->Height - resizingMargin && e->Y<= dragged_picture_box->Height))
		MessageBox::Show("������ ������ ����");
	// ������ �����
	if((e->X>=resizingMargin && e->X< dragged_picture_box->Width - resizingMargin) &&
		(e->Y>= dragged_picture_box->Height - resizingMargin && e->Y<= dragged_picture_box->Height))
		MessageBox::Show("������ �����");
	// ������ ����� ����
	if ((e->X>=0&&e->X<= resizingMargin)&&
		(e->Y>= dragged_picture_box->Height - resizingMargin&&e->Y<= dragged_picture_box->Height))
		MessageBox::Show("������ ����� ����");
	// ����� �����
	if ((e->X>=0&&e->X<= resizingMargin)&&
		(e->Y> resizingMargin&&e->Y< dragged_picture_box->Height - resizingMargin))
		MessageBox::Show("����� �����");
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

