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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* del = head;
        ListNode* prev = del;
        int c = 0;
        for(int i = 0; i < n ; i++){
            curr = curr->next;
            c++;
        }
        
        while(curr!=NULL){
            prev = del;
            del = del->next;
            curr = curr->next;
            c++;
        }
        
        prev->next = del->next;
        if(c==n)
            return head->next;
        return head;
    }
};