#pragma once
#include <core/Common.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


namespace ListIntersection {

    class Solution {
    public:
        ListNode* getIntersectionNodeHash(ListNode* headA, ListNode* headB) {
            unordered_set<ListNode*> hash;
            
            ListNode* current_node = headB;
            while (current_node != nullptr) {
                hash.insert(current_node);
                current_node = current_node->next;
            }


            current_node = headA;
            while (current_node != nullptr) {
                if (hash.find(current_node) != hash.end())
                    return current_node;
                current_node = current_node->next;
            }

            return nullptr;
        }

        ListNode* getIntersectionNodeSO(ListNode* headA, ListNode* headB) {
            size_t list_a_len = 0, list_b_len = 0;

            ListNode* current_node = headA;
            while (current_node != nullptr) {
                list_a_len++;
                current_node = current_node->next;
            }

            current_node = headB;
            while (current_node != nullptr) {
                list_b_len++;
                current_node = current_node->next;
            }

            if (list_a_len > list_b_len) {
                for (size_t i = 0; i != list_a_len - list_b_len; ++i)
                    headA = headA->next;
            }
            else if (list_a_len < list_b_len) {
                for (size_t i = 0; i != list_b_len - list_a_len; ++i)
                    headB = headB->next;
            }

            while (headA != nullptr) {
                if (headA == headB) return headA;
                else { headA = headA->next; headB = headB->next; };
            }

            return nullptr;
        }

        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
            //getIntersectionNodeHash(headA, headB);
            getIntersectionNodeSO(headA, headB);
        }
    };

}