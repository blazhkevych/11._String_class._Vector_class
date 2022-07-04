#include <windows.h>
#include "Filter.h"

bool Filter::IsDigit()
{
	/*



	//if

	string s("ABCDE");
	//вывод третьего символа строки
	cout << "operator[](2): " << s[2] << endl;
	cout << "s.at(2): " << s.at(2) << endl;
	//генерация исключения при выходе за пределы строки
	try
	{
		cout << "try s.at(100): ";
		cout << s.at(100) << endl;
	}
	catch (out_of_range e)
	{
		cout << "exception: " << e.what() << endl;
	}
	//изменение первого символа строки
	s[0] = '1';
	cout << s << endl;

	///////////////////////////////////////////////////////
	string s = "I am here. Try to find me.";
	//поиск первого вхождения символа e
	cout << "s.find('e'): " << s.find('e') << endl;
	//поиск последнего вхождения символа e
	cout << "s.rfind('e'): " << s.rfind('e') << endl;
	//поиск первого вхождения символа e после 10 индекса
	cout << "s.find('e', 10): " << s.find('e', 10) << endl;
	//поиск первого вхождения подстроки 'am'
	cout << "s.find('am'): " << s.find("am") << endl;
	//поиск первого вхождения любого символа из подстроки 'he'
	cout << "s.find_first_of('he')" << s.find_first_of("he") << endl;
	//поиск последнего вхождения любого символа из подстроки 'he'
	cout << "s.find_last_of('he')" << s.find_last_of("he") << endl;
	//поиск символа, который в строке не содержится
	cout << "s.find('F')" << s.find('F') << endl;
	//проверка возвращаемого значения
	if (s.find('F') == -1)
		cout << "Symbol not found" << endl;

	///////////////////////////////////////////////////////////

	  replace - замещение одного или более символов в заданной позиции


	string result1a, result1b;
	string s1("AAAAAAAA");
	string s2("BBB");
	s1.replace(1, 4, s2);
	cout << "The result of replacement: " << s1 << endl;


	//return false;

	*/
	return 0;
}

// Считывает файл для работы с фильтрами.
void Filter::ReadFile()
{
	char fileName[MAX_PATH] = "music.txt";
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
		m_vector.Add(fiftyLines);
		fiftyLines.clear();
	}
}

// Перегруженный оператор <<. Вывод вектора на экран.
ostream& operator<<(ostream& cout, Filter& f)
{
	//cout << endl;
	f.m_vector.Print();
	return cout;
}
