#pragma once
#include "PictureBoxInstance.h"
using namespace System::Collections::Generic;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
// �����������, ������� ��� �� ������ � ���� �����. ���� ����� ����� ��������� ������ �����������, ����������� ��������� ��� ��������������. ���������� ����������� ������� ����������� 
ref class PictureBoxInstanceWithText : public PictureBoxInstance
{
protected:
	List<String^>^ str_list;
	PictureBoxInstanceWithText(PictureBox^ pb);
};

