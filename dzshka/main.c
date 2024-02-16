#include "PeopleFile.h"




int main() {
	ArrayPeoples mainList;

	InitializationList(&mainList);

	AddNewPeople(&mainList, "BBB", "ZOV");
	AddNewPeople(&mainList, "AAA", "rucoblud");
	AddNewPeople(&mainList, "aaa", "debik");


	PrintArray(mainList);
	bublesort(&mainList, sortbyname);
	PrintArray(mainList);
	bublesort(&mainList, sortbysurname);
	PrintArray(mainList);
	freeArray(&mainList);

	return 0;
}