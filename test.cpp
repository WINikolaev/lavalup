#include <iostream>
#include <memory>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>


using namespace std;

typedef struct {
	int count;
	char *msg1;
	char *msg2;
}data;
/*
template <class Iterator>
struct iterator_traits {
	typedef Iterator::difference_type	difference_type;
	typedef Iterator::value_type		value_type;
	typedef Iterator::pointer			pointer;
	typedef Iterator::reference			reference;
	typedef Iterator::iterator_category	itercator_category;
}

template <class It>
void iter_swap(It i, It j) {
	typename iterator_traits<It>::value_type t = *i;
	*i = *j;
	*j = t;
}
*/

template<class T>
struct Sum {
	typedef typename T::value_type type;
	type sum;
	Sum() {sum = 0;}
	void operator() (type n) {cout << "operate: " << n << endl;}
	
};

int main() {
	vector<int> v1 {5,4,3,7,8,9,9,9,2,40,31,1};
	vector<int> v2 {5,6,7,8,9,9};
	auto p = v1.begin();
	p++;
	p++;
	p++;
	
	v1.erase(remove(v1.begin(),p,0), v1.end());
	return 0;
}

// vector<int> vec {1,2,3,4,5};
// std::vector<int>::iterator vbegin = vec.begin();
// std::vector<int>::iterator vend = vec.end();
// std::vector<int>::reverse_iterator vrbegin = vec.rbegin();
// std::vector<int>::reverse_iterator vrend = vec.rend();
// vbegin += vec.size()/2;
// vrbegin += vec.size()/2;
// vrbegin--;
// *vbegin = 100;
// *vrbegin = 101;

// auto ls_test = make_unique<list<data>>();
// 	ls_test->push_back({1, "", ""});
// 	ls_test->push_back({2, "", ""});
// 	ls_test->push_back({3, "", ""});
// 	ls_test->push_back({4, "", ""});
// 	if (ls_test->empty()) {return 0;}

// 	auto iterator1 = ls_test->begin();
// 	auto iterator2 = ls_test->begin();
// 	iterator2++;
// 	while (iterator2 != ls_test->end())
// 	{
// 		iterator2++;
// 		if (iterator2 == ls_test->end()){break;}
// 		iterator2++;
// 		iterator1++;
// 	}
// 	cout << "\r\nmidean: " << iterator1->msg1 << iterator1->count << endl;
	
// 	auto vec_test = make_unique<vector<data>>();

// 	deque<int> deq_t(5);
// 	deq_t.push_back(2);
// 	deq_t.push_front(3);
// 	deq_t.insert(deq_t.begin()+4, 245);
// 	deq_t.at(2) = 1111;
	
// 	cout << "test: " << deq_t.at(0) << endl;
	
// 	deque<int> deq {3, 1, 4, 1, 5};
// 	stack<int> st(deq);
// 	st.push(3);
// 	st.push(2);
// 	st.push(4);
// 	cout << "size of stack: " << st.size() << endl;
// 	cout << "test: " << st.top() << endl;
// 	st.pop();
// 	cout << "test: " << st.top() << endl;
// 	st.pop();
// 	cout << "test: " << st.top() << endl;
// 	cout << "size of stack: " << st.size() << endl;
// 	for (size_t i = 0; i < st.size; i++)
// 	{
// 		cout << "test: " << st.top() << endl;
// 	}
// 	deque<int> deq {3, 1, 4, 1, 5};
// 	queue<int> c3(deq);
// 	cout << "size of queue: " << c3.size() << endl;
// 	cout << "test: " << c3.front() << endl;
// 	c3.pop();
// 	cout << "size of queue: " << c3.size() << endl;
// 	cout << "test: " << c3.front() << endl;
// 	c3.pop();
// 	cout << "size of queue: " << c3.size() << endl;
// 	cout << "test: " << c3.front() << endl;
// 	c3.pop();
// 	cout << "size of queue: " << c3.size() << endl;


// 	vector<bool> bvect;
// 	bvect.push_back(true);
// 	bvect.push_back(false);
// 	bvect.push_back(true);
// 	bvect.push_back(false);
// 	bvect.push_back(true);
// 	bvect.push_back(false);
// 	bvect.push_back(true);
// 	bvect.push_back(false);

// 	bvect.push_back(true);
// 	bvect.push_back(false);
// 	bvect.push_back(true);
// 	bvect.push_back(false);
// 	bvect.push_back(true);
// 	bvect.push_back(false);
// 	bvect.push_back(true);
// 	bvect.push_back(false);

// 	vector<int> intvect {1,2,3,4,5,6,67,8,9};
// 	auto iteratro_bvect = intvect.begin();
// 	cout << "size of vector bool: " << intvect.size() << endl;
	
// 	for (size_t i = 0; i < intvect.size() - 3; i++)
// 	{
// 		iteratro_bvect++;
// 	}



// multiset<int> st;
	// st.insert(1);
	// st.insert(3);
	// st.insert(3);
	// st.insert(2);
	// auto test = st.equal_range(3);
	// cout << "test size: "  << endl;
	// map<string, int> maps;
	// maps.insert(map<string, int>::value_type("a", 123));
	// maps.insert(map<string, int>::value_type("b", 1));
	// maps.insert(map<string, int>::value_type("c", 2));
	// maps.insert(map<string, int>::value_type("d", 3));
	// maps.insert(map<string, int>::value_type("e", 4));
	// maps["b"] = 123;

	// cout << "test: " << maps.size() << endl;
	// auto it = maps.find("b");
	// if (it != maps.end())
	// {
	// 	cout << "res: " << it->second << endl;
	// }