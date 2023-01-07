#include "Layer.h"
Layer::Layer(PictureBox^ pb,int num_in_table) :PictureBoxInstanceWithText(pb){
	this->pb = pb;
	ILayer = ITableLayer::CreatePicture(num_in_table);
}

Layer::Layer(PictureBox^ pb, int num_in_table,int num_strings) :PictureBoxInstanceWithText(pb)
{
	this->pb = pb;
	ILayer = ITableLayer::CreatePictureWithText(num_in_table);
	this->str_list = gcnew List<String^>();

}

int Layer::HaveText()
{
	return ILayer->HaveText();
}

void Layer::GetUp()
{
	ILayer->GetUp();
}

void Layer::GetDown()
{
	ILayer->GetDown();
}

bool Layer::GetTextHaveBackground()
{
	return text_have_background;
}

void Layer::SetTextHaveBackground(bool b)
{
	this->text_have_background = b;
}

void Layer::RefreshLayers(List<Layer^>^ layer_list)
{
	for (int i = layer_list->Count - 1; i >= 0; i--)
	{
		layer_list[i]->GetPictureBox()->BringToFront();
	}
}


