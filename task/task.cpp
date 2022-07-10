/*
############################################ ЗАДАНИЕ ###########################################
					Класс Vector. Класс string.
	Разработать программу, фильтрующую текст из заданного файла. Задача
программы заключается в считывании файла и отображении его на экране
(постранично), используя замену заданного набора символов на пробелы.
	Программа должна предлагать следующие варианты наборов символов для
фильтрации:
	 символы латиницы;
	 символы кириллицы;
	 символы пунктуации;
	 цифры.
	Фильтры могут накладываться последовательно. При повторной
установке существующего фильтра данный фильтр должен сниматься.
	В коде программы следует обязательно использовать класс Vector и
класс string.
################################################################################################
		СТАТУС : Готово.

		ССЫЛКИ:
* basic_string Class
https://docs.microsoft.com/en-us/cpp/standard-library/basic-string-class?f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(XSTRING%252Fstd%253A%253Abasic_string%253A%253Ainsert)%3Bk(std%253A%253Abasic_string%253A%253Ainsert)%3Bk(insert)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue&view=msvc-170#erase
* коды Virtual-Key
https://docs.microsoft.com/ru-ru/windows/win32/inputdev/virtual-key-codes?redirectedfrom=MSDN
################################################################################################
*/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Filter.h"

int main()
{
	SetConsoleCP(1251);
	/*
	Задает кодовую страницу ввода, используемую консолью, связанной с вызывающим процессом.
	Консоль использует страницу входного кода для преобразования ввода с клавиатуры
	в соответствующее символьное значение.
	*/
	SetConsoleOutputCP(1251);
	/*
	Задает выходную кодовую страницу, используемую консолью, связанной с вызывающим процессом.
	Консоль использует свою кодовую страницу вывода для преобразования символьных значений,
	записанных различными функциями вывода, в изображения, отображаемые в окне консоли.
	*/

	Filter filter;
	const char fileName[MAX_PATH] = "music.txt";
	filter.ReadFile(fileName);
	filter.PrintStartScreen();

	int userPressed{ 0 }; // Нажатая пользователем кнопка.
	do
	{
		userPressed = _getch();

		if (userPressed == 0 || userPressed == 0xE0)
			userPressed = _getch();

		if (userPressed == VK_ESCAPE) // "Escape" - выход из программы.
			break;
		if (userPressed == 72) // "UP"
			filter.KeyPressed(userPressed);
		else if (userPressed == 80) // "DOWN"
		{
			filter.KeyPressed(userPressed);
		}
		// Кнопки вкл/выкл фильтров:
		else if (userPressed == 112) // "p" - Фильтр пунктуации вкл/выкл. (только для английской раскладки)
		{
			filter.KeyPressed(userPressed);
		}
		else if (userPressed == 100) // "d" - Фильтр цыфр вкл/выкл. (только для английской раскладки)
		{
			filter.KeyPressed(userPressed);
		}
		else if (userPressed == 108) // "l" - Фильтр латиницы вкл/выкл. (только для английской раскладки)
		{
			filter.KeyPressed(userPressed);
		}
		else if (userPressed == 99) // "c" - Фильтр кириллицы вкл/выкл. (только для английской раскладки)
		{
			filter.KeyPressed(userPressed);
		}
	} while (true);
}