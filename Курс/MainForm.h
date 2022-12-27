#pragma once

namespace ���� {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		//
			// ����������� ���������� ��� ����������� �������������� �������� ����������� (�������������� ������)
		
		System::Drawing::Size^ startSize; 
		Rectangle rectProposedSize_1=Rectangle::Empty;
		int resizingMargin = 15;
		bool resizing_picture_box;	
		System::Windows::Forms::PictureBox^ dragged_picture_box;
		Point startDraggingPoint_1;
			//
		System::Windows::Forms::Button^ button_121414;
		void MakeStringInTable();
		int creating_base = 0;
		int mouse_down = 0;
		Rectangle rectProposedSize = Rectangle::Empty;
		Point startDraggingPoint;
		System::Windows::Forms::PictureBox^ main_element;
		//
	private: System::Windows::Forms::Button^ button_set_image_to_object;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip_delete_main_element;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column_name;
	private: System::Windows::Forms::DataGridViewButtonColumn^ up;
	private: System::Windows::Forms::DataGridViewButtonColumn^ down;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::DataGridView^ main_table;
		   //

	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//

		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	protected:

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button_put_main_element = (gcnew System::Windows::Forms::Button());
			this->button_set_image_to_object = (gcnew System::Windows::Forms::Button());
			this->main_table = (gcnew System::Windows::Forms::DataGridView());
			this->Column_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->up = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->down = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->contextMenuStrip_delete_main_element = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->BeginInit();
			this->contextMenuStrip_delete_main_element->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button_put_main_element
			// 
			this->button_put_main_element->Location = System::Drawing::Point(702, 25);
			this->button_put_main_element->Name = L"button_put_main_element";
			this->button_put_main_element->Size = System::Drawing::Size(97, 57);
			this->button_put_main_element->TabIndex = 0;
			this->button_put_main_element->Text = L"������� �������";
			this->button_put_main_element->UseVisualStyleBackColor = true;
			this->button_put_main_element->Click += gcnew System::EventHandler(this, &MainForm::button_put_main_element_Click);
			// 
			// button_set_image_to_object
			// 
			this->button_set_image_to_object->Location = System::Drawing::Point(702, 88);
			this->button_set_image_to_object->Name = L"button_set_image_to_object";
			this->button_set_image_to_object->Size = System::Drawing::Size(97, 57);
			this->button_set_image_to_object->TabIndex = 3;
			this->button_set_image_to_object->Text = L"���������� �����������";
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
			this->Column_name->HeaderText = L"�������� ����";
			this->Column_name->MaxInputLength = 30;
			this->Column_name->MinimumWidth = 70;
			this->Column_name->Name = L"Column_name";
			this->Column_name->Width = 200;
			// 
			// up
			// 
			this->up->HeaderText = L"����";
			this->up->Name = L"up";
			this->up->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->up->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// down
			// 
			this->down->HeaderText = L"����";
			this->down->Name = L"down";
			this->down->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->down->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// contextMenuStrip_delete_main_element
			// 
			this->contextMenuStrip_delete_main_element->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->�������ToolStripMenuItem });
			this->contextMenuStrip_delete_main_element->Name = L"contextMenuStrip1";
			this->contextMenuStrip_delete_main_element->Size = System::Drawing::Size(119, 26);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�������ToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(320, 176);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(151, 136);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseUp);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1411, 645);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->main_table);
			this->Controls->Add(this->button_set_image_to_object);
			this->Controls->Add(this->button_put_main_element);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->EndInit();
			this->contextMenuStrip_delete_main_element->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_put_main_element_Click(System::Object^ sender, System::EventArgs^ e) {
			creating_base = 1;
	}
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
			if (main_element == nullptr)
				this->main_element = (gcnew System::Windows::Forms::PictureBox());
			this->main_element->Location = Control::PointToClient(rectProposedSize.Location);
			this->main_element->Name = L"pictureBox1";
			this->main_element->Size = rectProposedSize.Size;
			this->main_element->TabIndex = 1;
			this->main_element->TabStop = false;
			this->main_element->Image = image;
			this->Controls->Add(this->main_element);
			this->main_element->ContextMenuStrip = this->contextMenuStrip_delete_main_element;
			// �������� ������ � �������
			//
			rectProposedSize.Width = 0;
			rectProposedSize.Height = 0;

			button_put_main_element->Enabled = 0;

			creating_base = 0;
		}
	}

