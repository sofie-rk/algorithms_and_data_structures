
#include <iostream>

using namespace std;

int countGhosts() {

	int counter = 0;

	// First line is the size of the grid
	int N;
	cin >> N;

	// Read N lines
	for (int i=0; i<N+1; i++) {
		string line;
		getline(cin, line);
		
		for (unsigned int j=0; j<line.length(); j++) {
			if (line.at(j) == 'G') {
				counter++;
			}
		}
	}


	return counter;

}

//------------------------------------------------------------------------------'

int main()
{
	cout << countGhosts();

}

//------------------------------------------------------------------------------
