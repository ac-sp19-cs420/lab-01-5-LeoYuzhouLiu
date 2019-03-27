#include <stdio.h>
#include <stdlib.h>

/*
This class builds a doubly-linked-list and a circular buffer.
I'm still unfamilier with parameters and classes in c, 
so errors are reported for some of my parameters and items, 
and I don't know how to solve them. 

@author Leo Yuzhou Liu
*/

/*
Double Linked-list
*/
typedef struct DLL1 {
	int data;
	int key;
	DLL1* next;
	DLL1* last;
} DLL1;

typedef struct DLL2 {
	DLL1* head;
} DLL2;

typedef struct CirBuf {
	DLL1* head;
	DLL1* tail;
	int size;
	int num;
} CirBuf;

// Here are a few simple methods for me to operate later.
int head(CirBuf* cb) {
	if (cb->head != NULL) {
		return cb->head->data;
	}
	return -1;
}

int tail(CirBuf* cb) {
	if (cb->tail != NULL) {
		return cb->tail->data;
	}
	return -1;
}

int pop(CirBuf* cb) {
	if (cb->tail == NULL) {
		return -1;
	}
	DLL1* nodePtr = cb->tail;
	cb->tail = cb->tail->last;
	nodePtr->last = NULL;
	nodePtr->next = NULL;
	int val = nodePtr->data;
	free(nodePtr);
	return val;
}

DLL2 insert(DLL2 d, int key, int data) {
	DLL1* newNode = (DLL1*)malloc(sizeof(DLL1));
	newNode->data = data;
	newNode->last = NULL;
	newNode->next = NULL;
	if (d->head == NULL) {
		d->head = newNode;
	}
	else {
		d->head->last = newNode;
		newNode->next = d->head;
		d->head = newNode;
	}
	return d;
}

/*
insert_dll() adds a new empty node gives it values.
*/
int insert_dll(Head head, int data, int key) {
	struct DLL1* nodePtr = head.head;
	struct DLL1* last = nodePtr;

	while (nodePtr->next != NULL) {
		if (nodePtr->key == key) {
			return 0;
		}
		if (key < nodePtr->key) {
			// sorting
			nodePtr->next = last->next;
			last->next = nodePtr;
			nodePtr->data = data;
			nodePtr->key = key;
		}
		last = nodePtr;
		nodePtr = nodePtr->next;
	}
}

// I don't know if that's how to return -1.
int is_in_list_dll(Head head, int key) {
	struct DLL1* nodePtr = head.head;
	if (nodePtr == NULL) {
		return 0;
	}
	while (nodePtr != NULL) {
		if (nodePtr->key == key) {
			return 1;
		}
		nodePtr = nodePtr->next;
	}
	
	return -1;

}

// find_element_dll() uses a while loop to find elements.
int find_element_dll(Head head, int key) {
	struct DLL1* nodePtr = head.head;
	while (nodePtr != NULL) {
		if (nodePtr->key == key) {
			return nodePtr->data;
		}
		nodePtr = nodePtr->next;
	}
	return 0;
}

// opposite of insert_dll()
int remove_dll(Head head, int key) {
	struct DLL1* nodePtr = head.head;
	struct DLL1* last = nodePtr;

	while (nodePtr->next != NULL) {
		if (nodePtr->key == key) {
			last->next = nodePtr->next;
			return 1;
		}
		last = nodePtr;
		nodePtr = nodePtr->next;
	}
	return 0;
}

// print_dll uses a while loop to print all elements.
void print_dll(Head head) {
	struct DLL1* nodePtr = head.head;
	while (nodePtr != NULL) {
		printf("%d\n", nodePtr->data);
		nodePtr = nodePtr->next;
	}
}

/*
create_array_dll() gives the linked-list properties of an array.
*/
int* create_array_dll(Head head) {
	struct DLL1* nodePtr = head.head;
	int size = 0;
	while (nodePtr != NULL) {
		size++;
		nodePtr = nodePtr->next;
	}
	int* result = new int[size];
	// VS reports error for "new".
	nodePtr = head.head;
	int i = 0;
	while (nodePtr != NULL) {
		result[i] = nodePtr->data;
		i++;
		nodePtr = nodePtr->next;
	}
	return result;
}



/*
Circular Buffer
*/

typedef struct circular_list {
	int size;
	int num;                   // num is the number of occupied slots 
	int data;
	circular_list* head;
	circular_list* tail;
} circular_list;

int create_cl(int size, Head head, Tail tail) {
	struct circular_list nodePtr = head.head;
	nodePtr->size = head->size;
	nodePtr->num = num;
	// parse in num
	if (head->size != 1) {
		return 1;
	}
	return 0;
}

// I'm not sure how to add a new element into a circular buffer.
int push_cl(Head head) {
	if (cl->num < cl->size) {
		struct circular_list* nodePtr = head.head;
		struct circular_list* newElement = nodePtr;
		head->next = nodePtr->next;
		nodePtr->next = head;
		num++;
		return 0;
	}
	return -1;
}

int pop_cl(circular_list* cl, Head head) {
	if (cl->head != NULL) {
		struct circular_list* nodePtr = head.head;
		struct circular_list* newElement = nodePtr;
		head->tail->next = nodePtr->next;
		/*
		I don't understand why to advance the tail in pop_cl()
		so I'm not sure what to parse in.
		*/
		head->num -= 1;
		return cl->tail->data;
	}
	return -1;
}

int head_cl(circular_list* cl) {
	if (cl->head != NULL) {
		return cl->tail->data;
	}
	return -1;
}


int main() {
	return 0;
}