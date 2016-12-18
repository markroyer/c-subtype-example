
#ifndef OBJECT_H_
#define OBJECT_H_

/**
 * Root for all objects
 */
typedef struct Object {
	void* derived_object;
	struct Object_private_fields* private_fields;
	const struct Object_vtable* methods;
} Object;

/**
 * Object public methods
 */
typedef struct Object_vtable {
	/**
	 * Display a string representation of the object.
	 * @param Object to display (Not null)
	 * @return String representation Object@0x000
	 */
	const char* (*toString)(Object*);
} Object_vtable;

Object* newObject();

void deleteObject(Object* obj);

#endif /* OBJECT_H_ */
