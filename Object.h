
#ifndef OBJECT_H_
#define OBJECT_H_



typedef struct Object {
	void* derived_object;
	struct Object_private_fields* private_fields;
	const struct Object_vtable* methods;
} Object;

typedef struct Object_vtable {
	const char* (*toString)(Object*);
} Object_vtable;

Object* newObject();

void deleteObject(Object* obj);

#endif /* OBJECT_H_ */