// �������� ������
private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	delete main_element;
	button_put_main_element->Enabled = 1;
}
private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	dragged_picture_box = (PictureBox^)sender;
	// ����� ������� ����
	if ((e->X >= 0 && e->X <= resizingMargin) &&
		(e->Y >= 0 && e->Y <= resizingMargin)) 
	{
		this->pictureBox1->Cursor = Cursors::SizeNWSE;
		
		resizing_picture_box = true;

		rectProposedSize_1.X = this->PointToScreen(dragged_picture_box->Location).X;
		rectProposedSize_1.Y = this->PointToScreen(dragged_picture_box->Location).Y;
		rectProposedSize_1.Width = e->X;
		rectProposedSize_1.Height = e->Y;
		// draw rect
		ControlPaint::DrawReversibleFrame(rectProposedSize_1, this->ForeColor, FrameStyle::Dashed);
	}
		
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
	//
	if ((e->X <= resizingMargin) || (e->X >= dragged_picture_box->Width - resizingMargin) ||
		(e->Y <= resizingMargin) || (e->Y >= dragged_picture_box->Height - resizingMargin))
	{
		resizing_picture_box = true;

		// indicate resizing
		this->Cursor = Cursors::SizeNWSE;
		// starting size
		this->startSize = gcnew System::Drawing::Size(e->X, e->Y);
		// get the location of the picture box
		Point pt = PointToScreen(dragged_picture_box->Location);
		rectProposedSize_1.X = this->PointToScreen(dragged_picture_box->Location).X;
		rectProposedSize_1.Y= this->PointToScreen(dragged_picture_box->Location).Y;
		rectProposedSize_1.Width = e->X;
		rectProposedSize_1.Height = e->Y;
		// draw rect
		ControlPaint::DrawReversibleFrame(rectProposedSize_1, this->ForeColor, FrameStyle::Dashed);
	}
	else
	{
		resizing_picture_box = false;
		// indicate moving
		this->Cursor = Cursors::SizeAll;
	}

	// start point location
	this->startDraggingPoint_1 = e->Location;
}
private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (resizing_picture_box!=true) {
		// ����� ������� ����
		if ((e->X >= 0 && e->X <= resizingMargin) &&
			(e->Y >= 0 && e->Y <= resizingMargin))
			this->pictureBox1->Cursor = Cursors::SizeNWSE;
		// ������� �����
		if ((e->X > resizingMargin && e->X < this->pictureBox1->Width - resizingMargin) &&
			(e->Y >= 0 && e->Y <= resizingMargin))
			this->pictureBox1->Cursor = Cursors::SizeNS;
		// ������ ������� ����
		if ((e->X >= this->pictureBox1->Width - resizingMargin && e->X <= this->pictureBox1->Width) &&
			(e->Y >= 0 && e->Y <= resizingMargin))
			this->pictureBox1->Cursor = Cursors::SizeNESW;
		// ������ �����
		if ((e->X >= this->pictureBox1->Width - resizingMargin && e->X <= this->pictureBox1->Width) &&
			(e->Y > resizingMargin && e->Y < this->pictureBox1->Height - resizingMargin))
			this->pictureBox1->Cursor = Cursors::SizeWE;
		// ������ ������ ����
		if ((e->X >= this->pictureBox1->Width - resizingMargin && e->X <= e->X <= this->pictureBox1->Width) &&
			(e->Y >= this->pictureBox1->Height - resizingMargin && e->Y <= this->pictureBox1->Height))
			this->pictureBox1->Cursor = Cursors::SizeNWSE;
		// ������ �����
		if ((e->X >= resizingMargin && e->X < this->pictureBox1->Width - resizingMargin) &&
			(e->Y >= this->pictureBox1->Height - resizingMargin && e->Y <= this->pictureBox1->Height))
			this->pictureBox1->Cursor = Cursors::SizeNS;
		// ������ ����� ����
		if ((e->X >= 0 && e->X <= resizingMargin) &&
			(e->Y >= this->pictureBox1->Height - resizingMargin && e->Y <= this->pictureBox1->Height))
			this->pictureBox1->Cursor = Cursors::SizeNESW;
		// ����� �����
		if ((e->X >= 0 && e->X <= resizingMargin) &&
			(e->Y > resizingMargin && e->Y < this->pictureBox1->Height - resizingMargin))
			this->pictureBox1->Cursor = Cursors::SizeWE;
		if ((e->X > resizingMargin && e->X < this->pictureBox1->Width - resizingMargin) &&
			(e->Y > resizingMargin && e->Y < this->pictureBox1->Height - resizingMargin))
			this->pictureBox1->Cursor = Cursors::Default;
	}
	if (dragged_picture_box != nullptr)
	{
		if (resizing_picture_box)
		{
			// erase rect
			if (rectProposedSize_1.Width > 0 && rectProposedSize_1.Height > 0)
				ControlPaint::DrawReversibleFrame(rectProposedSize_1, this->ForeColor, FrameStyle::Dashed);
			// calculate rect new size
			/*
			rectProposedSize.Width = Control::PointToScreen(e->Location).X- rectProposedSize.X;
			rectProposedSize.Height = Control::PointToScreen(e->Location).Y- rectProposedSize.Y;
			*/
			rectProposedSize_1.Width = e->X;
			rectProposedSize_1.Height = e->Y;
			// draw rect
			if (rectProposedSize_1.Width > 0 && rectProposedSize_1.Height > 0)
				ControlPaint::DrawReversibleFrame(rectProposedSize_1, this->ForeColor, FrameStyle::Dashed);
		}
		else
		{
			Point^ pt;
			if (dragged_picture_box == sender) // ��������� ����
				pt = gcnew Point(e->X, e->Y);
			else;
			 //pt = dragged_picture_box.PointToClient((sender).PointToScreen(new Point(e.X, e.Y)));

			dragged_picture_box->Left += pt->X - this->startDraggingPoint_1.X;
			dragged_picture_box->Top += pt->Y - this->startDraggingPoint_1.Y;
		}
	}
}
private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (resizing_picture_box)
	{
		if (rectProposedSize_1.Width > 0 && rectProposedSize_1.Height > 0)
		{
			// erase rect
			ControlPaint::DrawReversibleFrame(rectProposedSize_1, this->ForeColor, FrameStyle::Dashed);
		}
		// set size 
		this->dragged_picture_box->Size = rectProposedSize_1.Size;
	}

	this->dragged_picture_box = nullptr;
	this->startDraggingPoint_1 = Point::Empty;
	this->Cursor = Cursors::Default;
}
};
}
