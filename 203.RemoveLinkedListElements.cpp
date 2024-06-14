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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr=head;
        ListNode* pre=NULL;
        ListNode* forw=NULL;
        while(curr != NULL){
            if(curr->val == val){
                forw=curr->next;
                if (pre != nullptr) {
                    pre->next = forw;
                }else {
                    head = forw;
                }
                delete curr;
                curr = forw;
            }else {
                pre = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
