#pragma once
using namespace System::Windows::Forms;
// ������������� � ������������, ������������ ��������� PictureBox. ����������� �����.
ref class PictureBoxInstance
{
protected: PictureBox ^ pb;
		PictureBoxInstance(PictureBox^ pb);
public:
		PictureBox^ GetPictureBox();
	   void SetPictureBox(PictureBox^ pb);
};

