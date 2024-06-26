#include "Utilities.h"

#pragma region === Functions ===
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

int MyRandom(int from, int to) {
	return rand() % (to - from + 1) + from;
}
#pragma endregion

#pragma region === MessageHelper WinForm ===
void MessageHelper::Show(String^ message, String^ header)
{
	MessageBox::Show(message, header);
}

void MessageHelper::ShowWarning(String^ message)
{
	MessageBox::Show(message, "Внимание!");
}

void MessageHelper::ShowError(String^ message)
{
	MessageBox::Show(message, "Ошибка!");
}

void MessageHelper::ShowException(String^ message)
{
	MessageBox::Show(message, "Вызвано исключение!");
}
#pragma endregion

#pragma region === StringHelper ===
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

#pragma region === VerificationHelper === 
bool VerificationHelper::JustString(std::string& text)
{
	for (auto c : text) {
		if (c == '0' || c == '1' ||
			c == '2' || c == '3' ||
			c == '4' || c == '5' ||
			c == '6' || c == '7' ||
			c == '8' || c == '9')
			return false;
	}

	return true;
}

bool VerificationHelper::JustString(System::String^ text)
{
	for each (auto c in text)
	{
		if (c == '0' || c == '1' ||
			c == '2' || c == '3' ||
			c == '4' || c == '5' ||
			c == '6' || c == '7' ||
			c == '8' || c == '9')
			return false;
	} 

	return true;
}

bool VerificationHelper::JustNumber(std::string& text)
{
	for (auto c : text) {
		int ascii = c; // ASCII Val converted

		if (!(c >= 48 && c <= 57))
			return false;
	}

	return true;
}

bool VerificationHelper::JustNumber(System::String^ text)
{
	for each (auto c in text){
		int ascii = c; // ASCII Val converted

		if (!(c >= 48 && c <= 57))
			return false;
	}

	return true;
}
#pragma endregion

#pragma region === ConsoleHelper ===
void ConsoleHelper::Write(std::string& message)
{
	std::cout << message;
}

void ConsoleHelper::WriteLine(std::string& message)
{
	std::cout << message << std::endl;
}

void ConsoleHelper::Write(std::string& message, std::string& header)
{
	std::cout << header << " " << message;
}

void ConsoleHelper::WriteLine(std::string& message, std::string& header)
{
	std::cout << header << " " << message << std::endl;
}

void ConsoleHelper::WriteWarning(std::string& message)
{
	std::cout << "Внимание! " << message;
}

void ConsoleHelper::WriteLineWarning(std::string& message)
{
	std::cout << "Внимание! " << message << std::endl;
}

void ConsoleHelper::WriteException(std::string& message)
{
	std::cout << "Исключение! Сообщение: " << message;
}

void ConsoleHelper::WriteLineException(std::string& message)
{
	std::cout << "Исключение! Сообщение: " << message << std::endl;
}
#pragma endregion

