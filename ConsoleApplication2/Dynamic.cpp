#include <stdlib.h>
#include <iostream>
#include <windows.h>
typedef void(*LibraryFunction)(char*, char*, int);
void main() {
	HINSTANCE hLib;							// ��������� ������������� ����������
	LibraryFunction  f;						// ��������� ��������� �� ������������ �������
	hLib = LoadLibrary(TEXT("main.dll"));	// ��������� ����������
	if (hLib == NULL) {						// ��������� ��������� �������� ����������
		std::cout << "Unable to load the library 'main.dll'\n";
		system("pause");
		return;
	}
	// �������� ��������� �� ������� � ����������� ��� � ������� ����
	f = (LibraryFunction)GetProcAddress(hLib, "RemoveSub");
	if (!f)									// ��������� ���������� ���������
		std::cout << "Unable to find the function 'RemoveSub'!\n\n";
	else {
		char str[256], res[256];
		int number;
		std::cout << "Input string: ";
		std::cin.get(str, 256);
		if (str[0] == '\0') {
			std::cout << "Empty string";
			FreeLibrary(hLib);
			system("pause");
			return;
		}
		std::cout << "Size: ";
		std::cin >> number;
		if (number < 1) {
			std::cout << "Number error(must be > 0)";
			FreeLibrary(hLib);
			system("pause");
			return;
		}
		f(str, res, number);
		std::cout << "Result: ";
		std::cout << res;
	}
	system("pause");
	FreeLibrary(hLib);
}