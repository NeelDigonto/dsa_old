#pragma once
#include "core/Common.h"

//partition dp

struct MatDim {
	std::size_t i;
	std::size_t j;
};


namespace MatriXChainMultiplication {

	//template<typename CTy>
	class Sandbox {
		//using vtype = typename CTy::value_type;
		using vtype = unsigned int;
		using sz = std::size_t;
	private:
		static auto _mctMemo(const std::vector<unsigned int>& _c, sz i, sz j, std::vector<std::vector<std::optional<vtype>>>& cache) -> vtype {
			if (i == j)
				return 0;

			if (cache[i][j].has_value())
				return cache[i][j].value();

			sz min_cost = std::numeric_limits<vtype>::max();

			for (sz k = k = i; k < j; ++k) {
				sz steps = _c[i - 1] * _c[k] * _c[j]
					+ _mctMemo(_c, i, k, cache) + _mctMemo(_c, k + 1, j, cache);

				if (steps < min_cost) min_cost = steps;
			}

			cache[i][j] = min_cost;
			return cache[i][j].value();
		}
	public:
		static auto mctMemo(const std::vector<unsigned int>& _c) -> vtype {
			std::vector<std::vector<std::optional<vtype>>> cache(_c.size(), std::vector<std::optional<vtype>>(_c.size(), std::nullopt));
			return _mctMemo(_c, 1, _c.size() - 1, cache);
		}

	public:
		static auto mctTab(const std::vector<unsigned int>& _c) -> vtype {
			std::vector<std::vector<std::optional<vtype>>> cache(_c.size(), std::vector<std::optional<vtype>>(_c.size(), std::nullopt));

			for (sz it = 0; it != _c.size(); ++it) 
				cache[it][it] = 0;

			for (sz i = _c.size() - 1; i >= 1; i--) {
				for (sz j = i + 1; j < _c.size(); j++) {
					sz min_cost = std::numeric_limits<vtype>::max();

					for (sz k = k = i; k < j; ++k) {
						sz steps = _c[i - 1] * _c[k] * _c[j]
							+ cache[i][k].value() + cache[k + 1][j].value();

						if (steps < min_cost) min_cost = steps;
					}

					cache[i][j] = min_cost;
				}
			}

			return cache[1][_c.size()-1].value();
		}

		static void tests() {

			std::vector<unsigned int> sample{ 10, 30, 5, 60 };
			//benchmark("Recursive", mctRec, std::vector<unsigned int>{ 10, 30, 5, 60 });
			//benchmark("Memoized", fibonacciMemo, { 10, 30, 5, 60 });
			//benchmark("Tabulation", fibonacciTab, { 10, 30, 5, 60 });
			//benchmark("Space-Optimized", fibonacciSO, { 10, 30, 5, 60 });

			std::cout << mctMemo(sample) << std::endl;

			std::cout << mctTab(sample) << std::endl;
		}

	};

	void test() {
		Sandbox::tests();
	}

}