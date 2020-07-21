#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "BinarySearchTree.h"

int main(int argc, char** argv)
{
	BinarySearchTree<char>* B = new BinarySearchTree<char>;
	B->addNode('5');
	B->addNode('f');
	B->addNode('3');
	B->addNode('0');
	B->addNode('a');
	B->printTree();
	B->printLevelElements(1);
	B->deleteNode('8');
	B->printTree();
	B->deleteTree();
	B->printTree();
	return 0;
}