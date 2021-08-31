//
// Created by Osvaldo Moreno Ornelas on 5/12/16.
//


#include "Huffman.h"
#include <fstream>
//
//Heap<char,int> codeHeap;
////Tree codesTree
////object array table
//
//set<char> charSet;
//int frequencies[128] = {0};

Huffman::Huffman() { }

Huffman::~Huffman() { }


void Huffman::createTable(string convertStr){

//for every char iin the set, increase an instace using the ascii value
	for(char c : convertStr)
	{
		//creates set of unique character values
		charSet.insert (c);

		//create a parallel array of frequencies
		frequencies[c]++;
	}
}

void Huffman::createHeap(){

	BinaryTree * rootTree;


	for(char c : charSet){

		rootTree = new BinaryTree(c,frequencies[c]);

		codeHeap.Insert(rootTree);

	}


}

void Huffman::outputFrequenceAndChar()
{

	//initialize the frequencies from char set
	//char set allows to have unique characters in the table.
	for(char c : charSet)
	{
		cout << endl << c << endl;
		cout << frequencies[c] << endl;
	}

}

//make the binary tree by following the algorithm in the Data Structures
//book.
BinaryTree * Huffman::createTree(){


	//right
	BinaryTree *tree1;

	//left
	BinaryTree *tree2;

	//root
	BinaryTree *tree3;

	//while there is 1 in the heap
while(codeHeap.Size() > 1)
{

//cout << endl << codeHeap.Size() << endl;

	//min
	tree1 = codeHeap.MinElement();
	codeHeap.removeMin ();


	//second min
	tree2 = codeHeap.MinElement ();
	codeHeap.removeMin ();

tree3 = new BinaryTree();


	tree3->setValue (tree1->getValue()+tree2->getValue ());
	tree3->setLeft (tree1->getRoot());

	tree3->setRight (tree2->getRoot());


	//insert new tree
	codeHeap.Insert(tree3);
}


BinaryTree *returnTree;

returnTree = codeHeap.MinElement();
codeHeap.removeMin();

//return tree with the codes
return returnTree;

}

//this encodes the characters to a huffman code
void Huffman::encode(BinaryTree* codeTree,string decodeStr, string fileName){

	//void char that will get chat with code
string str  = "";

ofstream oFile;
oFile.open(fileName.c_str());

ostringstream out;

//for very character in the string
for(char c : decodeStr)
{

	//get the code for that character
	codeTree->huf(codeTree->getRoot(), c, "", str );

	//save codes
	out << str.c_str();
}


cout << endl << "Huffman coded: " << endl;
cout << out.str().length();

oFile<< out.str();

oFile.close();

}

//decode the huffman code
string Huffman::decode(BinaryTree * myTree, string FileName){

	ostringstream out;
	stringstream outCode;


	//open file with the codes
	ifstream inFile;

	cout << endl << FileName << endl;

	inFile.open(FileName.c_str());

	string decodedStr;

	//get codes from file
	inFile >> decodedStr;

	string showStr = "";


	//get the root of the huffman tree
	Node * myNode = myTree->getRoot();
ofstream outFile;
	outFile.open("AddressCodes.txt");

	//for every character in the coded string
	for(char c : decodedStr)
	{
		showStr += c;

		outFile << showStr;

		//cout << showStr;

		//if is the bottom of the tree
		if(myNode->leftLink == NULL && myNode->rightLink == NULL)
		{

			//put that character in the return string
			out << myNode->info;
			myNode = myTree->getRoot();
		}

		//if the value is 0
		if(c == '0')
		{

			//go left
			myNode = myNode->leftLink;
		}
		else if(c == '1')
		{
			//if 1, go right
			myNode = myNode->rightLink;
		}
	}

	out << myNode->info;




	//outFile << outCode.str();

	outFile.close();
	inFile.close();

	return out.str();

}

//otput the sequences
string Huffman::outputTable(BinaryTree* codeTree, int &compressedRatio)
{

	ostringstream out;
//int compressedRatio;

	string str = "";

	out << left;
	out << setw(15)<< "Character"  << setw(15) << "Frequence" << "Huffman Code" << endl;
	out << "-------------------------------------------" << endl;


	for(char c : charSet)
	{
		codeTree->huf(codeTree->getRoot(), c, "", str );
		compressedRatio += (str.length()*frequencies[c]);


		out << c << " has frequence of " << setw(5) << frequencies[c] << " with the huffman code:  " << str << endl;

	}

	return out.str();
}
