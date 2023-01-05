#pragma once
#include "TableLayerPictureWithText.h"
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
ref class Layer
{
private:
	List<String^>^ str_list;
	PictureBox^ pb;
	ITableLayer* ILayer;
public:
	Layer(PictureBox^ pb, int num_in_table);
	Layer(PictureBox^ pb, int num_in_table,int num_strings);
	int HaveText();
	PictureBox^ GetPictureBox();
	void GetUp();
	void GetDown();
	void SetPictureBox(PictureBox^ pb);
};

