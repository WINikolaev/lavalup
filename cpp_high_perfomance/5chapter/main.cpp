#include <iostream>
#include <vector>
#include <algorithm>
#include "bigonotation.cpp"

using namespace std;

class IntIterator {
public:
	IntIterator(int v) : v_{v} {}
	auto operator==(const IntIterator& it)const{ return v_ == it.v_; }
	auto operator!=(const IntIterator& it)const{ return !(*this==it); }
	auto& operator*() const { return v_; }
	auto& operator++() { ++v_; return *this; }
	auto& operator++(int v) {
		IntIterator temprorary(v);
		++(*this);
		return temprorary;
	}
private:
	int v_{};
};

int main() {
	auto first = IntIterator(12);
	auto last = IntIterator{16};
	for (auto it = first; it != last; it++) {
		cout << (*it) << " ";
	}
	
	return 0;
}