#include <iostream>
#include "classes.h"
#include <cstdlib>
#include <memory>
#include <string>
#include <typeinfo>

using namespace std;

void f_foo(foo val) {
	cout << "call function FOO" << endl;
}

foo f_foo2() {
	cout << "call function FOO2" << endl;
	foo temp(2);
	return temp;
}


struct unit {
	virtual ~unit(){}
};


struct ch_i : unit {};

void someFunc(int i = 0, double d = 0.1) {
	cout << "someFunc->" << "int: " << i << ", double: " << d << endl;
}


template<typename T>
void f1(T&& param) {
	cout << "T: " << param << endl;
}

template<typename T>
void f2(T param) {
	cout << "T2: " << param << endl;
}

template<typename T>
void f3(T& param) {
	cout << "T3: " << param << endl;
}

class Widget
{
private:
	int x{1222};
public:
	void push() {
		cout << "x: " << x << endl;
	}
};


class init
{
private:
	
public:
	init(int i, bool b) {
		cout << "int i, bool b" << endl;
	};
	init(int i, double d) {
		cout << "int i, double d" << endl;
	};
	init(std::initializer_list<long double> ld) {
		cout << "initializer_list ld: " << &ld << endl;
	};
};

int main () {
	//init w1(12,true);
	//init w2{12,true};
	//init w3(10, 5.0);
	//init w4{10, 5.0};
	
	decltype(std::string::find()) test;
	
	return 0;
}