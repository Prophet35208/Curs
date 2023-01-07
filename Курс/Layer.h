#pragma once
#include "PictureBoxInstanceWithText.h"
#include "TableLayerPictureWithText.h"
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
// ����� �������� ���������� ����������� ����� ������ �������������� �� ������ (picture box, ������� ����� �������� �����������, �����) � ������� � �������. ������ � ������� ���������� ��������� ���� (��� � �������, ��� � �� ������)
// �������������� � ������� � ����������� ������� ���� ������������ � ������� ���������� ITableLayer, ������� ������ ����������� ������ � ����� ��� ���������.
ref class Layer : public PictureBoxInstanceWithText
{
private:
	ITableLayer* ILayer;
public:
	Layer(PictureBox^ pb, int num_in_table);
	Layer(PictureBox^ pb, int num_in_table,int num_strings);
	int HaveText();
	void GetUp();
	void GetDown();
	// ��������� ����������� ���� �������� �� ������� � ������ (������ ���� �������� � ������ �����)
	static void RefreshLayers(List<Layer^>^ layer_list);
};

