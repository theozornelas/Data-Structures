//
// Created by omorenoornelas0 on 5/10/2016.
//

#ifndef HUFFMANCODES_HUFFMAN_H
#define HUFFMANCODES_HUFFMAN_H

#include "Heap.h"
//#include <string>
#include <set>
//using namespace std;

class Huffman
{

public:
    Huffman();
    ~Huffman();


    void createTable(string convertStr);

    void createHeap();

    BinaryTree * createTree();

    void encode(BinaryTree* codeTree, string decodeStr, string fileName);

    string decode(BinaryTree * myTree, string FileName);

    void outputFrequenceAndChar();

    string outputTable(BinaryTree* codeTree, int &compressedRatio);


private:

    Heap<BinaryTree,int> codeHeap;
    //Tree codesTree
    //object array table

	set<char> charSet;
	int frequencies[128] = {0};

};



#endif //HUFFMANCODES_HUFFMAN_H
