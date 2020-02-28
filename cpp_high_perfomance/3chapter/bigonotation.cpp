#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cassert>
#include <functional>
#include <vector>



auto linear_search(const std::vector<int>& vals, int key) {
	for (auto &&v : vals) {
		if (v == key)
		{
			return true;
		}
	}
	return false;
}



auto binary_search(const std::vector<int>& a, int&& key) {
	if (a.empty()) {
		return false;
	}
	auto low = size_t{0};
	auto high = a.size() - 1;
	while (low <= high) {
		const auto mid = low + ((high - low) / 2);
		if (a[mid] < key) {
			low = mid + 1;
		} else if (a[mid] > key) {
			high = mid - 1;
		} else {
			return true;
		}
	}
	return false;
}