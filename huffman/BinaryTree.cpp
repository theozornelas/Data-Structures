/*
 * BinaryTree.cpp
 *
 *  Created on: May 13, 2016
 *      Author: omorenoornelas0
 */
#include "BTree.h"
#define width_unit 5


BinaryTree::BinaryTree()
{
    root = new Node();
}

BinaryTree::BinaryTree(char newInfo, int newVal)
{
	root = new Node();
    root->info = newInfo;
    root->value = newVal;

}


BinaryTree::BinaryTree (const BinaryTree& otherTree)
{
	if (otherTree.root == NULL) //otherTree is empty
	root = NULL;
	else
	copyTree(root, otherTree.root);
}

void BinaryTree::copyTree
(Node* &copiedTreeRoot,
Node* otherTreeRoot)
{
if (otherTreeRoot == NULL)
copiedTreeRoot = NULL;
else
{
copiedTreeRoot = new Node();
copiedTreeRoot->info = otherTreeRoot->info;
copyTree(copiedTreeRoot->leftLink, otherTreeRoot->leftLink);
copyTree(copiedTreeRoot->rightLink, otherTreeRoot->rightLink);
}
} //en



BinaryTree:: ~BinaryTree(){}


void BinaryTree:: huf(Node * myNode, unsigned char c, string str, string &str2) const
{
	if(myNode != NULL)
	{
		if(!myNode->leftLink && !myNode->rightLink && myNode->info == c){
			str2 = str;
		}
		else
		{
			huf(myNode->leftLink,c,str+"0",str2);
			huf(myNode->rightLink,c,str+"1",str2);
		}
	}
}

void BinaryTree:: huffmanList(Node * myNode, string str) const
{
	if(myNode != NULL)
	{
		if(!myNode->leftLink && !myNode->rightLink)
		{
			cout << print_char(myNode);
		}
		else
		{
			huffmanList(myNode->leftLink, str+"0");
			huffmanList(myNode->rightLink, str+"1");
		}
	}
}


bool BinaryTree:: IsEmpty()
{
    return root == NULL;
}

char BinaryTree:: getInfo()
{
    return root->info;
}

int BinaryTree:: getValue()
{
return root->value;
}


void BinaryTree:: setInfo(char newInfo){

    root->info = newInfo;

}

void BinaryTree:: setValue(int newValue){


    root->value = newValue;

}


void BinaryTree:: setLeft(Node* newLeft){

    root->leftLink = newLeft;

}
void BinaryTree:: setRight(Node* newRight){
    root->rightLink = newRight;
}

Node * BinaryTree:: getRoot(){
    return root;
}

void BinaryTree:: InOrderTraversal()
{
    inorder(root);
}


void BinaryTree :: PreOrderTraversal()
{
    preorder(root);
}

void BinaryTree::  PostOrderTraversal()
{
    preorder(root);
}

int BinaryTree:: TreeHeight()
{
    return height(root);
}

int BinaryTree:: ThreeNodeCount()
{
    return nodecount(root);
}

int BinaryTree:: ThreeLeavesCount()
{
    return leavesCount(root);
}

void BinaryTree ::  DestroyTree()
{
    destroy(root);
}


void BinaryTree::  inorder(Node*p)
{
    if(p!=NULL)
    {
        inorder(p->leftLink);
        cout << p->info << " " << p->value;
        inorder(p->rightLink);
    }

}


void BinaryTree::  preorder(Node *p)
{
    if(p!=NULL)
    {
        cout << p->info << " ";
        preorder(p->leftLink);
        preorder(p->rightLink);

    }

}

void BinaryTree::  postorder(Node *p)
{
    if(p!=NULL)
    {
        postorder(p->leftLink);
        postorder(p->rightLink);
        cout << p->info << " ";

    }

}

int BinaryTree:: height(Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        return 1+max(height(p->leftLink),height(p->rightLink));
    }

}


int BinaryTree:: max(int x, int y)
{
    if(x>=y)
    {
        return x;
    }
    else
    {
        return y;
    }

}


