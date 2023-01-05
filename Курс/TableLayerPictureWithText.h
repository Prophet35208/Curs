#pragma once   
#include "TableLayerPicture.h"
class TableLayerPictureWithText : public TableLayerPicture
{
private:
    vector<string>* str_list;
private:
    TableLayerPictureWithText(int number_in_table, vector<string>* str_list) :TableLayerPicture(number_in_table) {
        this->str_list = str_list;
    }
protected:
    ~TableLayerPictureWithText();

public:
    void Delete() override;
    int GetNumInTable() override;
    vector<string>* GetStringList() override;
    void GetUp();
    void GetDown();
    int HaveText();
    friend ITableLayer* ITableLayer::CreatePictureWithText(int number_in_table, vector<string>* ptr);
};

