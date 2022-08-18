#pragma once
#include <core/Common.h>
#include <tree/LeetCodeTree.h>

namespace SortedArrayToBST {
    class Solution {
    private:
        template <typename FwdIt>
        TreeNode* sortedArrayToBST(FwdIt _first, FwdIt _last) {
            if (_first == _last) return nullptr;

            auto dist = distance(_first, _last);
            auto mid = next(_first, dist / 2);

            auto node = new TreeNode(*mid);
            node->left = sortedArrayToBST(_first, mid);
            node->right = sortedArrayToBST(next(mid), _last);

            return node;
        }

    public:
        TreeNode* sortedArrayToBST(const vector<int>& nums) {
            return sortedArrayToBST(nums.begin(), nums.end());
        }
    };


    void test() {
        const auto res = Solution{}.sortedArrayToBST({ -10, -3, 0, 5, 9 });
        BinaryTree::lvlorderTraverse(
            res, [](optional<int> val) { if(val.has_value()) cout << val.value() << endl; });
    }
}