#pragma once
#include <iostream>
#include <stack>

using namespace std;

template <class T>
class clsMyUndoRedoManager
{
private:
	T _Value;
	stack<T> _Undo;
	stack<T> _Redo;

public:

	clsMyUndoRedoManager(T Value = T()) 
	{
		_Value = Value;
		_Undo.push(_Value);
	}
	void SetValue(T Value)
	{
		_Value = Value;
		_Undo.push(_Value);
	}

	T GetValue() const
	{
		return _Value;
	}

	_declspec(property(get = GetValue, put = SetValue)) T Value;

	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_Value);
			_Undo.pop();
			_Value = _Undo.top();
		}
	}

	void Redo()
	{
		if (!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}
	}
};