#pragma once
// ����� ����������, ������� ��������� �������� � �������� TableLayerPicture � TableLayerPictureWitnText, �� ��������� �� ����������
class ITableLayer
{
protected:
    virtual ~ITableLayer() = default; // ���������� ����������

public:
    ITableLayer& operator=(const ITableLayer&) = delete; // ������ ������������
    virtual int GetNumInTable() = 0; 
    virtual void SetNumberInTable(int num) = 0; 
    virtual void Delete() = 0;  // ������� ������
    virtual void GetUp() = 0; // ����������� �������� ������ �� 1
    virtual void GetDown() = 0; // ��������� �������� ������ �� 1
    virtual int HaveText() = 0; // ���������� 1, ���� ������ ������������ ��������� ������, 0 � �������� ������
    virtual int GetNumStrings()=0; // ���� ������ ������������ ��������� ������, �� �������� ���������� ����� ������, ������� ���������� � �������� ������
    virtual void SetNumStrings(int num) =0; // ���� ������ ������������ ��������� ������, �� ��������� ���������� ����� ������, ������� ���������� � �������� ������

    // �������-�������
    static ITableLayer* CreatePicture(int number_in_table);
    static ITableLayer* CreatePictureWithText(int number_in_table);
};

