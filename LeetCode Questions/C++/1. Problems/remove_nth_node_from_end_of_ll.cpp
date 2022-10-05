/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode*ptr = head;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    int p = count-n;
    struct ListNode*ptr1 = head;
    if(count==1) return NULL;
    else if(count==n)
    {
        head = ptr1->next;
    }
    else
    {
        int i=0;
        while(ptr1!=NULL && i<p-1)
        {
            printf("%d ",ptr1->val);
            ptr1=ptr1->next;
            i++;
        }
        struct ListNode*p1 = ptr1->next;
        ptr1->next=p1->next;
        free(p1);
    }
    return head;
}
