#ifndef LINKED_LIST_H
#define LINKED_LIST_H
template<class T>
struct Node {
	Node<T>* next;
	T data;
};
template <class T>
class LinkedList
{
protected:
	Node<T>* head;
	Node<T>* tail;
	int Length;
public:
	LinkedList()
	{
		head = tail = nullptr;
		Length = 0;
	}
	~LinkedList()
	{
		while (Length > 0)
		{
			remove(Length - 1);
			Length--;
		}
	}
	LinkedList(const LinkedList& L)
	{
		this->head = L.head;
		this->tail = L.tail;
		this->Length = L.Length;
	}
	int length()
	{
		return Length;
	}
	void add(T data)
	{
		if (!head)
		{
			head = new Node<T>;
			head->data = data;
			head->next = nullptr;
			tail = head;
			Length++;
		}
		else
		{
			if (tail)
			{
				Node<T>* newData = new Node<T>;
				newData->data = data;
				newData->next = nullptr;
				tail->next = newData;
				tail = newData;
			}
			else
			{
				tail = new Node<T>;
				tail->data = data;
				tail->next = nullptr;
			}
			Length++;
		}
	}
	void remove(int position)
	{
		int counter = 1;
		Node<T>* iterator = begin();
		if (position == 0)
		{
			head = head->next;
			Length--;
			delete(iterator);
		}
		else
		{
			Node<T>* next = iterator->next;
			while (next != nullptr)
			{
				if (counter == position)
				{
					Node<T>* curr = new Node<T>;
					curr = iterator->next;
					iterator->next = next->next;
					Length--;
					delete(curr);
					break;
				}
				next = next->next;
				iterator = iterator->next;
				counter++;
			}
		}
	}
	Node<T>* get(int position)
	{
		int counter = 0;
		Node<T>* iterator = begin();
		while (iterator != nullptr)
		{
			if (counter == position)
			{
				return iterator;
			}
			iterator = iterator->next;
			counter++;
		}
		return nullptr;
	}
	Node<T>* begin()
	{
		Node<T>* newHead = new Node<T>;
		newHead = head;
		return newHead;
	}
	Node<T> end()
	{
		return tail;
	}
};
#endif
