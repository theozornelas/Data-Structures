/*
 * BTree.h
 *
 *  Created on: May 13, 2016
 *      Author: omorenoornelas0
 */

#ifndef BTREE_H_
#define BTREE_H_

#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#pragma once
#include <math.h>
#include <vector>
#include <queue>

//enumerated type for the type of iteration of the tree
enum printType
{
	IN_ORDER,
	PRE_ORDER,
	POST_ORDER
};

//templated node struct
 struct Node{
        char info;
        int  value;
        Node *leftLink;
        Node *rightLink;
        Node(){leftLink = NULL; rightLink = NULL; value = 0;}
    };

//father tree class it has the methods needed to traverse and print the list
class BinaryTree{
public:
	//constructor
    BinaryTree();

    BinaryTree(char newInfo, int newVal);

    BinaryTree (const BinaryTree& otherTree);

    void copyTree
    (Node* &copiedTreeRoot,
    Node* otherTreeRoot);

    //destructor
    ~BinaryTree();

    bool IsEmpty();

    void InOrderTraversal();

    void PreOrderTraversal();

    void PostOrderTraversal();

    int TreeHeight();

    int ThreeNodeCount();

    int ThreeLeavesCount();

    void DestroyTree();

    string Print(printType method);

    void DrawTree();
    char getInfo();

    int getValue();

    void setInfo(char newInfo);

    void setValue(int newValue);

    void setLeft(Node* newLeft);
    void setRight(Node* newRight);

    Node * getRoot();

    void huf(Node * myNode, unsigned char c, string str, string &str2) const;

    void huffmanList(Node * myNode, string str) const;

    void print(ostream &, Node *, int) const; //prints the tree
    void print(Node *, int) const; //prints the tree

    string print_char(Node *) const; //prints chars

protected :

    //tree root
     Node *root;


private:

    //in order traversal
    void inorder(Node *p);

    //pre order traversal
    void preorder(Node *p);

    //post order traversal
    void postorder(Node *p);

    //height of the tree
    int height(Node *p);

    int max(int x, int y);

    int nodecount(Node *p);

    int leavesCount(Node *p);

    void destroy(Node* &p);


    int DrawTreePrivate(Node *tree, int is_left, int offset, int depth, char s[20][255]);

};

int maxHeight(BinaryTree *p);

string intToString(int val, char info);

void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out);

void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out);

void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out);

void printPretty(Node *root, int level, int indentSpace, ostream& out);



#endif /* BTREE_H_ */
