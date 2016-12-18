/**
 * @file main.c
 * @author Mark Royer
 * @date 18 December 2016
 */

#include <stdlib.h>
#include <stdio.h>

#include "LinkedList.h"
#include "Point3d.h"

/**
 * Display a linked list with some objects in it.
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {

	LinkedList* list = newLinkedList();

	Object* o1 = newObject();
	Object* o2 = newObject();

	Point* p1 = newPoint(1, 2);
	Point* p2 = newPoint(3, 4);
	Point* p3 = newPoint(5, 6);
	Point* p4 = newPoint(7, 8);
	Point3d* p5 = newPoint3d(9,10,11);

	list->methods->add(list, o1);
	list->methods->add(list, o2);

	list->methods->add(list, p1->parent);
	list->methods->add(list, p2->parent);
	list->methods->add(list, p3->parent);
	list->methods->add(list, p4->parent);
	list->methods->add(list, p5->parent->parent);

	printf("The toString() method is based on each object's subtype definition.\n");
	printf("%s - LinkedList pointer\n", list->methods->toString(list->parent));
	
	Object* upCast = list->parent;
	
	list->methods->removeFirst(list);

	printf("%s - Object pointer\n", upCast->methods->toString(upCast));

	deleteLinkedList(list);

	deleteObject(o1);
	deleteObject(o2);
	
	deletePoint(p1);
	deletePoint(p2);
	deletePoint(p3);
	deletePoint(p4);
	deletePoint3d(p5);

	printf("Done!\n");

	return 0;
}
