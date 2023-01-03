#pragma once
#include "TableLayerPictureWithText.h"
using namespace System::Windows::Forms;
ref class Layer
{
private:
	PictureBox^ pb;
	ITableLayer* ILayer;
public:
	Layer(PictureBox^ pb, int num_in_table);
	PictureBox^ GetPictureBox();
	void GetUp();
	void GetDown();
};

