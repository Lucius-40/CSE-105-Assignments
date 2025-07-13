#include "stack.h"
#include <iostream>

// Constructor implementation
ListStack::ListStack() {
    // TODO: Initialize head to nullptr
    // TODO: Initialize current_size to 0
    head = NULL ;
    current_size = 0 ;
}

// Destructor implementation
ListStack::~ListStack() {
    // TODO: Deallocate all nodes in the linked list
    // TODO: Consider using the clear() method
    clear();
}

// Push implementation
void ListStack::push(int item) {
    // TODO: Create a new node with the given item
    // TODO: Make the new node point to the current head
    // TODO: Update head to point to the new node
    // TODO: Increment current_size
    Node * p = new Node(item,head) ;
    head = p ;
    current_size ++ ;


}

// Pop implementation
int ListStack::pop() {
    // TODO: Check if the stack is empty, display error message if it is
    // TODO: Store the data from the head node
    // TODO: Update head to point to the next node
    // TODO: Delete the old head node
    // TODO: Decrement current_size
    // TODO: Return the stored data
    if(empty()){std ::cout <<"Stack Empty , cannot pop \n"; return -404;}
    int st = head->data ;
    Node * p = head ;
    head = head->next ;
    delete p ;
    current_size -- ;
    return st ;
}

// Clear implementation
void ListStack::clear() {
    // TODO: Traverse the linked list, deleting each node
    // TODO: Reset head to nullptr
    // TODO: Reset current_size to 0
    Node * p = head , *temp;
    while( p != NULL){
        temp = p ;
        p = p->next ;
        delete temp ;
    }
    head = NULL ;
    current_size = 0;

}

// Size implementation
int ListStack::size() const {
    // TODO: Return the current size (current_size)
    return current_size ;
}

// Top implementation
int ListStack::top() const {
    // TODO: Check if the stack is empty, display error message if it is
    // TODO: Return the data from the head node without removing it
    if(empty()){std :: cout <<"No top element, stack emmpty \n"; return -404 ;}
    else {
        return head->data ;
    }
}

// Empty implementation
bool ListStack::empty() const {
    // TODO: Return whether head is nullptr
    return head == NULL ;
}

// Print implementation
void ListStack::print() const {
    // TODO: Print stack elements from top to bottom in the format: |elem1, elem2, ..., elemN>
    // TODO: Traverse the linked list from head, printing each node's data
    std :: cout <<"| ";
    Node* p = head ; 
    while( p != NULL){
        if(p->next == NULL) std :: cout << p->data ;
        else {
            std :: cout << p->data <<" , ";
        }
        p = p->next ;
    }
    std :: cout <<" >\n";
}