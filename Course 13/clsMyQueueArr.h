#pragma once
#include <iostream>
#include"clsDynamicArray.h"

template <class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray<T> _MyList;
public:

	void Push(T value)
	{
		_MyList.InsertAtEnd(value);
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	void Pop()
	{
		_MyList.DeleteFirstItem();
	}

	T Front()
	{
		return _MyList.GetItem(0);
	}

	T Back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	T GetItem(int index)
	{
		return _MyList.GetItem(index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	bool UpdateItem(int index, T value)
	{
		return _MyList.SetItem(index, value);
	}

	void InsertAfter(int index, T value)
	{
		_MyList.InsertAfter(index, value);
	}

	void InsertAtFront(T value)
	{
		_MyList.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{
		_MyList.InsertAtEnd(value);
	}

	void Clear()
	{
		_MyList.Clear();
	}

	void Print()
	{
		_MyList.PrintItems();
	}
};

