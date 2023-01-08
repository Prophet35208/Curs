#pragma once
#include <string>
#include "ITableLayer.h"
using namespace std;
using namespace System;
class TableLayerPicture :  public ITableLayer
{
protected:
    int number_in_table;
    ~TableLayerPicture();
protected:
    TableLayerPicture(int number_in_table);

public:
    void Delete() override;
    int GetNumInTable() override;
    void GetUp() override;
    void GetDown() override;
    int HaveText() override;
    int GetNumStrings() override;
    void SetNumStrings(int num) override;
    friend ITableLayer* ITableLayer::CreatePicture(int number_in_table);
};

