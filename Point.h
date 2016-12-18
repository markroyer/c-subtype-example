
#ifndef POINT_H_
#define POINT_H_

#include "Object.h"

typedef struct Point {
	Object* parent;
	void* derived_object;
	struct Point_private_fields* private_fields;
	const struct Point_vtable* methods;
} Point;

typedef struct Point_vtable {
	const char* (*toString)(Object*);
	int (*getX)(Point*);
	int (*getY)(Point*);
} Point_vtable;

Point* newPoint(int x, int y);

void deletePoint(Point* p);

#endif /* POINT_H_ */
