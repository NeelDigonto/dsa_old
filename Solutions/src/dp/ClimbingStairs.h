#pragma once
#include "core/Common.h"
//Overlapping Subproblems

namespace ClimbingStairs {

	template<typename Ty, std::enable_if_t<std::is_integral_v<Ty>, bool> = true>
	class Sandbox {
	private:
		static Ty _climbingStairsMemo(Ty _stairsToClimb, vector<optional<Ty>>& _memo) {

			if (_stairsToClimb <= 1) {
				return 1;
			}

			if (_memo[_stairsToClimb].has_value()) return _memo[_stairsToClimb].value();

			_memo[_stairsToClimb] = climbingStairsRec(_stairsToClimb - 1) + climbingStairsRec(_stairsToClimb - 2);
			return _memo[_stairsToClimb].value();
		}
	public:

		static Ty climbingStairsRec(Ty _stairsToClimb) {
			if (_stairsToClimb <= 1) {
				return 1;
			}

			return climbingStairsRec(_stairsToClimb - 1) + climbingStairsRec(_stairsToClimb - 2);
		}

		static Ty climbingStairsMemo(Ty _stairsToClimb) {
			vector<optional<Ty>> memo(_stairsToClimb + 1, std::nullopt);
			
			return _climbingStairsMemo(_stairsToClimb, memo);
		}

		static Ty climbingStairsTab(Ty _stairsToClimb) {

			vector<optional<Ty>> memo(_stairsToClimb + 1, std::nullopt);

			memo[0] = 1;
			memo[1] = 1;

			for (size_t i = 2; i <= _stairsToClimb; ++i) {
				memo[i] = memo[i - 1].value() + memo[i - 2].value();
			}

			return memo[_stairsToClimb].value();
		}

		static Ty climbingStairsSO(Ty _stairsToClimb) {

			if (_stairsToClimb <= 1) return 1;

			Ty prev2 = 1;
			Ty prev = 1;

			for (size_t i = 2; i <= _stairsToClimb; ++i) {
				Ty current = prev + prev2;
				prev2 = prev;
				prev = current;
			}

			return prev;
		}

	};

	void test() {
		cout << Sandbox<int>::climbingStairsRec(3) << endl;
	}

}


