#include "Layer.h"
Layer::Layer(PictureBox^ pb,int num_in_table) {
	this->pb = pb;
	ILayer = ITableLayer::CreatePicture(num_in_table);
}

Layer::Layer(PictureBox^ pb, int num_in_table, vector<string>* v_ptr)
{
	this->pb = pb;
	ILayer = ITableLayer::CreatePictureWithText(num_in_table, v_ptr);

}

int Layer::HaveText()
{
	return ILayer->HaveText();
}

PictureBox^ Layer::GetPictureBox()
{
	return pb;
}

void Layer::GetUp()
{
	ILayer->GetUp();
}

void Layer::GetDown()
{
	ILayer->GetDown();
}

void Layer::SetPictureBox(PictureBox^ pb)
{
	this->pb = pb;
}


