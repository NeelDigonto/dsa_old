#pragma once
#include <iostream>
#include "../../tree/LeetCodeTree.h"

namespace Q104 {

    class Solution {
    public:
        int maxDepth(TreeNode* _root) {
            if (_root == nullptr)
                return 0;

            std::vector<const TreeNode*> lvl1, lvl2;
            std::vector<const TreeNode*>* current_lvl{ &lvl1 }, * next_lvl{ &lvl2 };

            current_lvl->push_back(_root);
            std::size_t height = 1;

            while (!current_lvl->empty()) {
                // generate next node
                for (auto& current_node : *current_lvl) {
                    if (current_node) {
                        next_lvl->push_back(current_node->left);
                        next_lvl->push_back(current_node->right);
                    }
                }

                // now set current_lvl to next_lvl
                current_lvl->clear();
                std::swap(current_lvl, next_lvl);
                height++;
            }

            return height - 2; // minus one cause the last lvl is always full of nulls, and minus 1 cause 1 extra post loop variable increment
        }
    };

	void test() {

        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        /*TreeNode* root = nullptr;*/

        /*TreeNode* root = new TreeNode(1);
        root->right = new TreeNode(2);*/

        Solution sol;
        std::cout << sol.maxDepth(root);

	}
}