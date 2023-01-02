#pragma once
#include <string>
#include "ITableLayer.h"
using namespace std;
using namespace System;
class TableLayerPicture :  public ITableLayer
{
private:
    static int num_all_objects_and_childs;
    int number_in_table;


private:
    TableLayerPicture( int number_in_table);
    TableLayerPicture(const TableLayerPicture& obj);

protected:
    ~TableLayerPicture();

public:
    void Delete() override;
    int GetNumInTable() override;

    friend ITableLayer* ITableLayer::CreatePicture( int number_in_table);
};

