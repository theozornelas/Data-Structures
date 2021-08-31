/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  4/11/16
 *****************************************************/
#include "RedBlackTree.h"

int main(){

	PrintHeader(cout, "Red Black Tree Implementation", "Osvaldo Moreno Ornelas", 'A',11);

	RedBlackTree<int, string>  myTree;

	myTree.Insert(18, "Laguna Niguel");
	myTree.Print();
	myTree.Insert(41, "Mission Viejo");
	myTree.Print();
	myTree.Insert(22, "Lake Forest");
	myTree.Print();
	myTree.Insert(44, "Irvine");
	myTree.Print();

	myTree.Delete(18);
	myTree.Print();

	myTree.Insert(59, "San Clemente");
	myTree.Print();
	myTree.Insert(32, "San Diego");
	myTree.Print();
	myTree.Insert(49, "Anaheim");
	myTree.Print();

	myTree.Delete(22);
	myTree.Print();

	myTree.Insert(73, "Los Angeles");
	myTree.Print();
	myTree.Insert(44, "Laguna Niguel");
	myTree.Print();
	myTree.Insert(17, "Orange");
	myTree.Print();
	myTree.Insert(77, "Palm Springs");
	myTree.Print();
	myTree.Insert(26, "Riverside");
	myTree.Print();

	myTree.Delete(73);
	myTree.Print();

	myTree.Insert(19, "Brea");
	myTree.Print();
	myTree.Insert(60, "Santa Ana");
	myTree.Print();
	myTree.Insert(35, "Tustin");
	myTree.Print();
	myTree.Insert(52, "Oceanside");
	myTree.Print();
	myTree.Insert(11, "La Jolla");
	myTree.Print();
	myTree.Insert(18, "Del Mar");
	myTree.Print();
	myTree.Insert(22, "Aliso Viejo");
	myTree.Print();
	myTree.Insert(49, "Laguna Beach");
	myTree.Print();

	myTree.Delete(41);
	myTree.Print();

	myTree.Insert(11, "Laguna Beach");
	myTree.Print();
	myTree.Insert(42, "Vista");
	myTree.Print();
	myTree.Insert(49, "San Diego");
	myTree.Print();
	myTree.Insert(99, "San Juan");
	myTree.Print();
	myTree.Insert(29, "Dana Point");
	myTree.Print();
	myTree.Insert(32, "Mission Viejo");
	myTree.Print();

	return 0;
}
