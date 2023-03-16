#include "IntegerArray.h"
#include "Bad_length.h"
#include "Bad_range.h"
#include<iostream>
using namespace std;
ArrayInt::ArrayInt() : m_length(0), m_data(nullptr)
{
}
ArrayInt::ArrayInt(int length) :m_length(length)
{
	if (length < 0)

		throw Bad_length();

	if (length >= 0)
		m_data = new int(length);
	else
		m_data = nullptr;
}

ArrayInt::~ArrayInt()
{
	delete[] m_data;
}
void ArrayInt:: erase()
{
	delete[]m_data;
	m_data = nullptr;
	m_length = 0;

}

int& ArrayInt:: operator[](int index)
{
	checkIndex(index);
	return m_data[index];
}
int ArrayInt::checkIndex(int index)
{
	if (index < 0 || index > m_length)
		throw Bad_range();

}
/*int ArrayInt::Index()
{
	cout << "Exception invalid index" << endl;
	return 0;
}*/
int ArrayInt:: getLength()
{
	return m_length;
}
void ArrayInt::realocate(int newLength)
{
	erase();
	if (newLength == 0)
		return;
	m_data = new int[newLength];
	m_length = newLength;
}
void ArrayInt:: resize(int newLength)
{
	if (newLength == m_length)
		return;
	if (newLength == 0)
	{
		erase();
		return;
	}

	int* data = new int[newLength];
	if (m_length > 0)
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;
		for (int index = 0; index < elementsToCopy; ++index)
			data[index] = m_data[index];

		delete[] m_data;
		m_data = data;
		m_length = newLength;


	}
}


ArrayInt::ArrayInt(const ArrayInt& a)
{

	realocate(getLength());


	for (int index{ 0 }; index < m_length; ++index)
		m_data[index] = a.m_data[index];
}

ArrayInt& ArrayInt:: operator=(const ArrayInt& a)
{

	if (&a == this)
		return *this;


	realocate(getLength());
	for (int index{ 0 }; index < m_length; ++index)
		m_data[index] = a.m_data[index];

	return *this;
}
void ArrayInt::insertBefore(int value, int index)
{
	checkIndex(index);

	int* data = new int[m_length + 1];
	for (int before = 0; before < index; ++before)
		data[before] = m_data[before];

	data[index] = value;

	for (int after = index; after < m_length; ++after)
		data[after + 1] = m_data[after];

	delete[] m_data;
	m_data = data;
	++m_length;

}
void ArrayInt:: remove(int index)
{
	checkIndex(index);

	if (m_length == 1)
	{
		erase();
		return;
	}
	int* data = new int[m_length - 1];

	for (int before = 0; before < index; ++before)
		data[before] = m_data[before];
	for (int after = index + 1; after < m_length; ++after)
		data[after - 1] = m_data[after];

	delete[] m_data;
	m_data = data;
	--m_length;

}
void ArrayInt:: insertAtBeginning(int value)
{
	insertBefore(value, 0);
}
void ArrayInt:: insertAtEnd(int value)
{
	insertBefore(value, m_length);
}
