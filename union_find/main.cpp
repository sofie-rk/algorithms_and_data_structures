
#include "quick_find.h"

#include <iostream>
using namespace std;

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	QuickFind q = QuickFind(7);
	q.printIdArray();

	q.unionFunc(3,4);
	q.printIdArray();

	q.unionFunc(5,0);
	q.printIdArray();

	q.unionFunc(4,5);
	q.printIdArray();

	q.unionFunc(4,3);
	q.printIdArray();

	q.unionFunc(0,1);
	q.printIdArray();

	q.unionFunc(2,6);
	q.printIdArray();

	q.unionFunc(0,4);
	q.printIdArray();

	q.unionFunc(6,0);
	q.printIdArray();

	
	

}

//------------------------------------------------------------------------------
