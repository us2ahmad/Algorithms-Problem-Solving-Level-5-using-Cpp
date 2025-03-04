#pragma once
#include <iostream>
#include"clsMyQueueArr.h"

template<class T>
class clsMyStackArr : public clsMyQueueArr<T>
{
public:

	void Push(T value)
	{
		clsMyQueueArr<T>::_MyList.InsertAtBeginning(value);
	}

	T Top()
	{
		//return __super::Front();
		return clsMyQueueArr<T>::Front();
	}

	T Bottom()
	{		
		//return __super::Back();
		return clsMyQueueArr<T>::Back();
	}
};

