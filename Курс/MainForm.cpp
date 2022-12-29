#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Курс::MainForm form;
	Application::Run(% form);
}

void Курс::MainForm::MakeStringInTable() {
    
}
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
