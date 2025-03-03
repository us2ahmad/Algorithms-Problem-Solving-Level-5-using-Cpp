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
	
	clsDynamicArray(int size = 0) 
	{
		if (size < 0)
			size = 0;

		_Size = size;
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

	void Resize(int newSize) 
	{
		if (newSize == _Size)
			return;
		
		if (newSize < 0)
			newSize = 0;
		
		T* TempArray = new T[newSize];
	
		if (newSize < _Size)
			_Size = newSize;

		for (int i = 0; i < _Size; i++)
		{
			TempArray[i] = OriginalArray[i];
		}

		_Size = newSize;
		delete[] OriginalArray;
		OriginalArray = TempArray;
	}
	
	T GetItem(int indxe) 
	{
		return (indxe < 0 || indxe >= _Size) ? NULL : OriginalArray[indxe];
	}

	void Clear() 
	{
		T* TempArray = new T[0];
		_Size = 0;
		delete[] OriginalArray;
		OriginalArray = TempArray;
	}

	void Reverse() 
	{
		T* TempArray = new T[_Size];
		int counte = 0;

		for (int i = _Size - 1; i >= 0 ; i--)
		{
			TempArray[counte] = OriginalArray[i];
			counte++;
		}
		
		delete[] OriginalArray;
		OriginalArray = TempArray;
	}

	bool DeleteItemByIndex(int index)		// This My Solution
	{
		if (index < 0 || index >= _Size)
			return false;

		T* TempArray = new T[_Size-1];

		int newSize = 0;
		for(int i = 0; i < _Size ; i++)
		{
			if (i != index) 
			{
				TempArray[newSize++] = OriginalArray[i];
			}
		}

		_Size = newSize;
		delete[] OriginalArray;
		OriginalArray = TempArray;
		return true;
	}

	bool DeleteItemAt(int index)
	{
		if (index >= _Size || index < 0)
			return false;

		_Size--;
		T* TempArray = new T[_Size];

		//copy all before index
		for (int i = 0; i < index; i++)
		{
			TempArray[i] = OriginalArray[i];
		}

		//copy all after index
		for (int i = index + 1; i < _Size + 1; i++)
		{
			TempArray[i - 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = TempArray;
		return true;
	}

	bool DeleteFirstItem() 
	{
		return DeleteItemByIndex(0);
	}

	bool DeleteLastItem()
	{
		return DeleteItemByIndex(_Size - 1);
	}
	
	int Find(T value) 
	{
		for (int  i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == value)
				return i;
		}
		return -1;
	}

	bool DeleteItem(T value) 
	{
		return DeleteItemByIndex(Find(value));
	}

	bool InsertAt(int index, T value) 
	{

		if (index > _Size || index < 0)
		{
			return false;
		}

		_Size++;

		T* TempArray = new T[_Size];

		//copy all before index
		for (int i = 0; i < index; i++)
		{
			TempArray[i] = OriginalArray[i];
		}

		TempArray[index] = value;

		//copy all after index
		for (int i = index; i < _Size - 1; i++)
		{
			TempArray[i + 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = TempArray;
		return true;
	}

	bool InsertAtBeginning(T value) 
	{
		return InsertAt(0, value);
	}

	bool InsertBefore(int index, T value)
	{
		if (index < 1)
			return InsertAt(0, value);
		else
			return InsertAt(index, value);
	}

	bool InsertAfter(int index, T value)
	{
		if (index >= _Size)
			return InsertAt(_Size, value);
		else
			return InsertAt(index + 1, value);
	}

	bool InsertAtEnd(T value)
	{
		return InsertAt(_Size, value);
	}
};

