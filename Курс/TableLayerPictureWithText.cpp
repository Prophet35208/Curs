#include "TableLayerPictureWithText.h"

TableLayerPictureWithText::~TableLayerPictureWithText()
{
}

int TableLayerPictureWithText::GetNumInTable()
{
	return number_in_table;
}


void TableLayerPictureWithText::GetUp()
{
	this->number_in_table++;
}

void TableLayerPictureWithText::GetDown()
{
	this->number_in_table--;
}

int TableLayerPictureWithText::HaveText()
{
	return 1;
}

void TableLayerPictureWithText::Delete() { delete this; }

ITableLayer* ITableLayer::CreatePictureWithText(int number_in_table)
{
	return static_cast<ITableLayer*>(new TableLayerPictureWithText(number_in_table));
}