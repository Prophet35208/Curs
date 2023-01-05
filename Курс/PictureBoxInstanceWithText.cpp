#include "PictureBoxInstanceWithText.h"

PictureBoxInstanceWithText::PictureBoxInstanceWithText(PictureBox^ pb) : PictureBoxInstance(pb)
{
    str_list = gcnew List<String^>();
}
