#include <windows.h>
#include "Filter.h"

// Является ли символ пунктуацией, если да, возвращает true.
bool Filter::f_IsPunctuation(const string& str)
{
	int i{ 0 };
	if (
		str[i] >= (char)33 && str[i] <= (char)47 ||
		str[i] >= (char)58 && str[i] <= (char)64 ||
		str[i] >= (char)91 && str[i] <= (char)96 ||
		str[i] >= (char)123 && str[i] <= (char)126 || // 127 del возможно нужно расширить до 127.
		str[i] >= (char)128 && str[i] <= (char)169 ||
		str[i] >= (char)171 && str[i] <= (char)174 ||
		str[i] >= (char)176 && str[i] <= (char)177 ||
		str[i] >= (char)181 && str[i] <= (char)183 ||
		str[i] == (char)185 ||
		str[i] >= (char)187 && str[i] <= (char)190
		)
	{
		return true;
	}
	return false;
}

// Является ли символ цифрой, если да, возвращает true.
bool Filter::f_IsDigit(const string& str)
{
	for (int i = 0; i < str.length();)
	{
		if (str[i] >= (char)48 && str[i] <= (char)57)
		{
			return true;
		}
		return false;
	}
	return false;
}

// Является ли символ латиницей, если да, возвращает true.
bool Filter::f_IsLatin(const string& str)
{
	for (int i = 0; i < str.length();)
	{
		if (
			str[i] >= (char)65 && str[i] <= (char)90 ||
			str[i] >= (char)97 && str[i] <= (char)122
			)
		{
			return true;
		}
		return false;
	}
	return false;
}

// Является ли символ кириллицей, если да, возвращает true.
bool Filter::f_IsCyrillic(const string& str)
{
	for (int i = 0; i < str.length();)
	{
		if (
			str[i] == (char)165 ||
			str[i] == (char)168 ||
			str[i] == (char)175 ||
			str[i] >= (char)178 && str[i] <= (char)180 ||
			str[i] == (char)184 ||
			str[i] == (char)186 ||
			str[i] >= (char)191 && str[i] <= (char)255
			)
		{
			return true;
		}
		return false;
	}
	return false;
}

// Заменяет символ пунктуации на пробел.
void Filter::f_FilterPunctuation(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (f_IsPunctuation(&str[i]))
			str[i] = ' '; // Можно заменить на replace.
	}
}

// Является ли символ цифрой, если да, возвращает true.
void Filter::f_FilterDigit(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (f_IsDigit(&str[i]))
			str[i] = ' '; // Можно заменить на replace.
	}
}

// Заменяет символ латиницы на пробел.
void Filter::f_FilterLatin(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (f_IsLatin(&str[i]))
			str[i] = ' '; // Можно заменить на replace.
	}
}

// Заменяет символ кириллицы на пробел.
void Filter::f_FilterCyrillic(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (f_IsCyrillic(&str[i]))
			str[i] = ' '; // Можно заменить на replace.
	}
}

// Обрабатывает нажатые клавиши прокрутки ввер или вниз.
void Filter::KeyPressed(int keyPressed)
{
	if (keyPressed == 72)
	{
		if (m_currentPage > 0)
		{
			m_currentPage--;
			filterPage = m_screen[m_currentPage];
			f_Filtration();
			PrintScreen();
		}
	}
	else if (keyPressed == 80)
	{
		if (m_currentPage < m_numberOfScreens)
		{
			m_currentPage++;
			filterPage = m_screen[m_currentPage];
			f_Filtration();
			PrintScreen();
		}
	}
	else if (keyPressed == 112)
	{
		filterPage = m_screen[m_currentPage];
		on_off_Punctuation();
		f_Filtration();
		PrintScreen();
	}
	else if (keyPressed == 100)
	{
		filterPage = m_screen[m_currentPage];
		on_off_Digit();
		f_Filtration();
		PrintScreen();
	}
	else if (keyPressed == 108)
	{
		filterPage = m_screen[m_currentPage];
		on_off_Latin();
		f_Filtration();
		PrintScreen();
	}
	else if (keyPressed == 99)
	{
		filterPage = m_screen[m_currentPage];
		on_off_Cyrillic();
		f_Filtration();
		PrintScreen();
	}
}

//Метод применяет включенные фильтры к выводимой странице.
void Filter::f_Filtration()
{
	if (m_flagCyrillic || m_flagDigit || m_flagLatin || m_flagPunctuation)
	{
		if (m_flagCyrillic)
			f_FilterCyrillic(filterPage);
		if (m_flagDigit)
			f_FilterDigit(filterPage);
		if (m_flagLatin)
			f_FilterLatin(filterPage);
		if (m_flagPunctuation)
			f_FilterPunctuation(filterPage);
	}
}

void Filter::on_off_Punctuation()
{
	if (m_flagPunctuation == false)
		m_flagPunctuation = true;
	else
		m_flagPunctuation = false;
}

void Filter::on_off_Digit()
{
	if (m_flagDigit == false)
		m_flagDigit = true;
	else
		m_flagDigit = false;
}

void Filter::on_off_Latin()
{
	if (m_flagLatin == false)
		m_flagLatin = true;
	else
		m_flagLatin = false;
}

void Filter::on_off_Cyrillic()
{
	if (m_flagCyrillic == false)
		m_flagCyrillic = true;
	else
		m_flagCyrillic = false;
}

// Считывает файл для работы с фильтрами.
void Filter::ReadFile(const char* fileName)
{
	FILE* f_read = nullptr;
	fopen_s(&f_read, fileName, "rt");
	if (f_read == nullptr)
	{
		perror("Error opening");
		return;
	}
	int lines{ 49 }; // Количество считываемыъ строк для записи в итый вектор.
	string fiftyLines{ "" };
	char buffer[300]{};
	while (!feof(f_read))
	{
		while (lines)
		{
			fgets(buffer, 300, f_read);
			if (feof(f_read))
				break;
			fiftyLines += buffer;
			lines--;
		}
		lines = 49;
		m_screen.Add(fiftyLines);
		m_numberOfScreens++;
		fiftyLines.clear();
	}
}

// Вывод "экрана" из массива.
void Filter::PrintScreen() const
{
	system("cls");
	cout << filterPage;
}

// Вывод "стартового" экрана из массива.
void Filter::PrintStartScreen()
{
	cout << m_screen[0];
}

// Перегруженный оператор <<. Вывод вектора на экран.
ostream& operator<<(ostream& cout, const Filter& f)
{
	f.m_screen.Print();
	return cout;
}