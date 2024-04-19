#include "Utilities.h"

#pragma region Functions
std::string ConvertToString(System::String^ s) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	std::string	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}

System::String^ ConvertToString(std::string& os) {
	System::String^ s = gcnew System::String(os.c_str());

	return s;
}
#pragma endregion

#pragma region Messager WinForm
void Messager::WarningMessage(String^ mess)
{
	MessageBox::Show(mess, "��������!");
}

void Messager::ExceptionMessage(String^ mess)
{
	MessageBox::Show(mess, "������� ����������!");
}

void Messager::ExceptionMessage(Exception^ ex)
{
	MessageBox::Show(ex->Message, "������� ����������!");
}

void Messager::Message(String^ mess, String^ header)
{
	MessageBox::Show(mess, header);
}
#pragma endregion

#pragma region StringHelper
std::string StringHelper::ConvertToString(System::String^ s)
{
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	std::string	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}

String^ StringHelper::ConvertToString(std::string& os)
{
	System::String^ s = gcnew System::String(os.c_str());

	return s;
}
#pragma endregion
