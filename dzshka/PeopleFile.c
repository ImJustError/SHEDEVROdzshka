#include "PeopleFile.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>





void swap(People* people1, People* people2);
void* MemAlloc(int size);
void* MemReAlloc(int size, ArrayPeoples List);

int InitializationList(ArrayPeoples* List) {
	List->array = NULL;// короче тут просто нулевой делаем массив а то мб будут ошибки 
	List->count = 0;
	return 0;
}

int PrintArray(ArrayPeoples List) {// хз просто функци€ вывода листа
	printf("-*-*-*-*");
	for (int i = 0; i < List.count; i++) {
		printf("\n%s\n%s\n", List.array[i].name, List.array[i].surname);
		if(i+1!= List.count)printf("--------");
		else printf("-*-*-*-*\n");
	}
	return 0;
}


int AddNewPeople(ArrayPeoples* List,char* name, char* surname) {
	List->count++;//счетчик +1
	List->array = MemReAlloc(sizeof(People) * List->count, *List);// перевыделение пам€ти на +1 человека
	People NewPeople;
	NewPeople.name = MemAlloc(MAX_SIZE_STR * sizeof(char));// выделение пам€ти на им€ 
	if (!NewPeople.name)return 1;
	NewPeople.surname = MemAlloc(MAX_SIZE_STR * sizeof(char));// на его фамилию
	if (!NewPeople.surname)return 1;
	strcpy_s(NewPeople.name, MAX_SIZE_STR - 1, name);// копируем им€ в человечка
	strcpy_s(NewPeople.surname, MAX_SIZE_STR - 1, surname);
	List->array[List->count - 1] = NewPeople;
	return 0;
}

void* MemAlloc(int size) {//функци€€ выделени€ пам€ти с проверкой ошибок
	void* pointer = malloc(size);
	if (!pointer) printf("\nerror alloc mem\n"); 
	return pointer;
}

void* MemReAlloc(int size,ArrayPeoples List ) {// перевыделение с проверкой
	void* pointer = realloc(List.array,size);
	if (!pointer) printf("\nerror alloc mem\n");
	return pointer;
}

int freeArray(ArrayPeoples* List) {// освобождение массива
	for (int i = 0; i < List->count; i++) {
		free(List->array[i].name);
		free(List->array[i].surname);
	}
	free(List->array);
	return 0;
}

void sortbyname(People* people1, People* people2) {// ффунци€ дл€ сравнени€ двух человечков по имени
	if (strcmp(people1->name, people2->name) > 0) {
		swap(people1, people2);
	}
}

void sortbysurname(People* people1, People* people2) {// по фамилии
	if (strcmp(people1->surname, people2->surname) > 0) {
		swap(people1, people2);
	}
}

void swap(People* people1, People* people2) {// мен€ет двух человечков местами если надо
	People tmp = *people1;
	*people1 = *people2;
	*people2 = tmp;
}



void bublesort(ArrayPeoples* List,sortAlg func1) {// хз просто сама сортировка
	
	for (int i = 0; i < List->count-1; i++) {
		for (int j = 0; j < List->count-1; j++) {
			func1(&(List->array[j]), &(List->array[j + 1]));
		}
	}

}