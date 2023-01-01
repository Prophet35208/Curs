#pragma once
#include "TableLayerPicture.h"
using namespace System::Windows::Forms;
ref class Layer
{
	PictureBox^ pb;
	ITableLayer* a;
	Layer(PictureBox^ pb);
};

