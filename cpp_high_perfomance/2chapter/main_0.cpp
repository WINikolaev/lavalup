#include <iostream>
#include <vector>
#include <algorithm>
#include "lambda.cpp"

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
	// foo str0;
	// str0.m_ = 1000;

	// cout << "test1: " << str0.val() << endl;
	// cout << "test2: " << str0.cref() << endl;
	// (str0.cref()) = 2000;
	// cout << "test1: " << str0.val() << endl;

	//lambda
	//func();
	//func_ref();
	// auto th = 3;
	// auto is_above = IsAbove(th);
	// auto test = is_above(5);
	
	// auto func = Func{};
	//func();
	//test equals true

	// func_mutable();
	// func_mutable_ref();

	auto buttons = make_buttons();
	for(const auto& b: buttons) {
		b.on_click();
	}
	buttons.front().on_click();
	return 0;
}