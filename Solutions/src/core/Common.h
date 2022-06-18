#pragma once
#include <any>
#include <bitset>
#include <chrono>
#include <cstdarg>
#include <cstddef>
#include <cstdlib>
#include <functional>
#include <initializer_list>
#include <optional> 
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <utility>
#include <variant>

#include <memory>
#include <memory_resource>
#include <scoped_allocator>
#include <climits>
#include <limits>

#include <cassert>
#include <exception>
#include <stdexcept>

#include <string>
#include <string_view>

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <iterator>

#include <algorithm>
#include <execution>

#include <cmath>
#include <complex>
#include <random>
#include <ratio>

#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <streambuf>

#include <algorithm>
#include <cmath>

#include <regex>

/*
#include <bits/stdc++.h>
using namespace std;
using sz = std::size_t;
*/

using namespace std;

using sz = std::size_t;

template<typename T>
ostream& operator << (ostream& os, const vector<T>& v) {
	os << "[ ";
	for (auto it = v.cbegin(); it != v.cend(); ++it)
		os << *it << " ";
	os << "]";
	return os;
}

namespace util {

	template<typename FwdIt>
	ostringstream printLinearDS(FwdIt _first, FwdIt _last) {
		ostringstream oss;

		if (distance(_first, _last) == 1)
			oss << *_first;
		else {
			for (auto it = _first; it != _last - 1; ++it)
				oss << *it << ", ";
			oss << *prev(_last);
		}

		return oss;
	}

	template<typename C>
	ostringstream print(const C& _c) {
		return printLinearDS(_c.begin(), _c.end());
	}



	template<typename Func, typename ...Args>
	void benchmark(const std::string& _test_name, Func _func, Args&&... _args) {
		auto start = std::chrono::high_resolution_clock::now();

		_func(std::forward<Args>(_args)...);
		auto finish = std::chrono::high_resolution_clock::now();

		double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();

		std::cout << _test_name << "took (seconds): " << elapsed_seconds << std::endl;
	}

	template<typename T>
	void forEach(T _iterable, void (*_lambda)(const typename T::value_type&, std::size_t)) {
		typename T::const_iterator iterator = _iterable.begin();
		std::size_t index = 0;

		while (iterator != _iterable.end())
			_lambda(*iterator++, index++);
	}

	template<typename T>
	[[nodiscard]] T map(T _iterable, auto (*_lambda)(const typename T::value_type&, std::size_t) -> typename T::value_type) {
		typename T::const_iterator iterator = _iterable.begin();

		std::size_t index = 0;
		std::array<typename T::value_type, _iterable.size()> new_iterable;

		while (iterator != _iterable.end())
			new_iterable[index] = _lambda(*iterator++, index++);

		return new_iterable;
	}

	template<typename Wt>
	class UDGAdjMat {
	public:
		using node_t = size_t;
		struct Edge {
			node_t u;
			node_t v;
			Wt fwdWt;
			Wt bckWt;
		};
	private:
		vector<vector<optional<Wt>>> graph_;
	public:
		UDGAdjMat() = delete;
		UDGAdjMat(size_t N) {
			graph_ = vector<vector<optional<Wt>>>(N, vector<optional<Wt>>(N, nullopt));
		}
		void addEdge(Edge _edge) {
			graph_[_edge.u][_edge.v] = _edge.fwdWt;
			graph_[_edge.v][_edge.u] = _edge.bckWt;
		}

		vector<Wt> getEdges() const noexcept {
			
		}

		void printEdge() {

		}
	};

}