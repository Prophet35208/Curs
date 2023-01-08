#pragma once
#include "PictureBoxInstanceWithText.h"
#include "TableLayerPictureWithText.h"
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
// Класс является обобщением зависимости между формой представлениея на макете (picture box, который может включать изображение, текст) и записью в таблице. Записи в таблице регулируют параметры слоёв (как в таблице, так и на макете)
// Взаимодействие с таблице и определение подтипа слоя определяется с помощью интерфейса ITableLayer, который создаёт необходимый объект и задаёт его параметры.
ref class Layer : public PictureBoxInstanceWithText
{
private:
	ITableLayer* ILayer;
	bool* text_have_background = new bool(false);
public:
	Layer(PictureBox^ pb, int num_in_table);
	Layer(PictureBox^ pb, int num_in_table,int num_strings);
	int HaveText();
	void GetUp();
	void GetDown();
	bool* GetTextHaveBackground();
	void SetTextHaveBackground(bool b);
	int GetNumStr();
	void SetNumStr(int num);
	// Обновляет чередование слоёв согласно их порядку в списке (список слоёв объявлен в гланой форме)
	static void RefreshLayers(List<Layer^>^ layer_list);
};

