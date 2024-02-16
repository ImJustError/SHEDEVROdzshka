#pragma once


#define MAX_SIZE_STR 50

typedef struct people {// стуктурка человечка
	char* name;
	char* surname;
}People;

typedef struct { // структура списка человечков
	struct people* array;
	int count;
}ArrayPeoples;

typedef int(*sortAlg)(People* people1, People* people2);// основная цель дзшки проверить знание использование этой хуйни

int InitializationList(ArrayPeoples* List);
int PrintArray(ArrayPeoples List);
int AddNewPeople(ArrayPeoples* List, char* name, char* surname);
int freeArray(ArrayPeoples* List);
void bublesort(ArrayPeoples* List, sortAlg func1);

void sortbyname(People* people1, People* people2);
void sortbysurname(People* people1, People* people2);
