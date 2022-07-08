#include <windows.h>
#include "Filter.h"

// Является ли символ пунктуацией, если да, возвращает true.
bool Filter::f_IsPunctuation(const string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (
			str[i] >= (char)33 && str[i] <= (char)48 ||
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
	return false;
}

// Является ли символ цифрой, если да, возвращает true.
bool Filter::f_IsDigit(const string& str)
{
	for (int i = 0; i < str.length(); i++)
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
	for (int i = 0; i < str.length(); i++)
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
	for (int i = 0; i < str.length(); i++)
	{
		if (
			str[i] == (char)165 ||
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
	//возможно в булевские передавать не весь стринг, а только str[i] и в случае возврата тру
	for (int i = 0; i < str.length(); i++)
	{
		if (f_IsPunctuation(&str[i]))
			str[i] = ' '; // возможно заменить на replace
	}
}

// Является ли символ цифрой, если да, возвращает true.
void Filter::f_FilterDigit(string& str)
{
	//возможно в булевские передавать не весь стринг, а только str[i] и в случае возврата тру
	for (int i = 0; i < str.length(); i++)
	{
		if (f_IsDigit(&str[i]))
			str[i] = ' '; // возможно заменить на replace
	}
}

// Заменяет символ латиницы на пробел.
void Filter::f_FilterLatin(string& str)
{
	//возможно в булевские передавать не весь стринг, а только str[i] и в случае возврата тру
	for (int i = 0; i < str.length(); i++)
	{
		if (f_IsLatin(&str[i]))
			str[i] = ' '; // возможно заменить на replace
	}
}

// Заменяет символ кириллицы на пробел.
void Filter::f_FilterCyrillic(char *filterPage)
{
	//возможно в булевские передавать не весь стринг, а только str[i] и в случае возврата тру
	for (int i = 0; i < str.length(); i++)
	{
		if (f_IsCyrillic(&str[i]))
			str[i] = ' '; // возможно заменить на replace
	}
}

// Обрабатывает нажатые клавиши прокрутки ввер или вниз.
void Filter::f_KeyPressed(int keyPressed)
{
	if (keyPressed == 72)
	{
		if (m_currentPage > 0)
			m_currentPage--;
	}
	else
		return;
	if (keyPressed == 80)
	{
		if (m_currentPage < m_numberOfScreens)
			m_currentPage++;
	}
	else
		return;

	;
	PrintScreen(f_Filtration());
}

//Метод применяет включенные фильтры к выводимой странице.
string& Filter::f_Filtration()
{
	//string filterPage = m_screen[m_currentPage];
	const int currentPageSize = m_screen[m_currentPage].length();
	char* filterPage = new char[currentPageSize];
	strcpy_s(filterPage, currentPageSize, m_screen[m_currentPage].c_str());

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
	return filterPage;
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
	int lines{ 50 }; // Количество считываемыъ строк.
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
		lines = 50;
		m_screen.Add(fiftyLines);
		m_numberOfScreens++;
		fiftyLines.clear();
	}
}

// Вывод одного "экрана" из массива.
void Filter::PrintScreen(const string& filterPage)
{
	system("cls");
	cout << filterPage;

	/*int oneScreenSize = m_screen[m_numberOfScreens].length();
	char* oneScreenArr = new char[oneScreenSize]{};
	m_screen[m_numberOfScreens].copy(oneScreenArr, oneScreenSize);*/
	// возможно нужно добавить в конец oneScreenArr \0 - "str.copy(test, 4);	test[4] = '\0';"
	//delete[]oneScreenArr;
}

// Перегруженный оператор <<. Вывод вектора на экран.
ostream& operator<<(ostream& cout, Filter& f)
{
	//cout << endl;
	f.m_screen.Print();
	return cout;
}