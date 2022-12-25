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
		void MakeStringInTable();
		int creating_base = 0;
		int mouse_down = 0;
		Rectangle rectProposedSize = Rectangle::Empty;
		Point startDraggingPoint;
	private: System::Windows::Forms::Button^ button_set_image_to_object;
	private: System::Windows::Forms::DataGridView^ main_table;

	private: System::Windows::Forms::PictureBox^ main_element;

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
	protected:

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_put_main_element = (gcnew System::Windows::Forms::Button());
			this->main_element = (gcnew System::Windows::Forms::PictureBox());
			this->button_set_image_to_object = (gcnew System::Windows::Forms::Button());
			this->main_table = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_element))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->BeginInit();
			this->SuspendLayout();
			// 
			// button_put_main_element
			// 
			this->button_put_main_element->Location = System::Drawing::Point(950, 12);
			this->button_put_main_element->Name = L"button_put_main_element";
			this->button_put_main_element->Size = System::Drawing::Size(97, 57);
			this->button_put_main_element->TabIndex = 0;
			this->button_put_main_element->Text = L"������� �������";
			this->button_put_main_element->UseVisualStyleBackColor = true;
			this->button_put_main_element->Click += gcnew System::EventHandler(this, &MainForm::button_put_main_element_Click);
			// 
			// main_element
			// 
			this->main_element->Location = System::Drawing::Point(12, 12);
			this->main_element->Name = L"main_element";
			this->main_element->Size = System::Drawing::Size(33, 24);
			this->main_element->TabIndex = 2;
			this->main_element->TabStop = false;
			// 
			// button_set_image_to_object
			// 
			this->button_set_image_to_object->Location = System::Drawing::Point(950, 75);
			this->button_set_image_to_object->Name = L"button_set_image_to_object";
			this->button_set_image_to_object->Size = System::Drawing::Size(97, 57);
			this->button_set_image_to_object->TabIndex = 3;
			this->button_set_image_to_object->Text = L"���������� �����������";
			this->button_set_image_to_object->UseVisualStyleBackColor = true;
			// 
			// main_table
			// 
			this->main_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->main_table->Location = System::Drawing::Point(1053, 12);
			this->main_table->Name = L"main_table";
			this->main_table->Size = System::Drawing::Size(346, 621);
			this->main_table->TabIndex = 4;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1411, 645);
			this->Controls->Add(this->main_table);
			this->Controls->Add(this->button_set_image_to_object);
			this->Controls->Add(this->main_element);
			this->Controls->Add(this->button_put_main_element);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_element))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_table))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_put_main_element_Click(System::Object^ sender, System::EventArgs^ e) {
		if (creating_base == 0) {
			creating_base = 1;
			this->Cursor = Cursors::SizeNWSE;
		}
		else
		{
			creating_base = 0;
			this->Cursor = Cursors::Default;
		}
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

			if (rectProposedSize.Width > 0 && rectProposedSize.Height > 0)
			{
				// erase rect
				ControlPaint::DrawReversibleFrame(rectProposedSize, this->ForeColor, FrameStyle::Dashed);
			}

			// �������� �������� �������� � ��������������
			Bitmap^ image = gcnew Bitmap(rectProposedSize.Width, rectProposedSize.Height);
			for (int i = 0; i < image->Width; i++)
				for (int j = 0; j < image->Height; j++)
					image->SetPixel(i, j, Color::Black);

			this->main_element->Location = Control::PointToClient(rectProposedSize.Location);
			this->main_element->Name = L"pictureBox1";
			this->main_element->Size = rectProposedSize.Size;
			this->main_element->TabIndex = 1;
			this->main_element->TabStop = false;
			this->main_element->Image = image;


			rectProposedSize.Width = 0;
			rectProposedSize.Height = 0;
	}
};
}
