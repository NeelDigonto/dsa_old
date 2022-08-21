#pragma once
#include "core/Common.h"

namespace Fibonacci {

	template<typename Ty, std::enable_if_t<std::is_integral_v<Ty>, bool> = true>
	class Sandbox {
	private:
		static Ty _fibonacciMemo(Ty _nth, std::vector<std::optional<Ty>>& _memo) {
			if (_nth <= 1) {
				return _nth;
			}

			if (_memo[_nth].has_value()) return _memo[_nth].value();

			_memo[_nth] = _fibonacciMemo(_nth - 1, _memo) + _fibonacciMemo(_nth - 2, _memo);
			return _memo[_nth].value();
		}
	public:

		static Ty fibonacciRec(Ty _nth) {
			if (_nth <= 1) {
				return _nth;
			}

			return fibonacciRec(_nth - 1) + fibonacciRec(_nth - 2);
		}

		static Ty fibonacciMemo(Ty _nth) {
			std::vector<std::optional<Ty>> memo(_nth + 1, std::nullopt);

			return _fibonacciMemo(_nth, memo);
		}

		static Ty fibonacciTab(Ty _nth) {
			std::vector<std::optional<Ty>> memo(_nth + 1, std::nullopt);

			memo[0] = 0;
			memo[1] = 1;

			for (std::size_t it = 2; it <= _nth; ++it) {
				memo[it] = memo[it - 1].value() + memo[it - 2].value();
			}

			return memo[_nth].value();
		}

		static Ty fibonacciSO(Ty _nth) {

			Ty prev2 = 0;
			Ty prev = 1;

			for (std::size_t it = 2; it <= _nth; ++it) {
				Ty current = prev2 + prev;
				prev2 = prev;
				prev = current;
			}

			return _nth == 0 ? 0 : prev;
		}

		static void tests() {
			//benchmark(fibonacciRec, 45);
			//util::benchmark("Memoized", fibonacciMemo, 1'000);
			//util::benchmark("Tabulation", fibonacciTab, 1'000);
			//util::benchmark("Space-Optimized", fibonacciSO, 1'000);
			cout << fibonacciTab(6);
		}

	};

	void test() {
		Sandbox<int>::tests();
	}

}

