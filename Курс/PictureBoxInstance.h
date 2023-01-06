#pragma once
using namespace System::Windows::Forms;
// Прямоугольник с изображением, определяемым границами PictureBox. Абстрактный класс.
ref class PictureBoxInstance
{
protected: PictureBox ^ pb;
		PictureBoxInstance(PictureBox^ pb);
public:
		PictureBox^ GetPictureBox();
	   void SetPictureBox(PictureBox^ pb);
};

