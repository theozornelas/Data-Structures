/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  4/11/16
 *****************************************************/

#ifndef REDBLACKTREE_H_
#define REDBLACKTREE_H_

#include "Functions.h"
#include "Node.h"

#include <deque>
#include <iterator>
#include <math.h>
#include <iomanip>


/*******************************************************
 * This is the Red-Black Tree implementation class, first
 * as a tree, then as a dictionary. The tree has balancing
 * print, insertion, deletion, and print methods.The tree
 * methods are private, so the user does not have access
 * to them. The tree uses the node nil as the point of
 * reference instead of NULL. The tree implementation was
 * based on pseudocode in the book introduction to algorithms
 * 3rd edition.
 *******************************************************/

template <class T, class E>
class RedBlackTree
{

	//dictionary ADT using a tree

public:

	RedBlackTree();
	~RedBlackTree();

	bool IsEmpty();

	void Insert(T key, E dataValue);

	void Delete(T key);

	T SearchDictionary(T key);

	void Print();

private:

	//utility method
	char enumToChar(Color color);


	//realigns the tree to the left
	void LeftRotate(node<T,E> *x);

	//realigns the tree to the left (mirror of left rotate)
	void RightRotate(node<T,E> *y);


	//inserts a new node into the tree
	void RBInsert(T newKey, E newData);


	//fixes the tree properties of the tree
	void RBInsertFix(node<T,E> * z);


	//moves the right most node into the parent being removed
	void RBTransplant(node<T,E> * u, node<T,E> *v);


	//deletes node from tree
	void RBDelete(int del);


	//realign after a deletion is being done
	void RBDeleteFixup(node<T,E> * x);

//search for the specific node
	node<T,E>* Search(node<T,E> *findNode, int val);

	//returns the smallest node
	node<T,E>* minimumVal(node<T,E>*x);

	//max height of the tree
	int maxHeight(node<T,E> *p);


	//prints the tree in a beautiful way
	void printPretty(int level, int indentSpace, ostream& out);

	//converts the tree contents into a string for output
	string intToString(int val, Color nodeColor);

	void printBranches(int branchLen, int nodeSpaceLen, int startLen,
			int nodesInThisLevel, const deque<node<T,E>*>& nodesQueue, ostream& out);

	void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel,
			const deque<node<T,E>*>& nodesQueue, ostream& out);

	void printLeaves(int indentSpace, int level, int nodesInThisLevel,
			const deque<node<T,E>*>& nodesQueue, ostream& out);


	//tree root
	node<T,E> * root;

	//node nil
	node<T,E> * nil;


};

//constructor - sets root to nil
template <class T, class E>
RedBlackTree<T, E> :: RedBlackTree()
{

	this->nil = new node<T,E>;
	nil->setColor(BLACK);
	nil->setKey(-1);

   this->root = nil;



}
//destructor
template <class T, class E>
RedBlackTree<T,E> :: ~RedBlackTree(){}

//if the tree is empty
template <class T, class E>
bool RedBlackTree<T,E> ::  IsEmpty()
{
	return this->root == NULL;
}

//inserts a new node as a dictionary
template <class T, class E>
void RedBlackTree<T,E> :: Insert(T key, E dataValue)
{

	cout << endl << InstructionHeader("Inserting ", key, dataValue) << endl;

	RBInsert(key, dataValue);
}

//deletes an specified node
template <class T, class E>
void RedBlackTree<T,E> :: Delete(T key)
{

	//get node to delete
	node<T,E> *searchPtr = Search(this->root, key);

	cout << endl << InstructionHeader("Deleting: " ,searchPtr->getKey(), searchPtr->getData());


	//delete the node
	RBDelete(key);
}

//searches for an specific key (gets a velue, not the node)
template <class T, class E>
T RedBlackTree<T,E> :: SearchDictionary(T key)
{
	node<T,E> *searchPtr;
	searchPtr = this->root;

	//iterates thruogh the whole tree until it hits the one before nil
	while(searchPtr != this->nil && key!= searchPtr->getKey())
	{
		if (key < searchPtr->getKey())
		{
			searchPtr = searchPtr->getLeft();
		}
		else
		{
			searchPtr = searchPtr->getRight();
		}
	}

	return searchPtr->getKey();
}

//converts node data to string
template <class T, class E>
string RedBlackTree<T,E> :: intToString(int val, Color nodeColor)
{
	 ostringstream ss;

	if(val == -1)
	{
		ss << "N";
	}
	else
	{
		ss << val;
	}


	ss << " " << enumToChar(nodeColor);
	  return ss.str();
}

//returns the copy of the node with that key
template <class T, class E>
node<T,E>* RedBlackTree<T,E> :: Search(node<T,E> *findNode, int val)
{
	node<T,E> *found;

	found = findNode;

	while(found != this->nil && val!= found->getKey())
	{
		if (val < found->getKey())
		{
			found = found->getLeft();
		}
		else
		{
			found = found->getRight();
		}
	}

	return found;
}

