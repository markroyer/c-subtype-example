
#include <stdlib.h>
#include <stdio.h>

#include "Point3d.h"

static const char* Point3d_toString(Object* point);
static int Point3d_getX(Point* point);
static int Point3d_getY(Point* point);

static char str[20];

typedef struct Point3d_private_fields {
	int z;
} Point3d_private_fields;


const Point3d_vtable Point3d_methods = {
	.toString = Point3d_toString,
	.getX = Point3d_getX,
	.getY = Point3d_getY
};

Point3d* newPoint3d(int x, int y, int z) {

	Point3d* result = malloc(sizeof(Point3d));

	result->parent = newPoint(x, y);
	result->parent->derived_object = result;

	result->derived_object = NULL;

	result->parent->parent->methods = (const Object_vtable*) (&Point3d_methods);
	result->parent->methods = (const Point_vtable*) (&Point3d_methods);
	result->methods = &Point3d_methods;

	result->private_fields = malloc(sizeof(Point3d_private_fields));
	result->private_fields->z = z;
	return result;

}

void deletePoint3d(Point3d* p) {
	deletePoint(p->parent);
	free(p->private_fields);
	free(p);
}

static const char* Point3d_toString(Object* point) {
	Point* parent = point->derived_object;
	Point3d* this = parent->derived_object;
	sprintf(str, "(%d,%d,%d)", parent->methods->getX(parent),
			parent->methods->getY(parent), this->private_fields->z);
	return str;
}


static int Point3d_getX(Point* point) {
	extern Point_vtable Point_methods;
	return Point_methods.getX(point);
}

static int Point3d_getY(Point* point) {
	extern Point_vtable Point_methods;
	return Point_methods.getY(point);
}
