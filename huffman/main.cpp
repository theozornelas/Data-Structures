//#include <iostream>
//#include <set>
//using namespace std;

#include "Huffman.h"
#include <fstream>
#include "Functions.h"

int main() {

string outFileName = "code.txt";

string convertStr = "Four score and seven years ago our fathers brought forth on this \n"
					"continent, a new nation, conceived in Liberty, and dedicated to the \n"
					"proposition that all men are created equal.\n\n"
					"Now we are engaged in a great civil war, testing whether that nation, or any\n"
					"nation so conceived and so dedicated, can long endure. We are met on a\n"
					"great battle-field of that war. We have come to dedicate a portion of that\n"
					"field, as a final resting place for those who here gave their lives that that\n"
					"nation might live. It is altogether fitting and proper that we should do this.\n\n"
					"But, in a larger sense, we cannot dedicate -- we cannot consecrate -- we\n"
					"cannot hallow -- this ground. The brave men, living and dead, who\n"
					"struggled here, have consecrated it, far above our poor power to add or\n"
					"detract. The world will little note, nor long remember what we say here, but\n"
					"it can never forget what they did here. It is for us the living, rather, to be\n"
					"dedicated here to the unfinished work which they who fought here have\n"
					"thus far so nobly advanced. It is rather for us to be here dedicated to the\n"
					"great task remaining before us -- that from these honored dead we take\n"
					"increased devotion to that cause for which they gave the last full measure\n"
					"of devotion -- that we here highly resolve that these dead shall not have\n"
					"died in vain -- that this nation, under God, shall have a new birth of freedom\n"
					"-- and that government of the people, by the people, for the people, shall\n"
					"not perish from the earth.";

//string convertStr = "--I love\n Computer Science ";

BinaryTree *mainTree;

    Huffman myTree;

    int uncompressedRatio  = convertStr.length() * 8;


	myTree.createTable (convertStr);


	myTree.createHeap ();


	mainTree = myTree.createTree ();

//mainTree->InOrderTraversal();

//myTree.outputFrequenceAndChar();

	myTree.encode(mainTree, convertStr, outFileName);

	int compressedRatio;

	ofstream treeFile;

	treeFile.open("tree.txt");



	printPretty(mainTree->getRoot(), 4, 4, treeFile);

	treeFile.close();

	cout << endl << myTree.outputTable(mainTree, compressedRatio) << endl;

	string decodedString;

	decodedString= myTree.decode(mainTree, outFileName);


	ofstream newFile;

	newFile.open("Adress.txt");

	newFile << decodedString;

	float ratio = ( float(compressedRatio)/uncompressedRatio)*100;


	cout << endl << "Ratio: " << ratio << endl;

	newFile.close();


    return 0;
}
