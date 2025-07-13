Stack ADT :
	 1)Last in , First out structure .

Operations : 
	1) Push  : inserts element to top of stack 
	2) pop   : Removes last element
	3) Top   : Access the last element
	4) size  : Number of elements in stack
	5) empty : Check if stack is empty


Stack has been implemented using both :
	1) Array based implementation 
	2) Linked List based implementation

Array based Implementation:
	An array of dynamic size is taken . It is always ensured that the array has at least 50% space for elements to be pushed in .
	It is also ensured that no less than 25% of the array is always occupied .
	The  current size attribute of Array_Stack acts as the locator for top value . current_size -1 -th index of the array has the 
	top element .
	For push , elements are added to current_size index of array and current_size is incremented.
	For pop, the current_size is lowered .
	Stack is empty when current_size is 0 ;

Linked List Implementation :
	Initially , the head of Linked List is set to NULL . This can be used to check if stack is empty .
	For every push, the new element in new node is appointed as the head node .
	For every pop , the head element is removed .
	For top , data in head node is accessed .
	Size if found as current size is tracked .


The test.cpp provides a framework for rigorous testing of the implementation based on boolean functions for each operation .