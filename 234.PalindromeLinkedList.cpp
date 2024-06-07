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
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            fast=fast->next->next;
            slow=slow->next;

        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* forw = NULL;
        while(curr != NULL){
            forw = curr->next;
            curr->next = pre;
            pre = curr;
            curr = forw;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        if(head->next == NULL){
            return true;
        }
        ListNode* mid = middle(head);
        ListNode* d = mid->next;
        mid->next = reverse(d);
        mid = mid->next;
        while(mid != NULL){
            if(temp->val != mid->val){
                return false;
            }
            mid = mid->next;
            temp = temp->next;
        }
        return true;
    }
};
