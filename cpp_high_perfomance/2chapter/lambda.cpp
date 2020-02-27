#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cassert>
#include <functional>



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

// Mutable lambda
// Capture by value

auto func_mutable() -> void {
	auto v = 7;
	auto lambda = [v]() mutable {
		std::cout << v << " ";
		++v;
	};
	assert(v == 7);
	lambda();
	lambda();
	assert(v == 7);
	std::cout << "res: " << v;
}

auto func_mutable_ref() -> void {
	auto v = 7;
	auto lambda = [&v]() mutable {
		std::cout << v << " ";
		++v;
	};
	assert(v == 7);
	lambda();
	lambda();
	assert(v == 9);
	std::cout << "res: " << v;
}

class Foo2 {
public:
	auto member_function() {
		auto a = 0;
		auto b = 1.0f;
		// Capture all variables by copy
		auto lambda_0 = [=]() { std::cout << a << b << m_; };
		// Capture all variables by reference
		auto lambda_1 = [&]() { std::cout << a << b << m_; };
		// Capture member variables by reference
		auto lambda_2 = [this]() { std::cout << m_; };
		// Capture member variables by copy
		//auto lambda_3 = [*this]() { std::cout << m_; };
	}
private:
	int m_{};
};


// Store the action to corresponding to clicking the buttoons
class Button
{
private:
	std::function<void(void)> on_click_{};
public:
	Button(std::function<void(void)> click);
	~Button();

	auto on_click() const {on_click_();}
};
Button::Button(std::function<void(void)> click) : on_click_(click) {}
Button::~Button() {}

auto make_buttons() {
	auto beep_button = Button([beep_count = 0]() mutable {
		std::cout << "Beep:" << beep_count << "! " << std::endl;
		++beep_count;
	});

	auto bop_button = Button([]{ std::cout << "Bop. " << std::endl; });
	auto silent_button = Button([]{});
	auto buttons = std::vector<Button>{beep_button, bop_button, silent_button};
	return buttons;
}