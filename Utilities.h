#pragma once

#include <string>
using namespace System;
using namespace System::Windows::Forms;

// --- ��������� ������� --- 
std::string ConvertToString(System::String^ s); // ������������ System::string ^ � std::string
String^ ConvertToString(std::string& os);		// ������������ std::string � System::string ^  

/// <summary>
/// ��������������� ������� ��� ������ �� ���������
/// </summary>
namespace StringHelper {
	/// <summary>
	/// ������������ System::string^ � std::string
	/// </summary>
	/// <param name="s"> - ��������� ������</param>
	/// <returns></returns>
	std::string ConvertToString(System::String^ s);

	/// <summary>
	/// ������������ std::string � System::string^  
	/// </summary>
	/// <param name="os"> - ����������� ������</param>
	/// <returns></returns>
	String^ ConvertToString(std::string& os);	  
}

/// <summary>
/// ����� ���������� � MessageBox WinForm
/// </summary>
namespace Messager {
	void WarningMessage(String^ mess);
	void ExceptionMessage(String^ mess);
	void ExceptionMessage(Exception^ ex);
	void Message(String^ mess, String^ header);
}