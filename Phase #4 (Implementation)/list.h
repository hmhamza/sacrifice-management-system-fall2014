#ifndef LIST_H
#define LIST_H

template <class T>
struct Node{
    T data;
    Node *next;
};

template <class T>
class List
{
    Node<T> *head;
    Node<T> *tail;

public:

    List(){                     //Constructor
        head = nullptr;
        tail = nullptr;
    }


    void addItem(T obj){       //Add Item
        Node<T> *newNode = new Node<T>;
        newNode->data = obj;
        newNode->next = nullptr;

        if (head == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;

    }

    bool searchItem(T obj){

        Node<T> *curr=head;

        while(curr!=nullptr){
            if(curr->data==obj)
                return true;
            curr=curr->next;
        }
        return false;
    }


};

#endif
