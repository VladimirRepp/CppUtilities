#include "Encoder.h"

void Encoder::SaveSessionKey()
{
	ofstream fout(path_to_session_key, ios::trunc | ios::binary);
	fout << hSessionKey;
	fout.close();
	
	cout << "��������� ���� ��������!" << endl;
}

void Encoder::LoadSessionKey()
{
	ifstream fin(path_to_session_key, ios::binary);
	fin >> hSessionKey;
	fin.close();

	cout << "��������� ���� ��������!" << endl;
}

Encoder::Encoder()
{
	path_to_session_key = "SessionKey.txt";

	hSessionKey = NULL;
	hProv = NULL;
}

Encoder::~Encoder()
{
}

string Encoder::Encrypt(string source_str, bool isDebugPrint)
{
	// ��������� ��������� ����������������
	if (!CryptAcquireContext(&hProv, NULL, NULL,
		PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
	{
		ConsoleHelper::WriteWarning("Encoder::Crypt(): CryptAcquireContext Is Fail!");
		return string();
	}
	std::cout << "��������� ������������ ��������������� . . ." << std::endl;

	// ��������� ����������� �����
	if (!CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey))
	{
		ConsoleHelper::WriteWarning("Encoder::Crypt(): CryptGenKey Is Fail!");
		return string();
	}

	std::cout << "��������� ���� ������������ . . ." << std::endl;

	// ������ ��� ����������
	string encrypt_txt = source_str;
	DWORD count = source_str.length();

	// ���������� ������
	if (!CryptEncrypt(hSessionKey, 0, true, 0, (BYTE*)encrypt_txt.c_str(), &count, strlen(encrypt_txt.c_str())))
	{
		ConsoleHelper::WriteWarning("Encoder::Crypt(): CryptEncrypt Is Fail!");
		return string();
	}

	std::cout << "���������� ���������!" << std::endl;

	if (isDebugPrint) {
		// �������� ����� �� �����
		cout << "������������� ������: " << encrypt_txt << endl;
		cout << "����� ������: " << encrypt_txt.length() << endl;
	}

	return encrypt_txt;
}

string Encoder::Decrypt(string source_str, bool isDebugPrint)
{
	// ��������� ��������� ����������������
	if (!CryptAcquireContext(&hProv, NULL, NULL,
		PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
	{
		ConsoleHelper::WriteException("Encoder::Crypt(): CryptAcquireContext Is Fail!");
		return string();
	}
	std::cout << "��������� ������������ ��������������� . . ." << std::endl;

	// �������� ���������� �����
	try {
		LoadSessionKey();
	}
	catch (exception ex) {
		string message = "Encoder::Decrypt(): ";
		message += ex.what();
		throw new exception(message.c_str());
	}

	DWORD count1 = source_str.length();
	string decrypt_str = source_str;

	if (isDebugPrint) {
		// �������� ����� �� �����
		cout << "�������� ������: " << source_str << endl;
		cout << "����� ������: " << source_str.length() << endl;
	}

	if (!CryptDecrypt(hSessionKey, 0, true, 0, (BYTE*)decrypt_str.c_str(), &count1))
	{
		ConsoleHelper::WriteWarning("Encoder::Crypt(): CryptDecrypt Is Fail!");
		return string();
	}
	
	if (isDebugPrint) {
		// �������� ����� �� �����
		cout << "�������������� ������: " << decrypt_str << endl;
		cout << "����� ������: " << decrypt_str.length() << endl;
	}

	return decrypt_str;
}
