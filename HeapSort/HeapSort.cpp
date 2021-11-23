#include "HeapSort.h"
#include <vector>
#include <iostream>

using std::endl;
using std::cout;
using std::vector;

int main()
{
	vector<int> ivec{ 7, 2, 8, 9, 3, 1, 5, 6, 20, 11, 18 };
	HeapSort(ivec.begin(), ivec.end());
	for (const int i : ivec)
		cout << i << " ";
	cout << endl;
	return 0;
}

