#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Element.h"
#include <iostream>

using namespace std;

template<typename T>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const BinaryTree &leaf);
	BinaryTree<T> &operator=(const BinaryTree<T> &leaf);

	void insert(T x);

	void inorder() const;
	void preorder() const;
	void postorder() const;

	void searchElement(T y);

	void removeInfo(T y);

	int depth(Element<T> *leaf);
	bool isEmpty();
	Element<T> *getRoot() const;
	~BinaryTree();
private:
	Element<T> *root;
	Element<T> *insert(T x, Element<T>* leaf);

	Element<T> *printInorder(Element<T> * leaf) const;
	Element<T> *printPreorder(Element<T> * leaf) const;
	Element<T> *printPostorder(Element<T> * leaf) const;

	Element<T> *search(const T x, Element<T> *leaf);

	Element<T> *clearData(Element<T>* leaf) const;
	Element<T> *remove(T x, Element<T> *leaf);

	Element<T> *findMinInfo(Element<T> *leaf);
	Element<T> *getInfo(Element<T> *leaf, Element<T> *root);

	Element<T> *getLeft(Element<T> *leaf) const;
	Element<T> *getRight(Element<T> *right) const;
	
};

template<typename T>
int BinaryTree<T>::depth(Element<T> *leaf)
{
	if (leaf == nullptr)
	{
		return 0;
	}
	int leftDepth = depth(leaf->left);
	int rightDepth = depth(leaf->right);

	return leftDepth>rightDepth ? leftDepth + 1 : rightDepth + 1;
}

template<typename T>
Element<T> * BinaryTree<T>::getRight(Element<T> * leaf) const
{

	if (leaf == nullptr)
	{
		return nullptr;
	}
	
	else if (leaf->right != nullptr)
	{
		return leaf->right;
	}
}

template<typename T>
Element<T> * BinaryTree<T>::getLeft(Element<T> * leaf) const
{
	if (leaf == nullptr) 
	{
		return nullptr; 
	}

	else if (leaf->left != nullptr)
	{
		return leaf->left;
	}
}

template<typename T>
bool BinaryTree<T>::isEmpty()
{
	return(getRoot == nullptr);
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree &leaf)
{
	getInfo(leaf.root, getRoot());
}

template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T> &leaf)
{
	if (this != &binarytree)
	{
		if (root != nullptr)
		{
			removeInfo(getRoot());
		}
	}
	if (leaf.root == nullptr)
	{
		root = nullptr;
	}
	else
	{
		getInfo(leaf.root, getRoot());
	}
	return *this;
}

template<typename T>
Element<T> *BinaryTree<T>::search(const T x, Element<T> *leaf)
{
	if (leaf != nullptr)
	{
		if (x == leaf->info)
		{
			cout << leaf->info;
		}
		else if (x < leaf->info)
		{
			search(x, leaf->left);
		}
		else
		{
			search(x, leaf->right);
		}
	}
	else
	{
		return nullptr;
	}
}

template<typename T>
Element<T>* BinaryTree<T>::clearData(Element<T>* leaf) const
{
	if (leaf == nullptr)
	{
		return nullptr;
	}
	else 
	{
		clearData(leaf->left);
		clearData(leaf->right);
		delete leaf;
	}
}

template<typename T>
Element<T>* BinaryTree<T>::remove(T x, Element<T>* leaf)
{
	Element<T> *temp;
	if (leaf == nullptr)
	{
		return nullptr;
	}
	else if (x < leaf->info)
	{
		leaf->left = remove(x, leaf->left);
	}
	else if (x > leaf->info)
	{
		leaf->right = remove(x, leaf->right);
	}
	else if (leaf->left && leaf->right)
	{
		temp = findMinInfo(leaf->right);
		leaf->info = temp->info;
		leaf->right = remove(leaf->info, leaf->right);
	}
	else
	{
		temp = leaf;
		if (leaf->left == nullptr)
		{
			leaf = leaf->right;
		}
		else if (leaf->right == nullptr)
		{
			leaf = leaf->left;
		}
		delete temp;
	}

	return leaf;
}

template<typename T>
Element<T>* BinaryTree<T>::findMinInfo(Element<T>* leaf)
{
	if (leaf == nullptr)
	{
		return nullptr;
	}
	else if (leaf->left == nullptr)
	{
		return leaf;
	}
	else
	{
		return findMinInfo(leaf->left);
	}
}

template<typename T>
Element<T>* BinaryTree<T>::getInfo(Element<T>* leaf, Element<T> *root)
{
	if (root != nullptr)
	{
		leaf = new Node<T>;

		if (root == nullptr)
		{
			getInfo(leaf->left, root->left);
			getInfo(leaf ->right, root->right);
		}
		else
		{
			leaf = nullptr;
		}
	}
	return nullptr;
}

template<typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template<typename T>
Element<T> *BinaryTree<T>::insert(T x, Element<T>* leaf)
{
	if (leaf == nullptr)
	{
		leaf = new Element<T>;
		leaf->info = x;
		leaf->left = leaf->right = nullptr;
	}
	else if (x <= leaf->info)
	{
		leaf->left = insert(x, leaf->left);
	}
	else if (x >= leaf->info)
	{
		leaf->right = insert(x, leaf->right);
	}
	return leaf;
}

template<typename T> 
void BinaryTree<T>::insert(T x)
{
	root = insert(x, root);
}

template<typename T>
void BinaryTree<T>::inorder() const
{
	printInorder(root);
	cout << endl;
}

template<typename T>
void BinaryTree<T>::preorder() const
{
	printPreorder(root);
	cout << endl;
}

template<typename T>
void BinaryTree<T>::postorder() const
{
	printPostorder(root);
	cout << endl;
}

template<typename T>
void BinaryTree<T>::searchElement(T y)
{
	search(y, root);
}

template<typename T>
void BinaryTree<T>::removeInfo(T y)
{
	remove(y, root);
}

template<typename T>
Element<T> *BinaryTree<T>::printInorder(Element<T>* leaf) const
{
	if (leaf == nullptr)
	{
		return leaf;
	}
	printInorder(leaf->left);

	cout << leaf->info << " ";

	printInorder(leaf->right);
}

template<typename T>
Element<T> *BinaryTree<T>::printPreorder(Element<T>* leaf) const
{
	if (leaf == nullptr)
	{
		return leaf;
	}
	cout << leaf->info << " ";

	printPreorder(leaf->left);

	printPreorder(leaf->right);
}

template<typename T>
Element<T> *BinaryTree<T>::printPostorder(Element<T>* leaf) const
{
	if (leaf == nullptr)
	{
		return leaf;
	}

	printPostorder(leaf->left);

	printPostorder(leaf->right);

	cout << leaf->info << " ";
}


template<typename T>
BinaryTree<T>::~BinaryTree()
{
	root = clearData(root);
}

template<typename T>
Element<T>* BinaryTree<T>::getRoot() const
{
	return root;
}

#endif // !BINARYTREE_H