#include "binary_search_tree.h"

//------------------------------------------------------------------------------'

int main()
{

	BinarySearchTree B = BinarySearchTree();

	B.printBSTInfo();

	Node node1 = Node(15, 0);

	B.insert(&node1);

	B.printBSTInfo();

}

//------------------------------------------------------------------------------
