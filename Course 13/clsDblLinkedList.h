#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDblLinkedList
{
private:
    int _Size = 0;
    void _SetSize(bool Increase = true)
    {
        Increase ? _Size++ : _Size--;
    }
public:

    class Node
    {
    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    // Print the linked list
   
    void InsertAtBeginning(T value)
    {
        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) 
        {
            head->prev = newNode;
        }

        head = newNode;
        _SetSize(true);
    }
 
    void InsertAfter(Node* current, T value)
    {
        /*  1 - Create a new node with the desired value.
             2-Set the next pointer of the new node to the next node of the current node.
             3-Set the previous pointer of the new node to the current node.
             4-Set the next pointer of the current node to the new node.
             5-Set the previous pointer of the next node to the new node(if it exists).
        */
        if (current == NULL)return;

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) 
        {
            current->next->prev = newNode;
        }
       
        current->next = newNode;
        _SetSize(true);
    }

    void InsertAfter(int index, T value)
    {
        InsertAfter(GetNode(index) ,value);
    }

    void InsertAtEnd(T value)
    {
        /*
            1-Create a new node with the desired value.
            2-Traverse the list to find the last node.
            3-Set the next pointer of the last node to the new node.
            4-Set the previous pointer of the new node to the last node.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) 
        {
            newNode->prev = NULL;
            head = newNode;
        }
        else 
        {
            Node* current = head;
           
            while (current->next != NULL) 
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }

        _SetSize(true);
    }

    void DeleteNode(Node*& nodeToDelete)
    {
        /*
            1-Set the next pointer of the previous node to the next pointer of the current node.
            2-Set the previous pointer of the next node to the previous pointer of the current node.
            3-Delete the current node.
        */
        if (head == NULL || nodeToDelete == NULL)
        {
            return;
        }
        if (head == nodeToDelete)
        {
            head = nodeToDelete->next;
        }
        if (nodeToDelete->next != NULL)
        {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }
        if (nodeToDelete->prev != NULL)
        {
            nodeToDelete->prev->next = nodeToDelete->next;
        }
       
        delete nodeToDelete;
        _SetSize(false);

    }

    void DeleteFirstNode()
    {
        /*
            1-Store a reference to the head node in a temporary variable.
            2-Update the head pointer to point to the next node in the list.
            3-Set the previous pointer of the new head to NULL.
            4-Delete the temporary reference to the old head node.
        */

        if (head == NULL) 
        {
            return;
        }
        
        Node* temp = head;
        head = head->next;
       
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
        _SetSize(false);

    }

    void DeleteLastNode() 
    {
        /*
            1-Traverse the list to find the last node.
            2-Set the next pointer of the second-to-last node to NULL.
            3-Delete the last node.
        */

        if (head == NULL) 
        {
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        // we need to find the node before last node.
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _SetSize(false);
    }

    void PrintList()
    {
        Node* Current = head;

        while (Current != NULL)
        {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << "\n";

    }

    Node* Find(T value)
    {
        Node* Current = head;
        while (Current != NULL)
        {
            if (Current->value == value)
                return Current;

            Current = Current->next;
        }

        return NULL;
    }
    
    int Size() 
    {
        return _Size;
    }
    
    bool IsEmpty() 
    {
        return _Size == 0;
    }
  
    void Clear() 
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Reverse() 
    {
        Node* Current = head;
        Node* Temp = NULL;

        while (Current != NULL)
        {
            Temp = Current->prev;
            Current->prev = Current->next;
            Current->next = Temp;
            Current = Current->prev;

        }

        if (Temp != NULL) 
        {
            head = Temp->prev;
        }
    }

    Node* GetNode(int index)
    {
        if (index > _Size - 1 || index < 0)
            return NULL;
        
        int Counter = 0;
        Node* Current = head;

        while (Current != NULL && (Current->next != NULL)) 
        {
            if (Counter == index)
                break;

            Current = Current->next;
            Counter++;
        }

        return Current;
    }

    T GetItem(int index)
    {
        Node* ItemNode = GetNode(index);

        return ItemNode != NULL ? ItemNode->value : NULL;
    }

    bool UpdateItem(int index,T value)
    {
        Node* ItemNode = GetNode(index);
        
        if (ItemNode != NULL) 
        {
            ItemNode->value = value;
            return true;
        }
    
        return false;
    }
};
