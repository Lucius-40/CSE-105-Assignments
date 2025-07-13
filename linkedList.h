#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<limits>
#include<iostream>

class LinkedList
{
public:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int x = 0)
        {
            next = nullptr;
            data = x;
        }
    };

    Node *head;
    int list_head;
    int size ;
    LinkedList(int x = 0)
    {
        head = nullptr;
        list_head = x;
        size = 0 ;
    }
    ~LinkedList()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    LinkedList &operator=(const LinkedList &other)
    {
        if (&other == this)
            return *this;
        clear();
        list_head = other.list_head;
        head = nullptr;
        if (other.head)
        {
            Node *curr = other.head;
            Node *prev = nullptr;
            while (curr)
            {
                Node *newnode = new Node(curr->data);
                if (!head)
                    head = newnode;
                else
                    prev->next = newnode;
                prev = newnode;
                curr = curr->next;
            }
        }
        return *this;
    }

    LinkedList(const LinkedList &other)
    {
        list_head = other.list_head;
        head = nullptr;
        if (other.head)
        {
            Node *curr = other.head;
            Node *prev = nullptr;
            while (curr)
            {
                Node *newnode = new Node(curr->data);
                if (!head)
                    head = newnode;
                else
                    prev->next = newnode;
                prev = newnode;
                curr = curr->next;
            }
        }
    }
    void add(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        size ++ ;
    }
    bool remove_value(int x)
    {
        Node *curr = head;
        Node *prev = nullptr;
        while (curr)
        {
            if (curr->data == x)
            {
                if (!prev)
                {
                    head = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                delete curr;
                size -- ;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }
    bool is_Present(int x)
    {
        Node *curr = head;
        while (curr)
        {
            if (curr->data == x)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
    void clear()
    {
        Node *curr = head;
        while (curr)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        size = 0 ;
    }

    class Iterator {
        Node* current;
    public:
        Iterator(Node* node) {
            current = node ;
        }
        int& operator*() { return current->data; }
        Iterator& operator++() { current = current->next; return *this; }
        bool operator!=(const Iterator& other) { return current != other.current; }
    };

    
    Iterator begin() { 
        return Iterator(head);
     }
    Iterator end() { 
        return Iterator(nullptr);
     }
    
    
    
    
    
};

#endif // LINKEDLIST_H