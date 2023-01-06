#include "PictureBoxInstance.h"

PictureBoxInstance::PictureBoxInstance(PictureBox^ pb) {
	this->pb = pb;
}

PictureBox^ PictureBoxInstance::GetPictureBox()
{
	return pb;
}

void PictureBoxInstance::SetPictureBox(PictureBox^ pb)
{
	this->pb = pb;
}
