#include "PictureBoxInstance.h"

PictureBoxInstance::PictureBoxInstance(PictureBox^ pb) {
	this->pb = pb;
	System::Drawing::Bitmap^ image = gcnew System::Drawing::Bitmap(pb->Width, pb->Height);
	for (int i = 0; i < image->Width; i++)
		for (int j = 0; j < image->Height; j++)
			image->SetPixel(i, j, System::Drawing::Color::Black);
}

PictureBox^ PictureBoxInstance::GetPictureBox()
{
	return pb;
}

void PictureBoxInstance::SetPictureBox(PictureBox^ pb)
{
	this->pb = pb;
}
