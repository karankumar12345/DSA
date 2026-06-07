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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* first = list1;
        ListNode* second = list2;
        ListNode* merge = new ListNode(-1);
        ListNode* current = merge;
        while (first != NULL && second != NULL) {
            if (first->val > second->val) {
                current->next = second;
                second = second->next;
            }
            else{
                current->next=first;
                first=first->next;
            }
            current=current->next;
        }

        if(first!=NULL){
            current->next=first;
        }
        if(second!=NULL){
            current->next=second;
        }
        return merge->next;
    }
};