#ifndef ARRAYINT_H 
#define ARRAYINT_H
#include <assert.h>


class ArrayInt
{
private:
	int m_length;
	int* m_data;
public:
	ArrayInt();
	ArrayInt(int length);
	~ArrayInt();
	void erase();
	
	int& operator[](int index);
	int checkIndex(int index);
	int Index();
	int getLength();
	void realocate(int newLength);
	void resize(int newLength);
	ArrayInt(const ArrayInt& a);
	ArrayInt& operator=(const ArrayInt& a);
	void insertBefore(int value, int index);
	void remove(int index);
	void insertAtBeginning(int value);
	void insertAtEnd(int value);
		
};
#endif




































