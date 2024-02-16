#pragma once


#define MAX_SIZE_STR 50

typedef struct people {// stryktyra cheloveka
	char* name;
	char* surname;
}People;

typedef struct { // stryktyra spiska 
	struct people* array;
	int count;
}ArrayPeoples;

typedef int(*sortAlg)(People* people1, People* people2);// glavnaya hueta

int InitializationList(ArrayPeoples* List);
int PrintArray(ArrayPeoples List);
int AddNewPeople(ArrayPeoples* List, char* name, char* surname);
int freeArray(ArrayPeoples* List);
void bublesort(ArrayPeoples* List, sortAlg func1);

void sortbyname(People* people1, People* people2);
void sortbysurname(People* people1, People* people2);
