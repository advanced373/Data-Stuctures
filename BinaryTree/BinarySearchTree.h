#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
template<class T>
struct Node
{
	Node<T>* left, * right;
	T data;

	bool operator > (Node<T> member)const
	{
		if (strcmp(typeid(member.data).name(),"char *") == 0)
		{
			return false;
		}
		else
		{
			return (this->data > member.data);
		}
	}
	bool operator < (Node<T> member)const
	{
		if (typeid(member->data).name() == "char *")
		{
			return strcmp(this->data, member->data);
		}
		else
		{
			return (this->data < member.data);
		}
	}
	Node<T>& operator=(Node<T>& member)
	{
		this->data = member.data;
		this->left = member.left;
		this->right = member.right;
		return *this;
	}
};

template<class T>
class BinarySearchTree
{
protected:
	Node<T> *root;
	int size;
	void addToTree(Node<T>** node,T data);
	void printTreeElements(Node<T>* node);
	void printElementsFromALevel(Node<T>* node, int level);
	bool elementExist(Node<T>* node, T val);
	Node<T>* deleteANode(Node<T>* node, T val);
	T getMinValue(Node<T>* node);
	void deleteTheTree(Node<T>* node);
public:
	BinarySearchTree()
	{
		root = nullptr;
		size = 0;
	}
	~BinarySearchTree()
	{
		deleteTheTree(root);
		root = NULL;
		size = 0;
	}
	void addNode(T data);
	int getSize();
	void printTree();
	void printLevelElements(int level);
	bool elementExists(T val);
	void deleteNode(T data);
	void deleteTree();
};
template<class T>
void BinarySearchTree<T>::addToTree(Node<T>** node, T data)
{
	if (elementExists(data) == 0)
	{
		if ((*node) == nullptr)
		{
			Node<T>* newNode = new Node<T>;
			newNode->data = data;
			newNode->left = nullptr;
			newNode->right = nullptr;
			*node = newNode;
			this->size++;
		}
		else
		{
			if ((*node)->data > data)
			{
				addToTree(&(*node)->left, data);
			}
			else
			{
				addToTree(&(*node)->right, data);
			}
		}
	}
}
template<class T>
inline void BinarySearchTree<T>::printTreeElements(Node<T>* node)
{
	if (node != NULL)
	{
		if(node->right != nullptr)
			printTreeElements(node->right);
		std::cout << node->data << " ";
		if(node->left != nullptr)
			printTreeElements(node->left);
	}
}
template<class T>
inline void BinarySearchTree<T>::printElementsFromALevel(Node<T>* node, int level)
{
	if (node != nullptr)
	{
		if (level > 0)
		{
			printElementsFromALevel(node->left, level - 1);
			printElementsFromALevel(node->right, level - 1);
		}
		else
		{
			std::cout << node->data << " ";
		}
	}
}
template<class T>
inline bool BinarySearchTree<T>::elementExist(Node<T>* node, T val)
{
	if (node != nullptr)
	{
		if (node->data == val)
		{
			return true;
		}
		else
		{
			if (elementExist(node->right, val) == true)
				return true;
			else if (elementExist(node->left, val) == true)
				return true;
		}
	}
	return false;
}
template<class T>
inline Node<T>* BinarySearchTree<T>::deleteANode(Node<T>* node, T val)
{
	if (node == nullptr)
		return node;
	else if (node->data < val)
		node->right = deleteANode(node->right, val);
	else if (node->data > val)
		node->left = deleteANode(node->left, val);
	else
	{
		if (node->left == nullptr)
		{
			Node<T>* tmp = new Node<T>;
			tmp = node->right;
			delete(node);
			return tmp;
		}
		else if (node->right == NULL)
		{
			Node<T>* tmp = new Node<T>;
			tmp = node->left;
			delete(node);
			return tmp;
		}
		node->data = getMinValue(node->right);
		node->right = deleteANode(node->right, node->data);
	}
	return node;
}
template<class T>
inline T BinarySearchTree<T>::getMinValue(Node<T>* node)
{
	if (node->left == nullptr)
	{
		return node->data;
	}
	getMinValue(node->left);
}
template<class T>
inline void BinarySearchTree<T>::deleteTheTree(Node<T>* node)
{
	if (node != nullptr)
	{
		deleteTheTree(node->left);
		deleteTheTree(node->right);
		delete(node);
	}
}
template<class T>
void BinarySearchTree<T>::addNode(T data)
{
	if (root == nullptr)
	{
		root = new Node<T>;
		root->left = nullptr;
		root->right = nullptr;
		root->data = data;
	}
	else
	{
		addToTree(&this->root, data);
	}
}
template<class T>
inline int BinarySearchTree<T>::getSize()
{
	return size;
}
template<class T>
inline void BinarySearchTree<T>::printTree()
{
	if(root)
		printTreeElements(this->root);
	std::cout << std::endl;
}
template<class T>
inline void BinarySearchTree<T>::printLevelElements(int level)
{
	printElementsFromALevel(root,level);
	std::cout << std::endl;
}
template<class T>
inline bool BinarySearchTree<T>::elementExists(T val)
{
	return elementExist(this->root,val);
}
template<class T>
inline void BinarySearchTree<T>::deleteNode(T data)
{
	this->root=deleteANode(root, data);
}
template<class T>
inline void BinarySearchTree<T>::deleteTree()
{
	deleteTheTree(root);
}
#endif