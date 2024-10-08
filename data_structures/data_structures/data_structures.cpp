#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

short FindNumberInArraySlow(int arr[10], int arrLength, int num)
{
	int pos = -1;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == num)
			pos = i;
	}
	return pos;
}

short FindNumberInArrayFast(int arr[10], int arrLength, int num)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == num)
			return i;
	}
	return -1;
}

void StackTest()
{
	//stack: Last In First Out

	//create stack of integers 
	stack <int> stkNumbers;

	//push elemenets into stack
	stkNumbers.push(11);
	stkNumbers.push(22);
	stkNumbers.push(33);
	stkNumbers.push(44);
	stkNumbers.push(55);

	cout << "Stack Size: " << stkNumbers.size() << endl;

	cout << "Stack Elements: \n";
	while (!stkNumbers.empty())
	{
		cout << stkNumbers.top() << endl; //print top element

		stkNumbers.pop(); //pop top element
	}

}

void StackSwapTest()
{
	//stack container declration
	stack <int> MyStack1;
	stack <int> MyStack2;

	// pushing elements into stack1
	MyStack1.push(11);
	MyStack1.push(22);
	MyStack1.push(33);
	MyStack1.push(44);
	MyStack1.push(55);

	// pushing elements into stack2
	MyStack2.push(1);
	MyStack2.push(2);
	MyStack2.push(3);
	MyStack2.push(4);
	MyStack2.push(5);

	MyStack1.swap(MyStack2); //stack swap elemnets 

	//print stack1 elements
	cout << "\nStack1 Elements: ";
	while (!MyStack1.empty())
	{
		cout << MyStack1.top() << " ";

		MyStack1.pop();
	}

	//print stack2 elements
	cout << "\nStack2 Elements: ";
	while (!MyStack2.empty())
	{
		cout << MyStack2.top() << " ";

		MyStack2.pop();
	}

}

void VectorTest()
{
	vector <int> MyVector1;

	MyVector1.push_back(100);
	MyVector1.push_back(200);
	MyVector1.push_back(300);

	//unlike stack, in vector you can access any element directly
	cout << MyVector1[1] << endl; // 200
}

void QueueTest()
{
	//queue: First In First Out

	queue <int> MyQueue;

	MyQueue.push(2000);
	MyQueue.push(2001);
	MyQueue.push(2002);
	MyQueue.push(2003);
	MyQueue.push(2004);

	cout << "\nSize  : " << MyQueue.size();
	cout << "\nFront : " << MyQueue.front();
	cout << "\nBack  : " << MyQueue.back();
	

	cout << "\nMyQueue Elements: ";
	while (!MyQueue.empty())
	{
		cout << MyQueue.front() << " ";
		MyQueue.pop();
	}


}

void QueueSwapTest()
{
	queue <int> MyQueue1;
	queue <int> MyQueue2;

	MyQueue1.push(108);
	MyQueue1.push(109);
	MyQueue1.push(110);
	MyQueue1.push(111);
	MyQueue1.push(112);

	MyQueue2.push(1);
	MyQueue2.push(2);
	MyQueue2.push(3);
	MyQueue2.push(4);
	MyQueue2.push(5);

	MyQueue1.swap(MyQueue2); 

	cout << "\nQueue1 Elements: ";
	while (!MyQueue1.empty())
	{
		cout << MyQueue1.front() << " ";

		MyQueue1.pop();
	}

	cout << "\nQueue2 Elements: ";
	while (!MyQueue2.empty())
	{
		cout << MyQueue2.front() << " ";

		MyQueue2.pop();
	}
}

/* Singly Linked List class and funcs */
class SinglyNode
{
public:
	int value;
	SinglyNode* next;
};

void InsertAtTheBeginning(SinglyNode*& head, int Value)
{
	//allocate memory to a node
	SinglyNode* new_node = new SinglyNode(); //a new object will be created dynamically somewhere in the memory

	//insert date
	new_node->value = Value;
	new_node->next = head;

	//move head to new node
	head = new_node; //make the head point to the created object so we have its address
}

SinglyNode* Find(SinglyNode* head, int Value)
{
	 while (head != NULL) {

        if (head->value == Value)
            return head;

        head = head->next;
	 }

    return NULL;
}

void InsertAfter(SinglyNode* prev_node, int Value)
{
	if (prev_node == NULL)
	{
		cout << "\nThe given previous node cannot be NULL\n";
		return;
	}
	
	SinglyNode* new_node = new SinglyNode();
	new_node->value = Value;
	new_node->next = prev_node->next;
	prev_node->next = new_node;

}

void PrintLinkedList(SinglyNode* head)
{
	cout << endl;
	while (head != NULL)
	{
		cout << head->value << " ";
		head = head->next;
	}
}

void InsertAtEnd(SinglyNode*& head, int Value)
{
	SinglyNode* new_node = new SinglyNode();
	new_node->value = Value;
	new_node->next = NULL; //it must point to NULL cause it's the last node

	if (head == NULL)
	{
		head = new_node;
		return;
	}

	SinglyNode* LastNode = head;
	while (LastNode->next != NULL)
	{
		LastNode = LastNode->next;
	}
	
	LastNode->next = new_node;
}

void DeleteNode(SinglyNode*& head, int Value)
{
	SinglyNode* Current = head;
	SinglyNode* Prev = head;

	if (head == NULL) return;

	if (Current->value == Value) //if Value was in the first node
	{
		head = Current->next; //make the head point to the next node before delete the current node
		delete Current; //free from memory
		return;
	}

	//finding the node with the correct value
	while (Current != NULL && Current->value != Value)
	{
		Prev = Current;
		Current = Current->next;
	}

	//if node not found
	if (Current == NULL) return;

	//node found, we link the previous node with the next node before deleting current node
	Prev->next = Current->next;
	delete Current; //free from memory
}

