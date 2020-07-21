#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "LinkedList.h"
#include "Helper.h"

int main(int argc, char** argv)
{
	char* t[] = { (char*)"test1",(char*)"test2",(char*)"test3" };
	LinkedList<char*> L;
	int count = 0;
	while (count != 3)
	{
		L.add(t[count]);
		count++;
	}
	printList(L);
}