#include "PictureBoxInstanceWithText.h"

PictureBoxInstanceWithText::PictureBoxInstanceWithText(PictureBox^ pb) : PictureBoxInstance(pb)
{
    str_list = gcnew List<String^>();
}

void PictureBoxInstanceWithText::SetFont(Font^ font)
{
    this->font = font;
}

Font^ PictureBoxInstanceWithText::GetFont()
{
    return font;
}
