#include <stdlib.h>
#include <iostream>
#include <windows.h>
typedef void(*LibraryFunction)(char*, char*, int);
void main() {
	HINSTANCE hLib;							// Объявляем идентификатор библиотеки
	LibraryFunction  f;						// Объявляем указатель на библиотечную функцию
	hLib = LoadLibrary(TEXT("main.dll"));	// Загружаем библиотеку
	if (hLib == NULL) {						// Проверяем результат загрузки библиотеки
		std::cout << "Unable to load the library 'main.dll'\n";
		system("pause");
		return;
	}
	// Получаем указатель на функцию и преобразуем его к нужному типу
	f = (LibraryFunction)GetProcAddress(hLib, "RemoveSub");
	if (!f)									// Проверяем полученный указатель
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