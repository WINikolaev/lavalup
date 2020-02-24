#include <iostream>

using namespace std;

// CPP 17

typedef struct {
	auto val() const -> int {return m_;}
	auto& cref() {return m_;}

	auto val2(bool f) const -> double {
		if (f) {
			return 0.4;
		} else {
			return 148;
		}
	}
	
	int m_;
}foo;


int main() {
	foo str0;
	str0.m_ = 1000;

	cout << "test1: " << str0.val() << endl;
	cout << "test2: " << str0.cref() << endl;
	(str0.cref()) = 2000;
	cout << "test1: " << str0.val() << endl;


	cout << "test3: " << str0.val2(1) << endl;
	cout << "test4: " << str0.val2(0) << endl;

	auto test = foo{};
	test.m_ = 2001;
	cout << "test1: " << str0.val() << endl;
	return 0;
}