void DeleteFirstNode(SinglyNode*& head)
{
	if (head == NULL) return;

	SinglyNode* Current = head;
	head = head->next;
	delete Current;
}

void DeleteLastNode(SinglyNode*& head)
{
	SinglyNode* Current = head;
	SinglyNode* Prev = head;

	if (head == NULL)
		return;

	if (Current->next == NULL) //if there is no next, means the first node is the last node
	{
		head = NULL;
		delete Current;//free from memory
		return;
	}

	// Find the key to be deleted
	while (Current != NULL && Current->next != NULL) 
	{
		Prev = Current;
		Current = Current->next;
	}

	// Remove the node
	Prev->next = NULL; //make the node before last node point to NULL
	delete Current; //free last node from memory

}

/* Doubly Linked List class and funcs */
class DoublyNode
{
public:
	int value;
	DoublyNode* next;
	DoublyNode* previous;
};

void InsertAtTheBeginning(DoublyNode*& head, int Value) //DLL = Doubly Linked List
{
	DoublyNode* new_node = new DoublyNode(); //new node in heap
	
	new_node->value = Value;
	new_node->previous = NULL;
	new_node->next = head;

	if (head != NULL)
		head->previous = new_node;

	head = new_node;

}

void PrintDoublyLinkedList(DoublyNode* head)
{
    cout << "\nNULL <--> ";
    while (head != NULL) {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL\n";
}

void PrintDoublyNodeDetails(DoublyNode* head)
{

	if (head->previous != NULL)
		cout << head->previous->value;
	else
		cout << "NULL";

	cout << " <--> " << head->value << " <--> ";

	if (head->next != NULL)
		cout << head->next->value << "\n";
	else
		cout << "NULL";

}

void PrintDoublyLinkedListDetails(DoublyNode* head)

{
	cout << "\n\n";
	while (head != NULL) {
		PrintDoublyNodeDetails(head);
		head = head->next;
	}
}

DoublyNode* Find(DoublyNode* head, int Value)
{
	//same algorithm as SinglyLinkedList (overload)
	while (head != NULL) {

		if (head->value == Value)
			return head;

		head = head->next;
	}

	return NULL;
}

void InsertAfter(DoublyNode* prev_node, int Value)
{
	if (prev_node == NULL)
	{
		cout << "\nThe given previous node cannot be NULL\n";
		return;
	}

	DoublyNode* new_node = new DoublyNode();

	new_node->value = Value;
	new_node->previous = prev_node;
	new_node->next = prev_node->next;

	prev_node->next = new_node;

	if (new_node->next != NULL)
		new_node->next->previous = new_node;

}

void InsertAtEnd(DoublyNode*& head, int Value)
{
	DoublyNode* new_node = new DoublyNode();
	new_node->value = Value;
	new_node->next = NULL;

	if (head == NULL)
	{
		new_node->previous == NULL;
		head = new_node;
		return;
	}

	DoublyNode* LastNode = head;
	while (LastNode->next != NULL)
	{
		LastNode = LastNode->next;
	} // Last Node found after loop

	new_node->previous = LastNode;
	LastNode->next = new_node;

}

void DeleteNode(DoublyNode*& head, DoublyNode*& NodeToDelete)
{

	if (head == NULL || NodeToDelete == NULL) 
		return;

	if (head == NodeToDelete) 
		head = NodeToDelete->next;

	if (NodeToDelete->next != NULL) 
		NodeToDelete->next->previous = NodeToDelete->previous;
	
	if (NodeToDelete->previous != NULL) 
		NodeToDelete->previous->next = NodeToDelete->next;
	
	delete NodeToDelete;
}

void DeleteFirstNode(DoublyNode*& head)
{
	if (head == NULL) return;

	DoublyNode* Current = head;
	head = Current->next; // or head = head->next
	
	if (head != NULL)
		Current->next->previous = NULL; // or head->previous = NULL

	delete Current;
}

void DeleteLastNode(DoublyNode*& head)
{
	if (head == NULL) return;

	
	if (head->next == NULL) 
	{
		delete head;
		head = NULL;
		return;
	}

	DoublyNode* Current = head;
	while (Current->next->next != NULL) //another way to find the node before the last node
	{
		Current = Current->next;
	}

	DoublyNode* LastNode = Current->next;
	Current->next = NULL; //Current is the node before the last node
	delete LastNode; //free last node from memory

}

union MyUnion
{
	int intValue;
	float floatValue;
	char charValue;
};

int main()
{
	MyUnion Union1;
	
	Union1.intValue = 42;
	std::cout << "Integer value: " << Union1.intValue << std::endl;

	Union1.floatValue = 3.14;
	std::cout << "Float value: " << Union1.floatValue << std::endl;

	Union1.charValue = 'A';
	std::cout << "Char value: " << Union1.charValue << std::endl;


	/*DoublyNode* head = NULL; 
	InsertAtEnd(head, 1111);
	InsertAtEnd(head, 2222);
	InsertAtEnd(head, 3333);
	InsertAtEnd(head, 4444);


	cout << "Doubly Linked List Before: ";
	PrintDoublyLinkedList(head);

	DeleteLastNode(head);

	cout << "\nDoubly Linked List After: ";
	PrintDoublyLinkedList(head);*/


	system("pause>0");
	return 0;
}
