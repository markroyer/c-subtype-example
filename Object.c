/**
 * @file Object.c
 * @author Mark Royer
 * @date 18 December 2016
 */

#include <stdlib.h>
#include <stdio.h>

#include "Object.h"

static const char* Object_toString(Object* obj);

static char str[40];

const Object_vtable Object_methods = {
	 .toString = Object_toString
};

typedef struct Object_private_fields {

} Object_private_fields;

/**
 * Creates a new object.
 *
 * @return The newly created object
 */
Object* newObject() {
	Object* result = malloc(sizeof(Object));
	result->derived_object = NULL;
	result->private_fields = malloc(sizeof(Object_private_fields));
	result->methods = ((const Object_vtable*)&Object_methods);

	return result;
}

/**
 * Delete the object.
 *
 * @param obj The object to delete
 */
void deleteObject(Object* obj) {
	free(obj->private_fields);
	free(obj);
}

static const char* Object_toString(Object* obj) {
	sprintf(str, "Object@%p", obj);
	return str;
}
