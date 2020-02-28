#include <iostream>
#include <vector>
#include <algorithm>
#include "bigonotation.cpp"

using namespace std;


int main() {
	vector<int>vec{1,2,3,4,5,6,7,8,9};
	binary_search(vec, 4);
	return 0;
}