//rotates the tree to the left
template <class T, class E>
void RedBlackTree<T,E> :: LeftRotate(node<T,E> *x)
{
	node<T,E>*y;
	y= x->getRight(); //y==right


	x->setRight(y->getLeft()); //x is the left node of y


	//if it is not the end of the list
	if(y->getLeft() != this->nil)
	{
		//parent of y is x
		y->getLeft()->setParent(x);
	}

	y->setParent(x->getParent());

	if(x->getParent() == this->nil)
	{
		this->root = y;
	}
	else if(x==x->getParent()->getLeft())
	{
		x->getParent()->setLeft(y);
	}
	else
	{
		x->getParent()->setRight(y);
	}

	y->setLeft(x);
	x->setParent(y);
}


//Symmetrical to left rotate
template <class T, class E>
void RedBlackTree<T,E> :: RightRotate(node<T,E> *y)
{
	node<T,E>*x;
	x= y->getLeft();

	y->setLeft(x->getRight());

	if(x->getRight() != this->nil)
	{
		//y->getRight()->setParent(x);
		x->getRight()->setParent(y);
	}

	x->setParent(y->getParent());

	if(y->getParent() == this->nil)
	{
		this->root = x;
	}
	else if(y==y->getParent()->getRight())
	{
		y->getParent()->setRight(x);
	}
	else
	{
		y->getParent()->setLeft(x);
	}

	x->setRight(y);
	y->setParent(x);
}

template <class T, class E>
void RedBlackTree<T,E> :: RBInsert(T newKey, E newData)
{

	node<T,E> * z;

	//create new node with inserted data and initialize
	z = new node<T,E>();

	z->setKey(newKey);
	z->setData(newData);

	z->setParent(this->nil);
	z->setRight(this->nil);
	z->setLeft(this->nil);

	//create x and y
	node<T,E> * y;
	node<T,E> * x;

	y=this->nil;
	x=this->root;

	//marks the x nodes in the tree
	while(x != this->nil)
	{


		y = x;
		if(z->getKey() < x->getKey())
		{


			x = x->getLeft();
		}
		else
		{

			x = x->getRight();
		}


	}//end of while


	//sets the node related to z
	z->setParent(y);

	//if node is not large enough
	if(y == this->nil)
	{
		this->root = z;
	}
	else if(z->getKey() < y->getKey())
	{
		y->setLeft(z);
	}
	else
	{
		y->setRight(z);
	}

	//fix the tree
	RBInsertFix(z);


}
template <class T, class E>
void RedBlackTree<T,E> :: RBInsertFix(node<T,E> * z)
{

	node<T,E> * y;

	//while the parent is a red
	while(z->getParent()->getColor() == RED)
	{

		//set z to be the parent
		if(z->getParent() == z->getParent()->getParent()->getLeft())
		{

			y = z->getParent()->getParent()->getRight();
			if(y->getColor() == RED)
			{


				z->getParent()->setColor(BLACK);
				y->setColor(BLACK);
				z->getParent()->getParent()->setColor(RED);
				z = z->getParent()->getParent();
			}
			else
			{
				if(z == z->getParent()->getRight())
				{
					z = z->getParent();
					LeftRotate(z);//changed
				}

				z->getParent()->setColor(BLACK);
				z->getParent()->getParent()->setColor(RED);
				RightRotate(z->getParent()->getParent());

			}

		}//end of if
		else
		{
			y = z->getParent()->getParent()->getLeft();
			if(y->getColor() == RED)
			{
				z->getParent()->setColor(BLACK);
				y->setColor(BLACK);
				z->getParent()->getParent()->setColor(RED);
				z = z->getParent()->getParent();
			}
			else
			{
				if(z == z->getParent()->getLeft())
				{
					z = z->getParent();


					RightRotate(z);

				}

				z->getParent()->setColor(BLACK);
				z->getParent()->getParent()->setColor(RED);

				LeftRotate(z->getParent()->getParent());


			}

		}
	}//end of while

	this->root->setColor(BLACK);

}

template <class T, class E>
void RedBlackTree<T,E> :: RBTransplant(node<T,E> * u, node<T,E> *v)
{
	if(u->getParent() == this->nil)
	{

		this->root = v;
	}
	else if(u==u->getParent()->getLeft())
	{
		u->getParent()->setLeft(v);
	}
	else
	{
		u->getParent()->setRight(v);

	}

	//keep eye
	v->setParent(u->getParent());
}

