
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "LinkedList.h"

static const char* LinkedList_toString(Object* obj);

static void LinkedList_add(LinkedList* list, Object* p);

static Object* LinkedList_removeFirst(LinkedList* list);

static bool LinkedList_isEmpty(LinkedList* list);

static void LinkedList_display(LinkedList* list);

typedef struct Node {
	Object* item;
	struct Node* next;
} Node;

static Node* newNode(Object* item, Node* next) {
	Node* result = malloc(sizeof(Node));
	result->item = item;
	result->next = next;
	return result;
}

static void deleteNode(Node* n) {
	free(n);
}

typedef struct LinkedList_private_fields {
	Node* first;
} LinkedList_private_fields;

// @formatter:off
/**
 * LinkedList public methods
 */
const LinkedList_vtable LinkedList_methods = {
	.toString = LinkedList_toString,
	.add = LinkedList_add,
	.removeFirst = LinkedList_removeFirst,
	.isEmpty = LinkedList_isEmpty,
	.display = LinkedList_display
};
// @formatter:on

static char str[256];

/**
 * Creates a new list.
 *
 * @return The new list
 */
LinkedList* newLinkedList() {
	LinkedList* result = malloc(sizeof(LinkedList));
	result->parent = newObject();
	result->parent->derived_object = result;

	result->parent->methods = (const Object_vtable*) (&LinkedList_methods);

	result->derived_object = NULL;

	result->methods = &LinkedList_methods;

	result->private_fields = malloc(sizeof(LinkedList_private_fields));

	result->private_fields->first = NULL;

	return result;
}

/**
 * Deletes the given list.
 *
 * @param list The list to delete
 */
void deleteLinkedList(LinkedList* list) {

	Node* first = list->private_fields->first;

	while (first != NULL) {
		Node* prev = first;
		first = first->next;
		free(prev);
	}

	deleteObject(list->parent);
	free(list->private_fields);
	free(list);
}

static void LinkedList_add(LinkedList* list, Object* item) {

	Node* n = newNode(item, NULL);

	if (list->private_fields->first == NULL) {
		list->private_fields->first = n;
	} else {
		Node* last = list->private_fields->first;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = n;
	}

}

static Object* LinkedList_removeFirst(LinkedList* list) {
	Node* first = list->private_fields->first;
	void* result = NULL;
	if (first != NULL) {
		result = first->item;
		list->private_fields->first = first->next;
		deleteNode(first);
	}
	return result;
}

static bool LinkedList_isEmpty(LinkedList* list) {
	return list->private_fields->first == NULL;
}

static void LinkedList_display(LinkedList* list) {

	Node* n = list->private_fields->first;

	while (n != NULL) {
		printf("%s\n", n->item->methods->toString(n->item));
		n = n->next;
	}
}

static const char* LinkedList_toString(Object* obj) {
//  An example of calling the Object supertype toString method
//	extern Object_vtable Object_methods;
//	sprintf(str, "%s%s", "Listed: ", Object_methods.toString(obj));

	LinkedList* this = obj->derived_object;
	Node* n = this->private_fields->first;
	strcpy(str, "[ ");
	while (n != NULL) {
		strcat(str, n->item->methods->toString(n->item));
		n = n->next;
		if (n != NULL)
			strcat(str, ", ");
	}
	strcat(str, " ]");

	return str;
}
