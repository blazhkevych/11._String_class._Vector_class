#pragma once
#include <iostream>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

template <typename T>
class Vector
{
	// Вектор.
	T* m_vect;
	// Размерность вектора.
	int m_size;
public:
	// Методы-аксессоры:
	// Инспекторы (позволяют получить значения полей).
	int GetSize() const;
	T* GetVect() const;

	// Функции - члены(методы) :	
	// Конструктор по умолчанию.
	Vector() :m_vect{ nullptr }, m_size{ 0 }{};

	// Конструктор, позволяющий задавать размерность вектора. explicit - препятствует выполнению неявных преобразований.	
	explicit Vector(int size);

	// Конструктор, позволяющий проинициализировать вектор с помощью существующего массива.
	Vector(const T* ptr, int size);

	// Конструктор копирования.
	Vector(const Vector<T>& v);

	// Реализация семантики переноса с использованием r-value ссылок.
	// Конструктор переноса.
	Vector(Vector<T>&& v);

	// Деструктор.
	~Vector();

	Vector<T>& operator ++ ();				// Увеличение всех компонент вектора на единицу (префикс).	
	Vector<T> operator ++ (int postfix);	// Увеличение всех компонент вектора на единицу (постфикс).	
	Vector<T>& operator -- ();				// Уменьшение всех компонент вектора на	единицу (префикс).	
	Vector<T> operator -- (int postfix);	// Уменьшение всех компонент вектора на единицу (постфикс).	

	// Перегруженный оператор присваивания с копированием.
	Vector<T>& operator = (const Vector& v);

	// Реализация семантики переноса с использованием r-value ссылок.
	// Перегруженный оператор присваивания с переносом.
	Vector<T>& operator = (Vector&& v);

	// Перегруженный оператор индексации.
	T& operator [] (int index);

	// Сложение двух векторов.
	Vector<T> operator + (const Vector& v);

	// Сложение вектора с числом (каждый компонент вектора складывается с числом).
	Vector<T> operator + (int n);

	// Перегруженный оператор += для сложения двух векторов.
	Vector<T>& operator += (const Vector& v);

	// Вычитание двух векторов.
	Vector<T> operator - (const Vector& v);

	// Вычитание числа из вектора (из каждого компонента вектора вычитывается число).
	Vector<T> operator - (int n);

	// Перегруженный оператор -= для вычитания двух векторов.
	Vector<T>& operator -= (const Vector& v);

	// Умножение векторов.
	Vector<T> operator * (const Vector& v);

	// Умножение вектора на число (каждый компонент вектора умножается на число).
	Vector<T> operator * (int n);

	// Перегруженный оператор *= для умножения вектора на число.
	Vector<T>& operator *= (int n);

	// Перегруженный оператор >>. Ввод вектора с клавиатуры.
	template<typename T>
	friend istream& operator >> (istream& cin, Vector<T>& v);

	// Перегруженный оператор <<. Вывод вектора на экран.
	template<typename T>
	friend ostream& operator << (ostream& cout, Vector<T>& v);

	// Метод вывода на экран.
	void Print() const;

	// Метод заполнения вектора.
	void Input();

	// Метод очистки вектора (заполнет все элементы нулями).
	void Clear();

	// Метод возвращает истину, если вектор пустой (m_size <= 0).
	bool IsEmpty() const;

	// Метод добавления элемента в вектор.
	void Add(const T& item);

	// Метод вставки элемента в вектор по заданному индексу.
	void Insert(int index, const T& item);

	// Метод удаления элемента из вектора по заданному индексу.
	void Remove(int index);
};

///////////////////////////////////////////////
///Реализация шаблонных методов класса Vector//
///////////////////////////////////////////////

// Методы-аксессоры:
// Инспекторы (позволяют получить значения полей).
template<typename T>
int Vector<T>::GetSize() const
{
	return m_size;
}
template<typename T>
T* Vector<T>::GetVect() const
{
	return m_vect;
}

// Функции - члены(методы) :	
// Конструктор, позволяющий задавать размерность вектора. explicit - препятствует выполнению неявных преобразований.	
template<typename T>
Vector<T>::Vector(int size)
{
	m_size = size;
	m_vect = new T[m_size];
	int min = 10; // Минимальное значение. 
	int max = 99; // Максимальное значение. 
	for (int i = 0; i < size; i++) // Заполняем одномерный массив псевдослучайными числами.
		m_vect[i] = (rand() % (max - min + 1) + min) * 0.99;
}

// Конструктор, позволяющий проинициализировать вектор с помощью существующего массива.
template<typename T>
Vector<T>::Vector(const T* ptr, int size)
{
	m_size = size;
	m_vect = new T[m_size];
	for (int i = 0; i < m_size; i++)
		m_vect[i] = ptr[i];
}

