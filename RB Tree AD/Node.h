/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  4/11/16
 *****************************************************/

#ifndef NODE_H_
#define NODE_H_

#include <iostream>

enum Color
{
	BLACK,
	RED
};

//this class has the node for a Red-Black Tree. The nodes contains 2
//templates that in this case store a key and a string value.

template <class T, class E>
class node
{
public:

	//constructor
	node();


	//mutating methods
	void setLeft(node<T,E> * leftPtr);
	void setRight(node<T,E> * rightPtr);
	void setParent(node<T,E> * parentPtr);
	void setColor(Color newColor);
	void setKey(T newK);
	void setData(E newData);

	//accessing methods
	node<T,E> * getRight() const;
	node<T,E> * getLeft()const;
	node<T,E> * getParent()const;

	Color getColor()const;
	T getKey()const;

	E getData() const;

private:

	//class attributes

	node<T,E> * parent;
	node<T,E> * left;
	node<T,E> * right;
	Color color;
	T key;
	E data;
};

//default constructor
template <class T, class E>
node<T,E>::node()
{
	this->parent = NULL;
	this->left   = NULL;
	this->right  = NULL;

	this->color = RED;
	this->key   = 0;
	this->data  = " ";
}

//set left node
template <class T, class E>
void node<T,E>:: setLeft(node<T,E> * leftPtr)
{
	this->left = leftPtr;
}

//set right node
template <class T, class E>
void node<T,E>::  setRight(node<T,E> * rightPtr)
{
	this->right = rightPtr;
}

//set parent node
template <class T, class E>
void node<T,E>::  setParent(node<T,E> * parentPtr)
{
	this->parent = parentPtr;
}


//set node color
template <class T, class E>
void node<T,E>::  setColor(Color newColor)
{
	this->color = newColor;
}

//set key
template <class T, class E>
void node<T,E>::  setKey(T newK)
{
	this->key = newK;
}

//set data
template <class T, class E>
void node<T,E>:: setData(E newData)
{
	data = newData;
}

//get right node
template <class T, class E>
node<T,E> *  node<T,E>:: getRight()const
{
return this->right;
}

//get left node
template <class T, class E>
node<T,E> *  node<T,E>:: getLeft()const
{

return this->left;
}

//get parent node
template <class T, class E>
node<T,E> *  node<T,E>:: getParent()const
{
	return this->parent;
}

//get color
template <class T, class E>
Color  node<T,E>:: getColor()const
{
	return this->color;
}

//get key
template <class T, class E>
T  node<T,E>:: getKey()const
{
	return this->key;
}

//get data
template <class T, class E>
E node<T,E>:: getData() const
{
	return data;

}



#endif /* NODE_H_ */
