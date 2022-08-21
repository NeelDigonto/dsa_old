
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int __main(int argc, char* a[])
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    size_t test_cases;
    cin >> test_cases;

    for (size_t test_case{ 0 }; test_case != test_cases; ++test_case) {
        size_t N, G;

        cin >> N >> G;

        vector<uint32_t> costs;
        costs.reserve(G);

        // take the cost array
        for (size_t i{ 0 }; i != G; ++i) {
            size_t temp;
            cin >> temp;
            costs.push_back(temp);
        }

        nth_element(costs.begin(), costs.begin() + N - 1, costs.end());

        size_t money{ 0 };
        for (size_t i{ 0 }; i != N; ++i) {
            money += costs[i];
        }

        cout << money << endl;
    }

    return 0;
}
