#include <iostream>
#include <algorithm>
#include <vector>
#include <list>



// labmda example
auto func() {
	auto vals = {1,2,3,4,5,6};
	auto th = 3;
	auto is_above=[th](int v){
		return v > th;
	};
	th = 4;
	auto count_b=std::count_if(
		vals.begin(),
		vals.end(),
		is_above
	);
	// count_b equals 3
}

auto func_ref() {
	auto vals = {1,2,3,4,5,6};
	auto th = 3;
	auto is_above=[&th](int v){
		return v > th;
	};
	th = 0;
	auto count_b=std::count_if(
		vals.begin(),
		vals.end(),
		is_above
	);
	// count_b equals 2
}

class IsAbove {
public:
	explicit IsAbove() {}
	IsAbove(int th) : th{th} {}
	// The only member function
	auto operator()(int v)const{return v > th;	}
private:
int th{0}; // Members
};


class IsAbove_ref{
public:
	IsAbove_ref(int& th) : th{th} {}
	// The only member function
	auto operator()(int v)const{return v > th;}
private:
	int& th; // Members
};


class Func {
public:
	Func() {}
	auto operator()() const->void {
		for(auto&& v : c)
			std::cout << v;
	}
private:
	std::list<int> c{4,2};
};