template <class T, class E>
void RedBlackTree<T,E> :: RBDelete(int del)
{

	node<T,E> *z;
	z= Search(this->root,del);


	node<T,E> *y;
	node<T,E> *x;
	Color OGColor;

	y = z;
	OGColor = y->getColor();

	if(z->getLeft() == this->nil)
	{
		x = z->getRight();
		RBTransplant(z,z->getRight());


	}
	else if(z->getRight() == this->nil)
	{
		x = z->getLeft();
		RBTransplant(z, z->getLeft());

	}
	else
	{

		y = minimumVal(z->getRight());

		OGColor = y->getColor();
		x = y->getRight();

		if(y->getParent() == z)
		{
			x->setParent( y);
		}
		else
		{
			RBTransplant(y,y->getRight());
			y->setRight(z->getRight());
			y->getRight()->setParent(y);

		}

		RBTransplant(z, y);

		y->setLeft(z->getLeft());
		y->getLeft()->setParent(y);
		y->setColor(z->getColor());
	}

	if(OGColor == BLACK)
	{
		RBDeleteFixup(x);
	}

	delete z;
}

template <class T, class E>
void RedBlackTree<T,E> ::  RBDeleteFixup(node<T,E> * x)
{
	node<T,E> * w;

	while(x!=this->root && x->getColor() == BLACK)
	{
		if(x==x->getParent()->getLeft())
		{
			w = x->getParent()->getRight();
			if(w->getColor() == RED)
			{
				w->setColor(BLACK);
				x->getParent()->setColor(RED);
				LeftRotate(x->getParent());
				w = x->getParent()->getRight();
			}
			if(w->getLeft()->getColor() == BLACK && w->getRight()->getColor() == BLACK)
			{
				w->setColor(RED);
				x = x->getParent();
			}
			else
			{
				if(w->getRight()->getColor() == BLACK){
					w->getLeft()->setColor(BLACK);
					w->setColor(RED);
					RightRotate(w);
					w = x->getParent()->getRight();
				}

				w->setColor(x->getParent()->getColor());
				x->getParent()->setColor(BLACK);
				w->getRight()->setColor(BLACK);

				LeftRotate(x->getParent());
				x = this->root;
			}


		}

		else
		{
			w = x->getParent()->getLeft();
			if(w->getColor() == RED)
			{
				w->setColor(BLACK);
				x->getParent()->setColor(RED);

				RightRotate(x->getParent());
				w = x->getParent()->getLeft(); //made a change
			}
			if(w->getRight()->getColor() == BLACK && w->getLeft()->getColor() == BLACK)
			{
				w->setColor(RED);
				x = x->getParent();
			}
			else
			{
				if(w->getLeft()->getColor() == BLACK){
					w->getRight()->setColor(BLACK);
					w->setColor(RED);
					LeftRotate(w);
					w = x->getParent()->getLeft();
				}

				w->setColor( x->getParent()->getColor());
				x->getParent()->setColor(BLACK);
				w->getLeft()->setColor(BLACK);

				RightRotate(x->getParent());
				x = this->root;
			}


		}
	}//end of while

	x->setColor(BLACK);
}

template <class T, class E>
node<T,E>* RedBlackTree<T,E> :: minimumVal(node<T,E>*x)
{

	if(this->root->getRight() != this->nil)
	{
		x = this->root->getRight();
	}
	while(x->getLeft() != this->nil)
	{
		x= x->getLeft();
	}
	return x;
}

template <class T, class E>
int RedBlackTree<T,E> ::  maxHeight(node<T,E> *p)
{
	if (p == this->nil) return 0;
	  int leftHeight = maxHeight(p->getLeft());
	  int rightHeight = maxHeight(p->getRight());
	  return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

template <class T, class E>
void RedBlackTree<T,E> ::  Print()
{
	printPretty(4,5,cout);
}

template <class T, class E>
char RedBlackTree<T,E> :: enumToChar(Color color)
{
	return (color == RED? 'R' : 'B');
}


// Print the arm branches (eg, /    \ ) on a line
template <class T, class E>
void RedBlackTree<T,E> ::  printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<node<T,E>*>& nodesQueue, ostream& out) {
	typename deque<node<T,E>*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}

// Print the branches and node (eg, ___10___ )
template <class T, class E>
void RedBlackTree<T,E> ::  printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<node<T,E>*>& nodesQueue, ostream& out) {
	typename deque<node<T,E>*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->getLeft()) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->getKey(),(*iter)->getColor()) : "");
    out << ((*iter && (*iter)->getRight()) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}

// Print the leaves only (just for the bottom row)
template <class T, class E>
void RedBlackTree<T,E> ::  printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<node<T,E>*>& nodesQueue, ostream& out) {
  typename deque<node<T,E>*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->getKey(), (*iter)->getColor()) : "");
  }
  out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
template <class T, class E>
void RedBlackTree<T,E> ::  printPretty( int level, int indentSpace, ostream& out) {

	int h = maxHeight(this->root);

  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)


  deque<node<T,E>*> nodesQueue;
  nodesQueue.push_back(this->root);


  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    for (int i = 0; i < nodesInThisLevel; i++) {
    	node<T,E> *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
	      nodesQueue.push_back(currNode->getLeft());
	      nodesQueue.push_back(currNode->getRight());
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

#endif /* REDBLACKTREE_H_ */
