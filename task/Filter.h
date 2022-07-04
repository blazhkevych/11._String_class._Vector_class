#pragma once
#include <string>
#include "Vector.h"
using std::string;

class Filter
{
	Vector<string> m_vector;
	int m_index;
public:
	// Конструктор по умолчанию.
	Filter() :m_vector{ 0 }, m_index{ 0 }{};
	// Конструктор со всеми параметрами.
	Filter(Vector<string> vector, int m_index) :m_vector{ 0 }, m_index{ 0 }{};

	// Является ли символ пунктуацией, если да, возвращает true.
	bool IsPunctuation();
	// Является ли символ цифрой, если да, возвращает true.
	bool IsDigit();
	// Является ли символ латиницей, если да, возвращает true.
	bool IsLatin();
	// Является ли символ кириллицей, если да, возвращает true.
	bool IsCyrillic();

	// Является ли символ пунктуацией, если да, возвращает true.
	bool FilterPunctuation();
	// Является ли символ цифрой, если да, возвращает true.
	bool FilterDigit();
	// Является ли символ латиницей, если да, возвращает true.
	bool FilterLatin();
	// Является ли символ кириллицей, если да, возвращает true.
	bool FilterCyrillic();

	// Считывает файл для работы с фильтрами.
	void ReadFile();

	// Перегруженный оператор <<. Вывод вектора на экран.
	friend ostream& operator << (ostream& cout, Filter& f);

};

// Перегруженный оператор <<. Вывод вектора на экран.
ostream& operator<<(ostream& cout, Filter& f);