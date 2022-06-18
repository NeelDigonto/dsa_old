#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <optional>
#include <queue>
#include <stack>
#include <iostream>
#include <utility>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BinaryTree {
public:
    using arr_rep_t = std::vector<std::optional<int>>;

    template<typename Callback>
    static void lvlorderTraverse(const TreeNode* _root, Callback _fn) {
        if (_root == nullptr) {
            _fn(std::optional<int>{ std::nullopt });
            return;
        }

        std::vector<const TreeNode*> lvl1, lvl2;
        std::vector<const TreeNode*>* current_lvl{ &lvl1 }, * next_lvl{ &lvl2 };

        current_lvl->push_back(_root);

        while (!current_lvl->empty()) {
            // generate next node
            for (auto& current_node : *current_lvl) {
                if (current_node) {
                    next_lvl->push_back(current_node->left);
                    next_lvl->push_back(current_node->right);

                    _fn(std::optional<int>{ current_node->val });
                }
                else
                {
                    _fn(std::optional<int>{ std::nullopt });
                }
            }

            // now set current_lvl to next_lvl
            current_lvl->clear();
            std::swap(current_lvl, next_lvl);
        }
    }

    [[nodiscard]] static arr_rep_t serialize_t(TreeNode* _root) {
        arr_rep_t _arr_rep;

        lvlorderTraverse(_root, [&_arr_rep](const std::optional<int>& _res) {
            _arr_rep.push_back(_res);
            });

        return _arr_rep;
    }

    // Encodes a tree to a single string.
    [[nodiscard]] static std::string serialize(TreeNode* root) {
        if (!root)
            return std::string{};

        arr_rep_t _arr_rep = serialize_t(root);

        const char* buffer_data = reinterpret_cast<const char*>(_arr_rep.data());
        const std::size_t buffer_size = _arr_rep.size() * sizeof(arr_rep_t::value_type);

        std::string buffer(buffer_data, buffer_size);

        return buffer;
    }

    [[nodiscard]] static TreeNode* deserialize_t(arr_rep_t _arr_rep) {
        std::queue<TreeNode*> queqe;
        arr_rep_t::const_iterator pos = std::begin(_arr_rep);

        TreeNode* root = new TreeNode(pos++->value());
        queqe.push(root);

        while (!queqe.empty()) {
            const auto node = queqe.front();

            node->left = (pos != _arr_rep.end() && pos->has_value()) ? new TreeNode(pos->value()) : nullptr;
            pos++;
            node->right = (pos != _arr_rep.end() && pos->has_value()) ? new TreeNode(pos->value()) : nullptr;
            pos++;

            if (node->left != nullptr) queqe.push(node->left);
            if (node->right != nullptr) queqe.push(node->right);

            queqe.pop();
        }

        return root;
    }

    // Decodes a string rep of a tree
    [[nodiscard]] static TreeNode* deserialize(std::string data) {
        if (data.size() < sizeof(arr_rep_t::value_type))
            return nullptr;

        arr_rep_t _arr_rep;
        auto buffer_t = reinterpret_cast<std::optional<int>*>(data.data());
        _arr_rep.assign(buffer_t, buffer_t + data.size() / sizeof(arr_rep_t::value_type));

        return deserialize_t(_arr_rep);
    }

    static void printLvlOrderTraverse(TreeNode* _root) {
        lvlorderTraverse(_root, [](std::optional<int> _elem) {
            std::cout << (_elem.has_value() ? std::to_string(_elem.value()) : "null") << ", ";
            });
    }
};



struct Trunk
{
    Trunk* prev;
    std::string str;

    Trunk(Trunk* prev, std::string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p)
{
    if (p == nullptr) {
        return;
    }

    showTrunks(p->prev);
    std::cout << p->str;
}

// Recursive function to print a binary tree.
// It uses the inorder traversal.
void printTree(TreeNode* root, Trunk* prev, bool isLeft)
{
    if (root == nullptr) {
        return;
    }

    std::string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev) {
        trunk->str = "---";
    }
    else if (isLeft)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    std::cout << root->val << std::endl;

    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

//	printTree(tree, nullptr, false);