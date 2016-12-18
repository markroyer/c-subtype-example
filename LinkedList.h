
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdbool.h>

#include "Object.h"

typedef struct LinkedList {
	Object* parent;
	void* derived_object;
	struct LinkedList_private_fields* private_fields;
	const struct LinkedList_vtable* methods;
} LinkedList;

typedef struct LinkedList_vtable {
	const char* (*toString)(Object*);
	void (*add)(LinkedList*, Object*);
	Object* (*removeFirst)(LinkedList*);
	bool (*isEmpty)(LinkedList*);
	void (*display)(LinkedList*);
} LinkedList_vtable;

LinkedList* newLinkedList();

void deleteLinkedList(LinkedList* list);

#endif /* LINKEDLIST_H_ */
