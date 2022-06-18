#pragma once
#include "../../tree//LeetCodeTree.h"

namespace Q102 {

    template<typename Callback>
    static void getLevels(TreeNode* _root, Callback _fn) {
        if (_root == nullptr) {
            _fn(std::vector<int>{});
            return;
        }

        std::vector<TreeNode*> lvl1, lvl2;
        std::vector<TreeNode*>* current_lvl{ &lvl1 }, * next_lvl{ &lvl2 };

        current_lvl->push_back(_root);

        while (!current_lvl->empty()) {
            // generate next node
            for (auto& current_node : *current_lvl) {
                if (current_node) {
                    next_lvl->push_back(current_node->left);
                    next_lvl->push_back(current_node->right);

                }
                else
                {

                }
            }

            // now set current_lvl to next_lvl
            _fn(*current_lvl);
            current_lvl->clear();
            std::swap(current_lvl, next_lvl);
        }
    }

    class Solution {
    public:
        std::vector<std::vector<int>> levelOrder(TreeNode* root) {
            std::vector<std::vector<int>> buffer;
            getLevels(root, [&buffer](std::vector<int>& _lvl) { buffer.push_back(_lvl); });
            return buffer;
        }
    };

    void test() {

        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        Solution{}.levelOrder(root);

    }

}