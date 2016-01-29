
#include <stdio.h>



static void change(int a);
static void change2(int* a);


struct Person {
    char*   name;
    char*   surname;
};

static void print_person(struct Person p);




int main(int argc, char **argv)
{

	int i = 0;
	printf("i \t int \t %p value: %d\n", &i, i);
	
	
	//	&i 	is the memory address of i
	//	b 	is the memory address of i (pointer)
	//  &b	is the memory address of b
	//	*b	is the value of i (where it points)
	//	&*b is the memory address of *b and also i
	//	b and &*b are the same

	int* j = &i;
	printf("j \t int* \t %p points to: %p\t value: %d\n", &j , &*j, *j);

	
	// changes to i 
	i++;
	printf("---------------------------------------------\ni++\n");
	printf("i \t int \t %p value: %d\n", &i, i);
	printf("j \t int* \t %p points to: %p\t value: %d\n", &j , &*j, *j);



	//	call by value (i does not change)
	change(i);
	printf("---------------------------------------------\nCall by value (i does not change)\n");
	printf("i \t int \t %p value: %d\n", &i, i);
	printf("j \t int* \t %p points to: %p\t value: %d\n", &j , &*j, *j);



	//	call by reference (i changes)
	//	you can pass the address of i
	//	or you can pass j because it is a pointer
	change2(&i);
	change2(j);
	printf("---------------------------------------------\nCall by reference (i changes)\n");
	printf("i \t int \t %p value: %d\n", &i, i);
	printf("j \t int* \t %p points to: %p\t value: %d\n", &j , &*j, *j);




	// example with struct
	//
	struct Person p = {0};
	p.name = "Anastasios";
	p.surname = "Gogos";
	print_person(p);


    return 0;
}








//	call by value
static void change(int a) {
	a++;
}

//	call by reference
static void change2(int* a) {
	(*a)++;
}




static void print_person(struct Person p) {
	printf("\nName:\t\t%s\nSurname:\t%s\n", p.name, p.surname );
}
