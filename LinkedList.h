#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdbool.h>

#include "Object.h"

/**
 * The LinkedList object structure extends Object.
 */
typedef struct LinkedList {
	Object* parent;
	void* derived_object;
	struct LinkedList_private_fields* private_fields;
	const struct LinkedList_vtable* methods;
} LinkedList;

/**
 * LinkedList public methods
 */
typedef struct LinkedList_vtable {
	/**
	 * Returns a string that shows the contents of the list.
	 * @param The list to create a string for (Not NULL)
	 * @return A string representation of this list
	 */
	const char* (*toString)(Object*);
	/**
	 * Adds an object to the end of the list.
	 * @param The list to add the object (Not NULL)
	 * @param
	 */
	void (*add)(LinkedList*, Object*);
	/**
	 * Removes the first element in the list.
	 * @param The list to remove the first element from (Not NULL)
	 * @return The element that was removed
	 */
	Object* (*removeFirst)(LinkedList*);
	/**
	 * @param The list to check if it's empty or not
	 * @return True IFF the list is empty
	 */
	bool (*isEmpty)(LinkedList*);
	/**
	 * Display each element of the list one per line.
	 * @param The list to display (Not NULL)
	 */
	void (*display)(LinkedList*);
} LinkedList_vtable;

LinkedList* newLinkedList();

void deleteLinkedList(LinkedList* list);

#endif /* LINKEDLIST_H_ */
