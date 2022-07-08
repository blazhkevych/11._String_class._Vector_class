#pragma once
#include <string>
#include "Vector.h"
using std::string;

class Filter
{
	Vector<string> m_screen;
	int m_numberOfScreens{ 0 };
	int m_currentPage{ 0 };

	// Является ли символ пунктуацией, если да, возвращает true.
	static bool f_IsPunctuation(const string& str);
	// Является ли символ цифрой, если да, возвращает true.
	static bool f_IsDigit(const string& str);
	// Является ли символ латиницей, если да, возвращает true.
	static bool f_IsLatin(const string& str);
	// Является ли символ кириллицей, если да, возвращает true.
	static bool f_IsCyrillic(const string& str);

	// Заменяет символ пунктуации на пробел.
	static void f_FilterPunctuation(string& str);
	// Заменяет символ цифры на пробел.
	static void f_FilterDigit(string& str);
	// Заменяет символ латиницы на пробел.
	static void f_FilterLatin(string& str);
	// Заменяет символ кириллицы на пробел.
	static void f_FilterCyrillic(char* filterPage);

	bool m_flagPunctuation{ false }; // Фильтр пунктуации вкл/выкл.
	bool m_flagDigit{ false };		// Фильтр цыфр вкл/выкл.
	bool m_flagLatin{ false };		// Фильтр латиницы вкл/выкл.
	bool m_flagCyrillic{ false };	// Фильтр кириллицы вкл/выкл.

	// Обрабатывает нажатые клавиши прокрутки ввер или вниз.
	void f_KeyPressed(int keyPressed);

	//Метод применяет включенные фильтры к выводимой странице.
	string& f_Filtration();

public:
	// Методы-аксессоры:
	// Инспекторы (позволяют получить значения полей).
	/*bool getFlagPunctuation() { return m_flagPunctuation; }
	bool getFlagDigit() { return m_flagDigit; }
	bool getFlagLatin() { return m_flagLatin; }
	bool getFlagCyrillic() { return m_flagCyrillic; }*/
	// Модификаторы (позволяют установить значения полей).
	void on_off_Punctuation();
	void on_off_Digit();
	void on_off_Latin();
	void on_off_Cyrillic();

	// Конструктор по умолчанию.
	Filter() :m_screen{ 0 }, m_numberOfScreens{ 0 }{};
	// Конструктор со всеми параметрами.
	Filter(Vector<string> vector, int m_index) :m_screen{ 0 }, m_numberOfScreens{ 0 }{};

	// Считывает файл для работы с фильтрами.
	void ReadFile(const char* fileName);

	// Перегруженный оператор <<. Вывод вектора на экран.
	friend ostream& operator << (ostream& cout, Filter& f);

	// Вывод одного "экрана" из массива.
	static void PrintScreen(const string& filterPage);
};

// Перегруженный оператор <<. Вывод вектора на экран.
ostream& operator<<(ostream& cout, Filter& f);