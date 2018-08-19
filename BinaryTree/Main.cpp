
#include <iostream>
#include <conio.h>

using namespace std;

#include "BinaryTree.h"
#include "Element.h"



int main(void)
{
	BinaryTree<int> bTree;

	bTree.insert(50);
	bTree.insert(45);
	bTree.insert(30);
	bTree.insert(55);
	bTree.insert(55);
	bTree.insert(53);



	cout << "\nYour Tree Inorder:" << endl;
	bTree.inorder();

	cout << "\nYour Tree postorder:" << endl;
	bTree.postorder();

	cout << "\nYour Tree preorder:" << endl;
	bTree.preorder();

	cout << "\nSearch 30:" << endl;
	bTree.searchElement(30);

	cout << "\n\nRemove 45:" << endl;
	bTree.removeInfo(45);
	bTree.inorder();

	cout << "\nDepth of Tree:" << bTree.depth(bTree.getRoot()) << endl;

	_getch();
	return 0;
}