int BinaryTree :: nodecount(Node*p)
{
    int nodeCounter = 0;
    if(p!=NULL)
    {
        if(p->leftLink != NULL || p->rightLink!= NULL)
        {
            nodeCounter++;
        }

    }
    return nodeCounter;
}

int BinaryTree :: leavesCount(Node *p)
{
    int leafCounter = 0;
    if(p!=NULL)
    {
        if(p->rightLink == NULL && p->leftLink==NULL)
        {

            leafCounter++;
        }

    }

    return leafCounter;
}

void BinaryTree :: destroy(Node* &p)
{
    if(p!=NULL)
    {
        destroy(p->leftLink);
        destroy(p->rightLink);
        delete p;
        p = NULL;
    }

}

string BinaryTree :: Print(printType method)
{
    ostringstream out;

    switch(method)
    {
    case IN_ORDER: InOrderTraversal();
    	break;
    case PRE_ORDER:  PreOrderTraversal();
    	break;
    case POST_ORDER: PostOrderTraversal();
    	break;
    }
    return out.str();

}


void BinaryTree::DrawTree() {
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%20s", " ");

    DrawTreePrivate(root, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

//the recursive tree output (w/ respect to its graph) fn.
void BinaryTree::print(ostream & ost, Node * curr, int level) const
{
    if(curr) //if the current node is not null then
    {
        print(ost,curr->rightLink,level+1); //try to go to right node
        //output the node data w/ respect to its level
        ost<<setw(level*width_unit)<<print_char(curr)<<":"
           <<curr->value<<endl;
        print(ost,curr->leftLink,level+1); //try to go to left node
    }
}

//the recursive tree print (w/ respect to its graph) fn.
void BinaryTree::print(Node * curr, int level) const
{
    if(curr) //if the current node is not null then
    {
        print(curr->rightLink,level+1); //try to go to right node
        //print the node data w/ respect to its level
        cout<<setw(level*width_unit)<<print_char(curr)<<":"
            <<curr->value<<endl;
        print(curr->leftLink,level+1); //try to go to left node
    }
}

string BinaryTree::print_char(Node * N) const
{
    string s="";

    if(!N->leftLink && !N->rightLink) //if it is a leaf node
    {
        unsigned char c=N->info;

        //if the char is not printable then output its octal ASCII code
        if(iscntrl(c) || c==32) //32:blank char
        {
            //calculate the octal code of the char (3 digits)
            char* cp=new char;
            for(int i=0;i<3;++i)
            {
                sprintf(cp,"%i",c%8);
                c-=c%8;
                c/=8;
                s=(*cp)+s;
            }
            s='/'+s; // adds \ in front of the octal code
        }
        else
            s=c;
    }
    return s;
}

int BinaryTree :: DrawTreePrivate(Node *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%01d)", tree->info);

    int left  = DrawTreePrivate(tree->leftLink,  1, offset,                depth + 1, s);
    int right = DrawTreePrivate(tree->rightLink, 0, offset + left + width, depth + 1, s);

//#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
//#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
//#endif

    return left + width + right;
}

// Print the arm branches (eg, /    \ ) on a line
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {

	deque<Node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}

// Find the maximum height of the binary tree
int maxHeight(Node *p) {
  if (!p) return 0;
  int leftHeight = maxHeight(p->leftLink);
  int rightHeight = maxHeight(p->rightLink);
  return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

// Convert an integer value to string
string intToString(int val, char info) {
  ostringstream ss;
  ss << val;
  //ss << ',';
  ss << info;
  return ss.str();
}

// Print the branches and node (eg, ___10___ )
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
  deque<Node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->leftLink) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->value, (*iter)->info) : "");
    out << ((*iter && (*iter)->rightLink) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}

// Print the leaves only (just for the bottom row)
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
  deque<Node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->value, (*iter)->info) : "");
  }
  out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
void printPretty(Node *root, int level, int indentSpace, ostream& out) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

  deque<Node*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    for (int i = 0; i < nodesInThisLevel; i++) {
    	Node *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
       nodesQueue.push_back(currNode->leftLink);
       nodesQueue.push_back(currNode->rightLink);
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
