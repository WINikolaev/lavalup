#include <iostream>
#include <vector>
#include <algorithm>
#include "bigonotation.cpp"

using namespace std;


int main() {
	vector<int>vec{1,2,3,4,5,6,7,8,9};
	binary_search(vec, 4);

	int Size = 5;

	const auto numBlocks = Size * Size;
	const auto BlockSpacing = 300.f;

	for (size_t BlockIndex = 0; BlockIndex < numBlocks; BlockIndex++)
	{
		const float XOffset = (BlockIndex%Size) * BlockSpacing; // Divide by dimension
		const float YOffset = (BlockIndex/Size) * BlockSpacing; // Modulo gives remainder
		if (!XOffset && YOffset) { cout << endl;}
		
		cout << YOffset << "," << XOffset << "			";
		//cout << "XOffset: " << XOffset << "; YOffset: " << YOffset << endl;
		//cout << "####################################" << endl;
	}
	
	return 0;
}