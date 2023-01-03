#pragma once
#include <string>
#include <vector>  
using namespace std;
class ITableLayer
{
protected:
    virtual ~ITableLayer() = default; // ���������� ����������

public:
    ITableLayer& operator=(const ITableLayer&) = delete; // ������ ������������
    virtual int GetNumInTable() = 0;

    virtual void Delete() = 0;  // ������� ������
    virtual void GetUp() = 0;
    virtual void GetDown() = 0;

    // �������-�������
    static ITableLayer* CreatePicture(int number_in_table);
    static ITableLayer* CreatePictureWithText(int number_in_table,vector<string>* ptr);
};

