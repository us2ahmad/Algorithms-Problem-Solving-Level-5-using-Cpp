#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
    clsDblLinkedList <int> MydblLinkedList;

    if (MydblLinkedList.IsEmpty()) 
    {
        cout << "\n\nYes, List Is Empty.\n";
    }
    else
    {
        cout << "\n\No, List Is Not Empty.\n";
    }

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();


    if (MydblLinkedList.IsEmpty())
    {
        cout << "\n\nYes, List Is Empty.\n";
    }
    else
    {
        cout << "\n\No, List Is Not Empty.\n";
    }

    clsDblLinkedList<int>::Node* N1 = MydblLinkedList.Find(2);

    if (N1 != NULL)
        cout << "\nNode with value 2 is Found :-)\n";
    else
        cout << "\nNode Is not found :-(\n";

    MydblLinkedList.InsertAfter(N1, 500);
    cout << "\nAfter Inserting 500 after 2:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAtEnd(700);
    cout << "\nAfter Inserting 700 at end:\n";
    MydblLinkedList.PrintList();

    clsDblLinkedList<int>::Node* N2 = MydblLinkedList.Find(4);
    MydblLinkedList.DeleteNode(N2);
    cout << "\nAfter Deleting 4:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.DeleteFirstNode();
    cout << "\nAfter Deleting First Node:\n";
    MydblLinkedList.PrintList();

    cout << "\nAfter Deleting Last Node:\n";
    MydblLinkedList.DeleteLastNode();
    MydblLinkedList.PrintList();
    

    MydblLinkedList.Reverse();
    MydblLinkedList.PrintList();

    //cout << "\n\nLinked List Size : " << MydblLinkedList.Size() << endl;
    //
    //MydblLinkedList.Clear();
    //
    //if (MydblLinkedList.IsEmpty())
    //{
    //    cout << "\n\nYes, List Is Empty.\n";
    //}
    //else
    //{
    //    cout << "\n\No, List Is Not Empty.\n";
    //}

    clsDblLinkedList<int>::Node* N3 = MydblLinkedList.GetNode(1);
    
    cout << "Node Index 1 : " << N3->value << endl;

    cout << "\n\nItem(0) Value Is : " << MydblLinkedList.GetItem(1) << endl;


    MydblLinkedList.UpdateItem(0,900);
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAfter(3,99);
    MydblLinkedList.PrintList();


    system("pause>0");
    
    return 0;
}