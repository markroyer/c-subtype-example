
#include <stdlib.h>
#include <stdio.h>

#include "Object.h"
#include "Point.h"

static const char* Point_toString(Object* point);
int Point_getX(Point* point);
int Point_getY(Point* point);

static char str[20];

typedef struct Point_private_fields {
	int x;
	int y;
} Point_private_fields;

const Point_vtable Point_methods = {
	 .toString = Point_toString,
	 .getX = Point_getX,
	 .getY = Point_getY
};

Point* newPoint(int x, int y) {

	Point* result = malloc(sizeof(Point));

	result->parent = newObject();
	result->parent->derived_object = result;

	result->derived_object = NULL;

	result->parent->methods = (const Object_vtable*)(&Point_methods);
	result->methods = &Point_methods;

	result->private_fields = malloc(sizeof(Point_private_fields));
	result->private_fields->x = x;
	result->private_fields->y = y;
	return result;
}

void deletePoint(Point* p) {
	deleteObject(p->parent);
	free(p->private_fields);
	free(p);
}

static const char* Point_toString(Object* point) {

	Point* this = point->derived_object;

	sprintf(str, "(%i,%i)", this->private_fields->x, this->private_fields->y);
	return str;
}

int Point_getX(Point* point) {
	return point->private_fields->x;
}

int Point_getY(Point* point) {
	return point->private_fields->y;
}
