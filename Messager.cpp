#include "Messager.h"

void Messager::Show(String^ message, String^ header)
{
	MessageBox::Show(message, header);
}

void Messager::ShowWarning(String^ message)
{
	MessageBox::Show(message, "��������!");
}

void Messager::ShowError(String^ message)
{
	MessageBox::Show(message, "������!");
}

void Messager::ShowException(String^ message)
{
	MessageBox::Show(message, "������� ����������!");
}
