#include "SettingsForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int main(cli::array<String^>^ arg) {
	vector<string>* f;
	ITableLayer* a=ITableLayer::CreatePictureWithText(1,f);
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	����::MainForm form;
	Application::Run(% form);
}
System::Void ����::MainForm::main_table_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (e->RowIndex != 0) {
		if (e->ColumnIndex == 1) {
			SettingsForm^ sf = gcnew SettingsForm();
			sf->current_picture_box = layer_list[e->RowIndex - 1]->GetPictureBox();
			sf->m_f = this;


			sf->ShowDialog();
		}
		if (e->ColumnIndex == 2) {
			if (e->RowIndex > 1) {
				// ��������� �� �������
				DataGridViewRow^ buf = main_table->Rows[e->RowIndex];
				main_table->Rows->Remove(buf);
				main_table->Rows->Insert(e->RowIndex - 1, buf);
				main_table->ClearSelection();
				main_table->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Selected = true;
				// ��������� � ������
				Layer^ bufl;
				bufl = layer_list[e->RowIndex-1];
				layer_list->RemoveAt(e->RowIndex-1);
				layer_list->Insert(e->RowIndex-2, bufl);
				RefreshTable();

			}
		}
		if (e->ColumnIndex == 3) {
			if (e->RowIndex < layer_list->Count) {
				// ��������� �� �������
				DataGridViewRow^ buf = main_table->Rows[e->RowIndex];
				main_table->Rows->Remove(buf);
				main_table->Rows->Insert(e->RowIndex + 1, buf);

				main_table->ClearSelection();
				main_table->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Selected = true;
				// ��������� � ������
				Layer^ bufl;
				bufl = layer_list[e->RowIndex - 1];
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

