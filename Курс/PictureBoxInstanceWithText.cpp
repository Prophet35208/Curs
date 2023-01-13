#include "PictureBoxInstanceWithText.h"

PictureBoxInstanceWithText::PictureBoxInstanceWithText(PictureBox^ pb) : PictureBoxInstance(pb)
{
    str_list = gcnew List<String^>();
    font = gcnew System::Drawing::Font("Aerial", 10);
}

void PictureBoxInstanceWithText::SetFont(Font^ font)
{
    this->font = font;
}

Font^ PictureBoxInstanceWithText::GetFont()
{
    return font;
}

void PictureBoxInstanceWithText::SetStringList(List<String^>^ str_list)
{
    this->str_list = str_list;
}

List<String^>^ PictureBoxInstanceWithText::GetStringList()
{
    return this->str_list;
}
