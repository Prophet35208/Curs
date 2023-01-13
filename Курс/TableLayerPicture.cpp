#include "TableLayerPicture.h"
#include <string>
using namespace std;
TableLayerPicture::TableLayerPicture(int number_in_table) {
    this->number_in_table = number_in_table;
}

TableLayerPicture::~TableLayerPicture() {

}

void TableLayerPicture::Delete() { delete this; }

int TableLayerPicture::GetNumInTable()
{
    return number_in_table;
}

void TableLayerPicture::SetNumberInTable(int num)
{
    this->number_in_table = num;
}

void TableLayerPicture::GetUp()
{
    this->number_in_table++;
}

void TableLayerPicture::GetDown()
{
    this->number_in_table--;
}

int TableLayerPicture::HaveText()
{
    return 0;
}

int TableLayerPicture::GetNumStrings()
{
    return 0;
}

void TableLayerPicture::SetNumStrings(int num)
{
    throw "DontHaveTextCapacity";
}




ITableLayer* ITableLayer::CreatePicture( int number_in_table)
{
    return static_cast<ITableLayer*>(new TableLayerPicture(number_in_table));
}