#pragma once
using namespace System::Windows::Forms;
// Изображение, определяемое границами PictureBox. В начале закрашивается чёрным. Абстрактный класс.
ref class PictureBoxInstance
{
protected: PictureBox ^ pb;
		PictureBoxInstance(PictureBox^ pb);
		PictureBox^ GetPictureBox();
	   void SetPictureBox(PictureBox^ pb);
};

