#include "TableLayerPicture.h"
#include <string>
using namespace std;
int TableLayerPicture::num_all_objects_and_childs = 0;
TableLayerPicture::TableLayerPicture(int number_in_table) {
    this->number_in_table = number_in_table;
    num_all_objects_and_childs++;
}

TableLayerPicture::TableLayerPicture(const TableLayerPicture& obj)
{
    this->number_in_table = obj.number_in_table;
}

TableLayerPicture::~TableLayerPicture() {
    num_all_objects_and_childs--;
}

void TableLayerPicture::Delete() { delete this; }

int TableLayerPicture::GetNumInTable()
{
    return number_in_table;
}


ITableLayer* ITableLayer::CreatePicture( int number_in_table)
{
    return static_cast<ITableLayer*>(new TableLayerPicture(number_in_table));
}