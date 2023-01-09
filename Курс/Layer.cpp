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

Layer::Layer(const Layer% obj) :PictureBoxInstanceWithText(obj.pb)
{
	this->font = (Font^)obj.font->Clone();
	if(obj.ILayer->HaveText())
		this->ILayer = ITableLayer::CreatePictureWithText(obj.ILayer->GetNumInTable());
	else
		this->ILayer = ITableLayer::CreatePicture(obj.ILayer->GetNumInTable());
	// pb необходимо создать и привязать после копирования
	this->pb = nullptr;
	this->str_list = gcnew List<String^>(obj.str_list);
	*this->text_have_background = *obj.text_have_background;
}

Layer Layer::operator=(Layer mc)
{
 Layer l(mc);
 return l;
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

bool* Layer::GetTextHaveBackground()
{
	return text_have_background;
}

void Layer::SetTextHaveBackground(bool b)
{
	*this->text_have_background = b;
}

int Layer::GetNumStr()
{
	return ILayer->GetNumStrings();
}

void Layer::SetNumStr(int num)
{
	if (ILayer->HaveText())
		ILayer->SetNumStrings(num);
}

void Layer::RefreshLayers(List<Layer^>^ layer_list)
{
	for (int i = layer_list->Count - 1; i >= 0; i--)
	{
		layer_list[i]->GetPictureBox()->BringToFront();
	}
}


