#include <iostream>
#include <vector>


namespace Q1 {

	std::vector<int> twoSum(const std::vector<int>& nums, int target)
	{

		for (auto i = 0; i < nums.size() - 1; ++i)
		{
			for (auto j = i + 1; j < nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target)
					return { i, j };
			}
		}
		return {};
	}

	bool test()
	{

		std::vector<int> answer = twoSum({ 2,7,11,15 }, 9);

		std::cout << answer[0] << " " << answer[1] << std::endl;
		return true;
	}
}