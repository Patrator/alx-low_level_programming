#ifndef DOG_H
#define DOG_H
/**
 * struct dog - combines three members
 * @name: first member
 * @age: second member which displays age
 * @owner: third member which displays owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /*DOG_H*/
