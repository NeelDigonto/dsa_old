#pragma once
#include <core/Common.h>

namespace NinjaTraining {
	using sz = std::size_t;

	template<typename T>
	T _ninjaTrainingMemo(sz day, sz last_task, const vector<vector<T>>& points, vector<array<T, 3>>& memo){
		static constexpr auto nval = numeric_limits<T>::min();
		static constexpr sz ntask = -1;
		T max_val = nval;

		if (day == 0) {
			for (sz task = 0; task != 3; ++task)
				if(task != last_task)
					max_val = max(max_val, points[0][task]);
			return max_val;
		}

		if (last_task != ntask && memo[day][last_task] != nval) return memo[day][last_task];
	
		for (sz task = 0; task != 3; ++task) {
			if (task != last_task) {
				const int val = points[day][task] + _ninjaTrainingMemo(day - 1, task, points,  memo);
				max_val = max(max_val, val);
			}
		}

		if (last_task == ntask) return max_val;
		else return memo[day][last_task] = max_val;
	}

	template<typename T>
	T ninjaTrainingMemo(sz n, const vector<vector<T>>& points)
	{
		static constexpr auto nval = numeric_limits<T>::min();
		static constexpr sz ntask = -1;
		vector<array<T, 3>> memo(n, array<T, 3>{nval, nval, nval});
		return _ninjaTrainingMemo(n - 1, ntask, points, memo);
	}

	template<typename T>
	T ninjaTrainingTab(sz n, const vector<vector<T>>& points) {
		static constexpr auto nval = numeric_limits<T>::min();
		static constexpr sz ntask = -1;

		if (n == 1)
			return max({ points[0][0], points[0][1], points[0][2] });

		vector<array<T, 3>> memo(n, array<T, 3>{nval, nval, nval});

		memo[0][0] = points[0][0];
		memo[0][1] = points[0][1];
		memo[0][2] = points[0][2];

		for (sz day = 1; day != n; ++day) {
			for (sz curr_task = 0; curr_task != 3; ++curr_task) {
				T max_val = nval;
				for (sz task = 0; task != 3; ++task) {
					if (task != curr_task) {
						max_val = max(max_val, memo[day-1][task]);
					}
				}
				memo[day][curr_task] = max_val + points[day][curr_task];
			}
		}

		const auto& last_day = memo[n - 1];

		return *max_element(last_day.begin(), last_day.end());
	}

	template<typename T>
	T ninjaTrainingSO(sz n, const vector<vector<T>>& points) {
		static constexpr auto nval = numeric_limits<T>::min();
		static constexpr sz ntask = -1;

		if (n == 1)
			return max({ points[0][0], points[0][1], points[0][2] });

		array<T, 3> last_day{nval, nval, nval};

		last_day[0] = points[0][0];
		last_day[1] = points[0][1];
		last_day[2] = points[0][2];

		for (sz day = 1; day != n; ++day) {
			array<T, 3> curr_day;
			for (sz curr_task = 0; curr_task != 3; ++curr_task) {
				T max_val = nval;
				for (sz task = 0; task != 3; ++task) {
					if (task != curr_task) {
						max_val = max(max_val, last_day[task]);
					}
				}
				curr_day[curr_task] = max_val + points[day][curr_task];
			}
			last_day = curr_day;
		}

		return *max_element(last_day.begin(), last_day.end());
	}

	int ninjaTraining(int n, const vector<vector<int>>& points)
	{
		//return ninjaTrainingMemo(n, points);
		//return ninjaTrainingTab(n, points);
		return ninjaTrainingSO(n, points);
	}

	void test() {
		cout << ninjaTraining(3, 
			{ {1,2,5},
			{3, 1, 1}, 
			{3, 3, 3} }) << endl;

		cout << ninjaTraining(3,
			{ {10, 40, 70},
			{20, 50, 80},
			{30, 60, 90} }) << endl;

		cout << ninjaTraining(3,
			{ {18, 11, 19},
			{4, 13, 7},
			{1, 8, 13} }) << endl;

		cout << ninjaTraining(10, {
			{99, 11, 68},
			{94, 40, 29},
			{74, 64, 1},
			{83, 56, 42},
			{68, 15, 85},
			{97, 32, 43},
			{100, 46, 4},
			{23, 74, 73},
			{54, 9, 51},
			{50, 43, 88 },
		}) << endl;
	}

}