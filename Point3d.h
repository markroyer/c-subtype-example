/**
 * @file Point3d.h
 * @author Mark Royer
 * @date 18 December 2016
 */

#ifndef POINT3D_H_
#define POINT3D_H_

#include "Point.h"

typedef struct Point3d {
	Point* parent;
	void* derived_object;
	struct Point3d_private_fields* private_fields;
	const struct Point3d_vtable* methods;
} Point3d;

typedef struct Point3d_vtable {
	const char* (*toString)(Object*);
	int (*getX)(Point*);
	int (*getY)(Point*);
} Point3d_vtable;

Point3d* newPoint3d(int x, int y, int z);

void deletePoint3d(Point3d* p);

#endif /* POINT3D_H_ */
