/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* Solve(ListNode* list1, ListNode* list2) {
        if (list1->next == nullptr) {
            list1->next = list2;
            return list1;
        }

        ListNode* curr1 = list1;
        ListNode* next1 = list1->next;
        ListNode* curr2 = list2;

        while (next1 != nullptr && curr2 != nullptr) {
            if (curr1->val <= curr2->val && curr2->val <= next1->val) {
                ListNode* next2 = curr2->next;
                curr1->next = curr2;
                curr2->next = next1;
                curr1 = curr2;
                curr2 = next2;
            } else {
                curr1 = next1;
                next1 = next1->next;
                if (next1 == nullptr) {
                    curr1->next = curr2;
                    return list1;
                }
            }
        }

        return list1;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        if (list1->val < list2->val) {
            return Solve(list1, list2);
        } else {
            return Solve(list2, list1);
        }
    }
};
