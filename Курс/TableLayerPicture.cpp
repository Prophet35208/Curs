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




ITableLayer* ITableLayer::CreatePicture( int number_in_table)
{
    return static_cast<ITableLayer*>(new TableLayerPicture(number_in_table));
}