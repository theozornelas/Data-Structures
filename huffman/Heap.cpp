/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  3/07/16
 *****************************************************/


#include "Heap.h"
#include <sstream>
//initializes attributes of the heap
//Heap :: Heap()
//{
//	size = 0;
//	root = 1;
//	myTree.push_back(0);
//	compares = 0;
//
//}
//
////destroys the heap
//Heap :: ~Heap()
//{
//	myTree.clear();
//}
//
//int Heap ::  Size()
//{
//	return myTree.size()-1;
//}
//
////checks if the heap is empty
//bool Heap ::  IsEmpty()
//{
//	return myTree.empty();
//}
//
////this insertion uses the bubble up method to arrange the contents in the heap.
//void Heap :: Insert(int newTeam)
//{
//	//insert in the heap
//	myTree.push_back(newTeam);
//
//	//increment the size
//	size++;
//
//	compares++;
//
//	//arrange values by bubbling up
//	BubbleUp(size);
//
//}
//
//int Heap :: MinElement()
//{
//	//return the root of the heap(smallest element)
//	compares++;
//	return myTree[root];
//}
//
//void Heap :: removeMin()
//{
//	//last is now the first
//	myTree[root] = myTree.at(size);
//
//	//pop the last
//	myTree.pop_back();
//
//	//decrease the size of the heap
//	size--;
//	if(size>0)
//	{
//		//rearange the heap
//		BubbleDown(root);
//	}
//
//	compares++;
//
//}
//
//int Heap :: Left(int index)
//{
//	compares++;
//	return myTree[index *2];
//
//}
//
//int Heap :: Right(int index)
//{
//	compares++;
//	return myTree[(index *2) + 1];
//}
//
////this method arranges the heap after an insertion. It searches the
////appropiate spot and and swaps in order to keep order.
//void Heap :: BubbleUp(int index)
//{
//
//	compares++;
//	//swap(index1 , index2/2)//depends if swapping from left or right
//	if(index > 0)
//	{
//		//get the index of the parent
//		int parentIndex = ParentIndex(index);
//
//		//if the parent is bigger than the child at the index passed
//		if(myTree[parentIndex]> myTree[index])
//		{
//			//swap them
//			Swap(parentIndex,index);
//
//			//repeat by recursevely calling the function at the parent
//			BubbleUp(parentIndex);
//		}
//	}
//}
//
////this method swaps the last with the root and pops it, then rearanges the
////heap in order to maintain its property.
//void Heap :: BubbleDown(int index)
//{
//	compares++;
//	int leftIndex;
//	int rightIndex;
//	int minIndex;
//
//	//get index of left child
//	leftIndex = LeftPosition(index);
//
//	//get index of right child
//	rightIndex = RightPosition(index);
//
//	//if the index is bigger than the size
//	if(rightIndex >= size)
//	{
//		//end the function
//		if(leftIndex >= size)
//		{
//			return;
//		}
//		else
//		{
//			//the lowest index is the left index
//			minIndex = leftIndex;
//		}
//
//	}else{
//
//		//if the left is less than equal to the right
//		if(myTree[leftIndex] <= myTree[rightIndex])
//		{
//			//lowest is the left
//			minIndex = leftIndex;
//		}
//		else
//		{
//			//lowest is the right
//			minIndex = rightIndex;
//		}
//	}
//
//	//if the index is greater than the minimum index
//	if(myTree[index] > myTree[minIndex])
//	{
//		//swap objects and use recursion for upper levels
//		Swap(minIndex,index);
//		BubbleDown(minIndex);
//	}
//
//}
//
////swaps a and b of spot
//void Heap ::  Swap(int a, int b)
//{
//	int temp;
//	compares++;
//	temp = myTree[a];
//	myTree[a] = myTree[b];
//	myTree[b] = temp;
//
//
//}
////returns the parent of that index
//int  Heap :: ParentIndex(int index)
//{
//	compares++;
//	return (index)/2;
//}
//
//int  Heap :: LeftPosition(int index)
//{
//	compares++;
//	return index*2;
//}
//
//int  Heap :: RightPosition(int index)
//{
//	compares++;
//	return (index*2) + 1;
//}
//
////prints the heap
//string Heap :: Print()
//{
//
//	ostringstream out;
//	int count = 1;
//
//
//	return out.str();
//}
//
//unsigned long Heap :: getCompas()
//{
//	return compares;
//}
//
//
////this functions sorts the heap in such form that it copies the value at the
////root of the heap into the array.
//void HeapSort(int teamAr[],const int AR_SIZE ,Heap &myHeap, unsigned long &counter)
//{
//
//	int index = 0;
//
////cout << InstructionHeader("INSERTING VALUES INTO THE HEAP") << endl;
//
////inserting the values into the heap
//	for(int i =0; i<AR_SIZE; i++)
//	{
//
//
//		myHeap.Insert(teamAr[i]);
//	}
//
//
////	cout << InstructionHeader("INSERTING VALUES FROM HEAP TO ARRAY" ) << endl;
//
//	//popping items and adding to the array
//	while(index < AR_SIZE && !myHeap.IsEmpty())
//	{
//		teamAr[index] = myHeap.MinElement();
//		myHeap.removeMin();
//		index++;
//
//
//	}
//
//	counter += myHeap.getCompas();
//
//}

