#ifndef HELPER_H
#define HELPER_H
#include "LinkedList.h"
template<class T>
void printList(LinkedList<T> &L)
{
	Node<T>* iterator = L.begin();
	while (iterator != nullptr)
	{
		std::cout << iterator->data << " ";
		iterator = iterator->next;
	}
}
#endif