// Конструктор копирования.
template<typename T>
Vector<T>::Vector(const Vector<T>& v)
{
	int size = v.GetSize();
	m_vect = new T[size];
	for (int i = 0; i < size; i++)
		m_vect[i] = v.m_vect[i];
	m_size = v.GetSize();
}

// Реализация семантики переноса с использованием r-value ссылок.
// Конструктор переноса.
template<typename T>
Vector<T>::Vector(Vector<T>&& v)
{
	m_vect = v.m_vect;
	m_size = v.m_size;
	v.m_vect = nullptr;
}

// Деструктор.
template<typename T>
Vector<T>::~Vector()
{
	delete[] m_vect;
}

// Увеличение всех компонент вектора на единицу (префикс).
template<typename T>
Vector<T>& Vector<T>::operator++()
{
	for (int i = 0; i < m_size; i++)
		m_vect[i]++;
	return *this;
}

// Увеличение всех компонент вектора на единицу (постфикс).	
template<typename T>
Vector<T> Vector<T>::operator++(int postfix)
{
	Vector <T> tmp = *this;
	for (int i = 0; i < m_size; i++)
		m_vect[i]++;
	return tmp;
}

// Уменьшение всех компонент вектора на	единицу (префикс).	
template<typename T>
Vector<T>& Vector<T>::operator--()
{
	for (int i = 0; i < m_size; i++)
		m_vect[i]--;
	return *this;
}

// Уменьшение всех компонент вектора на единицу (постфикс).	
template<typename T>
Vector<T> Vector<T>::operator--(int postfix)
{
	Vector<T> tmp = *this;
	for (int i = 0; i < m_size; i++)
		m_vect[i]--;
	return tmp;
}

// Перегруженный оператор присваивания с копированием.
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& v)
{
	if (this == &v)
		return *this;
	delete[] this->m_vect;
	this->m_vect = new T[v.m_size];
	this->m_size = v.m_size;
	for (int i = 0; i < this->m_size; ++i)
	{
		this->m_vect[i] = v.m_vect[i];
	}
	return *this;
}

// Реализация семантики переноса с использованием r-value ссылок.
// Перегруженный оператор присваивания с переносом.
template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& v)
{
	if (this == &v)
		return *this;
	delete[] m_vect;
	m_vect = v.m_vect;
	v.m_vect = nullptr;

	return *this;
}

// Перегруженный оператор индексации.
template<typename T>
T& Vector<T>::operator[](int index) // возможно нужно "int&" или "T&" или "Vector<T>"или "Vector<T> T&"
{
	if (index < 0 || index >= m_size)
		return m_vect[0];
	return m_vect[index];
}

// Сложение двух векторов.
template<typename T>
Vector<T> Vector<T>::operator+(const Vector& v)
{
	int sizeLess = m_size < v.m_size ? m_size : v.m_size;	// Вычисляем вектор с меньшей размерностью.
	int sizeBigger = m_size > v.m_size ? m_size : v.m_size;	// Вычисляем вектор с большей размерностью.
	Vector<T> result{ sizeBigger };
	result.Clear();
	for (int i = 0; i < sizeBigger; i++)
		if (i >= sizeLess)
		{
			//result[i] = (*(this->m_vect + i)) > (*(v.GetVect() + i)) ? (*(this->m_vect + i)) : (*(v.GetVect() + i));
			result[i] = 0;
		}
		else
			result[i] = *(this->m_vect + i) + *(v.GetVect() + i);

	return result;
}

// Сложение вектора с числом (каждый компонент вектора складывается с числом).
template<typename T>
Vector<T> Vector<T>::operator+(int n)
{
	Vector<T> result{ m_size };
	result.Clear();
	for (int i = 0; i < m_size; i++)
		result[i] = (*(this->m_vect + i)) + n;
	return result;
}

// Перегруженный оператор += для сложения двух векторов.
template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector& v)
{
	*this = this->operator+(v);

	return *this;
}

// Вычитание двух векторов.
template<typename T>
Vector<T> Vector<T>::operator-(const Vector& v)
{
	int sizeLess = m_size < v.m_size ? m_size : v.m_size;	// Вычисляем вектор с меньшей размерностью.
	int sizeBigger = m_size > v.m_size ? m_size : v.m_size;	// Вычисляем вектор с большей размерностью.
	Vector<T> result{ sizeBigger };
	result.Clear();
	for (int i = 0; i < sizeBigger; i++)
		if (i >= sizeLess)
		{
			//result[i] = (*(this->m_vect + i)) > (*(v.GetVect() + i)) ? (*(this->m_vect + i)) : (*(v.GetVect() + i));
			result[i] = 0;
		}
		else
			result[i] = *(this->m_vect + i) - *(v.GetVect() + i);

	return result;
}

