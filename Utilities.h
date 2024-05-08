#pragma once

#include <iostream>
#include <string>
using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

// --- Прототипы функций --- 
std::string ConvertToString(System::String^ s); // конвертируем System::string ^ в std::string
String^ ConvertToString(std::string& os);		// конвертируем std::string в System::string ^  
int MyRandom(int from, int to);					// Выдает псевдослучайное значение в диапазоне (включая)

/// <summary>
/// Вспомогательные функции для работы со стороками
/// </summary>
namespace StringHelper {
	/// <summary>
	/// Конвертирует System::string^ в std::string
	/// </summary>
	/// <param name="s"> - системная строка</param>
	/// <returns></returns>
	std::string ConvertToString(System::String^ s);

	/// <summary>
	/// Конвертируеи std::string в System::string^  
	/// </summary>
	/// <param name="os"> - стандартная строка</param>
	/// <returns></returns>
	String^ ConvertToString(std::string& os);	  
}

/// <summary>
/// Вывод соообщений в MessageBox WinForm
/// </summary>
namespace Messager {
	void WarningMessage(String^ mess);
	void ExceptionMessage(String^ mess);
	void ExceptionMessage(Exception^ ex, String^ pathFile = "..\\Log.txt");
	void Message(String^ mess, String^ header = "");
}

/// <summary>
/// Вывод сообщений в консоль
/// </summary>
namespace ConsoleHelper {
	void Write(std::string message);
	void WriteLine(std::string message);
	void Write(std::string message, std::string header);
	void WriteLine(std::string message, std::string header);
	void WriteWarning(std::string message);
	void WriteLineWarning(std::string message);
	void WriteException(std::string message);
	void WriteLineException(std::string message);
}
