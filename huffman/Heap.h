/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  3/07/16
 *****************************************************/

#ifndef HEAP_H_
#define HEAP_H_

#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

#include "BTree.h"


/**************************************************************************
 * This is the Heap Class. It implements a heap by using a vector of type
 * Team(class). The heap is used to sort a certain number of Items. The
 * Vector accommodates the data [x][R][L][R][LL][LR][RL][RR]....
 * The Heap will store the smallest number at the top.
 *************************************************************************/

template <typename E, typename V>
class Heap
{
public:

	//constructor
	Heap();

	//destructor
	~Heap();

	//size of the vector heap
	 int Size();

	//if the vector is empty
	bool IsEmpty();


	//inserts in to the heap. Bubbles up is necessary.
	void Insert(BinaryTree *newTree);


	//returns the last element in the list
	BinaryTree* MinElement();


	//removes the last element in the heap
	void removeMin();

	//left child team
	BinaryTree* Left(int index);


	//reight child team
	BinaryTree* Right(int index);

	//index of the parent
	int ParentIndex(int index);


	//bubble up the element if is less than the parent(used in insert)
	void BubbleUp(int index);

	//bubble down the element if is less than the parent(used in delete)
	void BubbleDown(int index);


	//swaps the elements in the heap(used in bubble down and bubble up)
	void Swap(int a, int b);

	//index of the left child
	int LeftPosition(int index);

	//index of the right child
	int RightPosition(int index);

    bool Find(E findCargo);
	//prints the heap
	string Print();

	unsigned long getCompas();

private:

	vector<BinaryTree*> myTree;  //container for the heap
	int size;//size/tail of the heap
	int root;//index of the root(always 1)

	unsigned long compares;

};

template <typename E, typename V>
Heap<E,V> :: Heap()
{
	size = 0;
	root = 1;

	BinaryTree *temp = new BinaryTree();
	myTree.push_back(temp);
	compares = 0;

}

//destroys the heap
template <typename E, typename V>
Heap<E,V> :: ~Heap()
{
	myTree.clear();
}


template <typename E, typename V>
bool Heap<E,V>::Find(E findCargo)
{
    // InputIterator find (InputIterator first, InputIterator last, const T& val);

    typename vector<BinaryTree>::iterator it;
   // it = myTree.begin();
    bool found = false;
    int counter = 0;

//    for(it = myTree.begin();  it!=myTree.end(); it++)
//    {
//        if((*it).getInfo() == findCargo)
//        {
//            found = true;
//        }
//    }

    return found;
};

template <typename E, typename V>
int Heap<E,V> ::  Size()
{
	return myTree.size()-1;
}

//checks if the heap is empty
template <typename E, typename V>
bool Heap<E,V> ::  IsEmpty()
{
	return myTree.empty();
}

//this insertion uses the bubble up method to arrange the contents in the heap.
template <typename E, typename V>
void Heap<E,V> :: Insert(BinaryTree *newTree)
{
	//insert in the heap

	//BinaryTree *addTree = newTree;

	myTree.push_back(newTree);

	//increment the size
	size++;

	compares++;

	//arrange values by bubbling up
	BubbleUp(size);

}

template <typename E, typename V>
BinaryTree* Heap<E,V> :: MinElement()
{
	//return the root of the heap(smallest element)
	compares++;
	return myTree[root];
}

template <typename E, typename V>
void Heap<E,V> :: removeMin()
{
	//last is now the first
	myTree[root] = myTree.at(size);

	//pop the last
	myTree.pop_back();

	//decrease the size of the heap
	size--;
	if(size>0)
	{
		//rearange the heap
		BubbleDown(root);
	}

	compares++;

}

template <typename E, typename V>
BinaryTree* Heap<E,V> :: Left(int index)
{
	compares++;
	return myTree[index *2];

}

template <typename E, typename V>
BinaryTree* Heap<E,V> :: Right(int index)
{
	compares++;
	return myTree[(index *2) + 1];
}

//this method arranges the heap after an insertion. It searches the
//appropiate spot and and swaps in order to keep order.
template <typename E, typename V>
void Heap<E,V> :: BubbleUp(int index)
{

	compares++;
	//swap(index1 , index2/2)//depends if swapping from left or right
	if(index > 0)
	{
		//get the index of the parent
		int parentIndex = ParentIndex(index);

		//if the parent is bigger than the child at the index passed
		if(myTree[parentIndex]->getValue()> myTree[index]->getValue())
		{
			//swap them
			Swap(parentIndex,index);

			//repeat by recursevely calling the function at the parent
			BubbleUp(parentIndex);
		}
	}
}

//this method swaps the last with the root and pops it, then rearanges the
//heap in order to maintain its property.
template <typename E, typename V>
void Heap<E,V> :: BubbleDown(int index)
{
	compares++;
	int leftIndex;
	int rightIndex;
	int minIndex;

	//get index of left child
	leftIndex = LeftPosition(index);

	//get index of right child
	rightIndex = RightPosition(index);

	//if the index is bigger than the size
	if(rightIndex >= size)
	{
		//end the function
		if(leftIndex >= size)
		{
			return;
		}
		else
		{
			//the lowest index is the left index
			minIndex = leftIndex;
		}

	}else{

		//if the left is less than equal to the right
		if(myTree[leftIndex]->getValue() <= myTree[rightIndex]->getValue())
		{
			//lowest is the left
			minIndex = leftIndex;
		}
		else
		{
			//lowest is the right
			minIndex = rightIndex;
		}
	}

	//if the index is greater than the minimum index
	if(myTree[index]->getValue() > myTree[minIndex]->getValue())
	{
		//swap objects and use recursion for upper levels
		Swap(minIndex,index);
		BubbleDown(minIndex);
	}

}

//swaps a and b of spot
template <typename E, typename V>
void Heap<E,V> ::  Swap(int a, int b)
{
	BinaryTree* temp;
	compares++;
	temp = myTree[a];
	myTree[a] = myTree[b];
	myTree[b] = temp;


}
//returns the parent of that index
template <typename E, typename V>
int  Heap<E,V> :: ParentIndex(int index)
{
	compares++;
	return (index)/2;
}
template <typename E, typename V>
int  Heap<E,V> :: LeftPosition(int index)
{
	compares++;
	return index*2;
}
template <typename E, typename V>
int  Heap<E,V> :: RightPosition(int index)
{
	compares++;
	return (index*2) + 1;
}

//prints the heap
template <typename E, typename V>
string Heap<E,V> :: Print()
{

	ostringstream out;
	int count = 1;


	return out.str();
}

template <typename E, typename V>
unsigned long Heap<E,V> :: getCompas()
{
	return compares;
}


#endif /* HEAP_H_ */