// Вычитание числа из вектора (из каждого компонента вектора вычитывается число).
template<typename T>
Vector<T> Vector<T>::operator-(int n)
{
	Vector<T> result{ m_size };
	result.Clear();
	for (int i = 0; i < m_size; i++)
		result[i] = (*(this->m_vect + i)) - n;
	return result;
}

// Перегруженный оператор -= для вычитания двух векторов.
template<typename T>
Vector<T>& Vector<T>::operator-=(const Vector& v)
{
	return *this = this->operator-(v);
}

// Умножение векторов.
template<typename T>
Vector<T> Vector<T>::operator*(const Vector& v)
{
	int sizeLess = m_size < v.m_size ? m_size : v.m_size;	// Вычисляем вектор с меньшей размерностью.
	int sizeBigger = m_size > v.m_size ? m_size : v.m_size;	// Вычисляем вектор с большей размерностью.
	Vector<T> result{ sizeBigger };
	result.Clear();
	for (int i = 0; i < sizeBigger; i++)
		if (i >= sizeLess)
		{
			//result[i] = (*(this->m_vect + i)) > (*(v.GetVect() + i)) ? (*(this->m_vect + i)) : (*(v.GetVect() + i));
			result[i] = 0;
		}
		else
			result[i] = *(this->m_vect + i) * *(v.GetVect() + i);

	return result;
}

// Умножение вектора на число (каждый компонент вектора умножается на число).
template<typename T>
Vector<T> Vector<T>::operator*(int n)
{
	Vector<T> result{ m_size };
	result.Clear();
	for (int i = 0; i < m_size; i++)
		result[i] = (*(this->m_vect + i)) * n;
	return result;
}

// Перегруженный оператор *= для умножения вектора на число.
template<typename T>
Vector<T>& Vector<T>::operator*=(int n)
{
	return *this = this->operator*(n);
}

// Перегруженный оператор >>. Ввод вектора с клавиатуры.
template<typename T>
istream& operator>>(istream& cin, Vector<T>& v)
{
	cout << endl;
	v.Clear();
	for (int i = 0; i < v.m_size; i++)
	{
		cout << "vector[" << i << "] = ";
		cin >> v.m_vect[i];
	}
	return cin;
}

// Перегруженный оператор <<. Вывод вектора на экран.
template<typename T>
ostream& operator<<(ostream& cout, Vector<T>& v)
{
	cout << endl;
	v.PrintScreen();
	return cout;
}

// Метод вывода на экран.
template<typename T>
void Vector<T>::Print() const
{
	for (int i = 0; i < m_size; i++)
		//cout << m_vect[i] << '\t';
		cout << m_vect[i];
	cout << endl;
}

// Метод заполнения вектора.
template<typename T>
void Vector<T>::Input()
{
	int min = 10; // Минимальное значение.
	int max = 99; // Максимальное значение.
	if (m_size != 0)
		for (int i = 0; i < m_size; i++)
			m_vect[i] = (rand() % (max - min + 1) + min) * 0.99;
}

// Метод очистки вектора (заполнет все элементы нулями).
template<typename T>
void Vector<T>::Clear()
{
	for (int i = 0; i < m_size; i++)
		m_vect[i] = 0;
}

// Метод возвращает истину, если вектор пустой (m_size <= 0).
template<typename T>
bool Vector<T>::IsEmpty() const
{
	return m_size <= 0 ? true : false;
}

// Метод добавления элемента в вектор.
template<typename T>
void Vector<T>::Add(const T& item)
{
	T* p = new T[++m_size];
	if (m_vect != nullptr)
	{
		for (int i = 0; i < m_size - 1; i++)
			p[i] = m_vect[i];
		p[m_size - 1] = item;
	}
	else
	{
		*p = item;
	}
	delete[]m_vect;
	m_vect = p;
	p = nullptr;
}

// Метод вставки элемента в вектор по заданному индексу.
template<typename T>
void Vector<T>::Insert(int index, const T& item)
{
	if (index < 0 || index > m_size - 1)
		return;
	T* p = new T[++m_size];
	int k = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (index == i)
		{
			k = 1;
			p[i] = item;
		}
		else
			p[i] = m_vect[i - k];
	}
	delete[]m_vect;
	m_vect = p;
	p = nullptr;
}

// Метод удаления элемента из вектора по заданному индексу.
template<typename T>
void Vector<T>::Remove(int index)
{
	if (index < 0 || index > m_size - 1)
		return;
	T* p = new T[--m_size];
	int k = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (index == i)
			k = 1;
		p[i] = m_vect[i + k];
	}
	delete[]m_vect;
	m_vect = p;
	p = nullptr;
}