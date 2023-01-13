#pragma once
#include "PictureBoxInstance.h"
using namespace System::Collections::Generic;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
/*void MakePbTransparent(PictureBox^ down_pb, PictureBox^ upper_pb) {
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
}*/
// Прямоугольник, который задаётся параметрами PictureBox. Изображение прямоугольника, показывающего границы текста задаются белым или другим цветом. Этот фон может быть учтён при конечной компиляции или же нет. Текст форматируем. Класс абстрактный
ref class PictureBoxInstanceWithText : public PictureBoxInstance
{
protected:
	Font^ font;
	List<String^>^ str_list;
	PictureBoxInstanceWithText(PictureBox^ pb);
public:
	void SetFont(Font^ font);
	Font^ GetFont();
	void SetStringList(List<String^>^str_list);
	List<String^>^ GetStringList();
};

