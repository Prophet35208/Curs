#include "Layer.h"
Layer::Layer(PictureBox^ pb,int num_in_table) {
	this->pb = pb;
	ILayer = ITableLayer::CreatePicture(num_in_table);
}

PictureBox^ Layer::GetPictureBox()
{
	return pb;
}


