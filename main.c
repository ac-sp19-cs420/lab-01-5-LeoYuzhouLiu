#include <stdio.h>
#include <stdlib.h>
//#include <iostream>

/*
This class builds a linked list, and it builds a stack and a queue.

@author Leo Yuzhou Liu
*/
//using namespace std;

struct Node {
	int data;
	int key;
	struct Node* next;
};

typedef struct Head {
	struct Node* head;
}Head;

/*
The insert() determines if the node conflicts with any existing nodes first.
If not, it grabs the 'next' of previous node and hold it in to irself,
then connects it's 'next' to the next node.
*/
int insert(Head head, int data, int key) {
	struct Node* nodePtr = head.head;
	struct Node* prev = nodePtr;

	while (nodePtr->next != NULL) {
		if (nodePtr->key == key) {
			return 0;
		}
		if (key < nodePtr->key) {
			nodePtr->next = prev->next;
			prev->next = nodePtr;
			nodePtr->data = data;
			nodePtr->key = key;
		}
		prev = nodePtr;
		nodePtr = nodePtr->next;
	}

}

/*
The remove() locates the node then does the opposite thing of inset().
*/
int remove(Head head, int data, int key) {
	struct Node* nodePtr = head.head;
	struct Node* prev = nodePtr;

	while (nodePtr->next != NULL) {
		if (nodePtr->key == key) {
			prev->next = nodePtr->next;
			return 1;
		}

		prev = nodePtr;
		nodePtr = nodePtr->next;
	}
	return 0;
}

void print_list(Head head) {
	struct Node* nodePtr = head.head;
	while (nodePtr != NULL) {
		// cout << nodePtr->data << "\t";
		printf("%d\t", nodePtr->data);
		nodePtr = nodePtr->next;
	}
}

/*
create_array() gives the linked-list properties of an array.*/
int* create_array(Head head) {
	struct Node* nodePtr = head.head;
	int size = 0;
	while (nodePtr != NULL) {
		size++;
		nodePtr = nodePtr->next;
	}
	// int* result = new int[size];
	int* result = (int*)malloc(sizeof(int) * size);
	nodePtr = head.head;
	int pos = 0;
	while (nodePtr != NULL) {
		result[pos] = nodePtr->data;
		pos++;
		nodePtr = nodePtr->next;
	}
	return result;
}

/*
push_stack() creates a temporary head which contains desired data,
and then turn the original head into a normal node,
then connects the new head(temp) with it.
*/
void push_stack(Head head, int val) {
	struct Node* nodePtr = head.head;
	struct Node* temp = head.head;
	temp->data = val;
	temp->next = nodePtr;
	head.head = temp;
}

/*
Redefine the head node.
*/
void pop_stack(Head head) {
	struct Node* nodePtr = head.head;
	head.head = head.head->next;
}

/*
is_empty() loops the stack and returns 0 once it detects any non-null value.
It can be used by both the stack and the queue.
*/
int is_empty(Head head) {
	struct Node* nodePtr = head.head;
	if (nodePtr->data != NULL) {
		return 0;
	}
	return 1;
}

/*
This does the same thing as push_stack()
*/
void push_queue(Head head, int val) {
	struct Node* nodePtr = head.head;
	struct Node* temp = head.head;
	temp->data = val;
	temp->next = nodePtr;
	head.head = temp;
}

/*
pop_queue() locates the last three node of the queue
and make the last two node points to NULL.
*/
void pop_queue(Head head) {
	struct Node* nodePtr = head.head;
	while (nodePtr->next->next == NULL) {
		nodePtr->next = NULL;
		nodePtr = nodePtr->next;
	}
}

/*
Loops the list and detect the target node.
*/
int is_in_list(Head head, int key) {
	struct Node* nodePtr = head.head;
	while (nodePtr != NULL) {
		if (nodePtr->key == key) {
			return 1;
		}
		nodePtr = nodePtr->next;
	}
	return 0;
}

/*
last() locates the last node and returns its data.
*/
int last(Head head) {
	struct Node* nodePtr = head.head;
	while (nodePtr->next == NULL) {
		return nodePtr->data;
		nodePtr = nodePtr->next;
	}
}

/*
Locates the node and return its data.*/
int find(Head head, int key) {
	struct Node* nodePtr = head.head;
	while (nodePtr != NULL) {
		if (nodePtr->key == key) {
			return nodePtr->data;
		}
		nodePtr = nodePtr->next;
	}
	return 0;
}

int main() {
	//struct Node* head = new struct Node;
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));

	head->data = 10;
	head->next = (struct Node*)malloc(sizeof(struct Node));
	head->next->next = 0;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data;
	return 0;
}