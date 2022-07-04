﻿/*
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

		КОММЕНТАРИИ К ЗАДАНИЮ:
* Работа с файлом в текстовом режиме. fgets, fputs (1 пример из примеров по файлам).
* getch (ждет нажатия клавиши, из крестики нолики, пятнашки)
* файл для работы "music.txt" в \11._String_class._Vector_class\task
* В развернутой консоли влазит 50 строк.
* Клавиши управления. "w" - глянуть выше, "s" - ниже(как ловили стрелочки в пятнашках, ловим 2 кода(224 и код клавиши)),
"p" - пунктуация, "d" - цифры, "l" - английские буквы(Latin alphabet), "c" - кириллица (Cyrillic)
* Прочесть весь файл сразу.
* При нажатии на "w" или "s" идет очистка экрана (system cls) и вывод.
* При нажатии на "w" или "s" идем по индексу массива вверх или вниз и вывод.
* Хранить в шаблонном векторе. Вектор хранит стринги. В одном стринге 1 экран, тоесть 50 конкатенированных строк.
* Читаем 50 строк с помощью ф-и гетс, конкатенировать и запихнуть в стринг, тоесть в итоге вектор - массив стрингов.
после прочтение каждой строки нужно конкатенировать "\n",так как фгетс не забирает ег оиз файла(проверить этот момент).
* 1 елемент вектора это стринг, которых хранит 50 строк.
* Готовый стринг кидаем в "Add" вектора.
* Процесс фильтрации происходит при выводе(замена на пробелы), по наличию тех или иных включенных фильтров.
* При повторном нажатии к примеру той же кнопки фильтра происходит вот что. Очистка экрана, берем эту же строку и уже цифры заменять
не нужно. 4 булевских флажка(вкл/выкл).
* Перед выводом проверять состояние фильтров на (вкл/выкл).
* Вектор хранит стринги.
* Разработать класс "фильтр". Внутри будет храниться обьект вектора(типизирован <стрингом>).
Класс фильт это клиент по отношению к классу вектор.
Переменная индекс, по которой и будем ходить вверх и вниз.
4 флажка булевских, для фильтрации.
4 метода проиводящих фильтрации (перед выводом.). Обрабатывает строку, заменяет что-то на пробелы.
4 метода определения, к примеру, является ли символ цифрой/ру буквой/латиницей/пунктуацией.
chartooem(в примерах работа со строками) - при выводе кириллицы конвертнуть из вин в дос кодировку.
oemtochar - наоборот, чтобы в программе обрабатывать русский текст, введенный ру текст конвертнуть из дос в вин кодировку.
Все методы делаю свою минимальную задачу.
Метод вывода на екран. Возможно перегрузить "<<".
* ВОзможно есть проблема с конвертацией самого текстового файла.(попробовать перевести файл в Ansi/utf8).
* Читаем строку из массива, меряем, чтобы не портить массив, создаем динам. буфер под эту строку, проводим замену 
в соответствии с фильтрами, и перед выводом CharToOemA.

В мейне создаем обьект класса фильтр и вперед (как работали с ректанглом.)
*
		ДОРАБОТКИ:
*
		ИЗВЕСТНЫЕ ОШИБКИ:
*
		ПРОТЕСТИРОВАТЬ:
*
		ВОПРОСЫ:
*
		ВИДЕО: 02:22:15 (начало дз), 01:43:00(шаблоны класса), 02:05:40 (о шаблонном веркторе)
		ССЫЛКИ:
* basic_string Class
https://docs.microsoft.com/en-us/cpp/standard-library/basic-string-class?f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(XSTRING%252Fstd%253A%253Abasic_string%253A%253Ainsert)%3Bk(std%253A%253Abasic_string%253A%253Ainsert)%3Bk(insert)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue&view=msvc-170#erase
* коды Virtual-Key
https://docs.microsoft.com/ru-ru/windows/win32/inputdev/virtual-key-codes?redirectedfrom=MSDN
################################################################################################
*/

#include <iostream>
#include "Vector.h"
#include "Filter.h"
#include <windows.h>

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
	filter.ReadFile();
	cout << filter;



}