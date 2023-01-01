#pragma once
#include <string>
using namespace std;
class ITableLayer
{
protected:
    virtual ~ITableLayer() = default; // ���������� ����������

public:
    virtual void Delete() = 0;  // ������� ������

    ITableLayer& operator=(const ITableLayer&) = delete; // ������ ������������
    virtual void Activate(bool activate) = 0;
    // �������-�������
    static ITableLayer* CreatePicture(int number_in_table);
};

