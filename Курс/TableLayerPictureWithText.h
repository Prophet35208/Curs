#pragma once   
#include "TableLayerPicture.h"
class TableLayerPictureWithText : public TableLayerPicture
{
private:
    int num_strings;
private:
    TableLayerPictureWithText(int number_in_table) :TableLayerPicture(number_in_table) {
        this->num_strings = 0;
    }
protected:
    ~TableLayerPictureWithText();

public:
    void Delete() override;
    int GetNumInTable() override;
    void GetUp() override;
    void GetDown() override;
    int HaveText() override;
    friend ITableLayer* ITableLayer::CreatePictureWithText(int number_in_table);
};

