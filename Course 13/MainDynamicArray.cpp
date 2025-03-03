#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

int main()
{
    clsDynamicArray<int> MyDynamicArray(5);

    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);

    cout << "\nIs Empty ? "<< MyDynamicArray.IsEmpty() << endl;
    cout << "\Array Size : "<< MyDynamicArray.Size() << endl;
    
    cout << "\Array Items :\n ";
    
    MyDynamicArray.PrintItems();

    system("pause>0");
    
    return 0;
}