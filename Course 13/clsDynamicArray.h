#pragma once
#include <iostream>

using namespace std;

template<class T>
class clsDynamicArray
{
protected:
	int _Size = 0;
public:

	T* OriginalArray;
	clsDynamicArray(int Size = 0) 
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;
		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	int Size() 
	{
		return _Size;
	}

	bool IsEmpty() 
	{
		return _Size == 0;
	}

	bool SetItem(int index, T value) 
	{
		if (index >= _Size || index < 0)
			return false;

		OriginalArray[index] = value;
		return true;
	}

	void PrintItems() 
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << "  ";
		}
		cout << endl;
	}

};

