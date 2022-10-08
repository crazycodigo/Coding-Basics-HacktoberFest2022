class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *merge=new ListNode();
        ListNode *head1=list1;
        ListNode *head2=list2;
        if(head1==NULL){
            return list2;
        }
        if(head2==NULL){
            return list1;
        }
        if(head1==NULL && head2==NULL){
            return NULL;
        }
        if(head1->val<head2->val){
            merge=head1;
            head1=head1->next;
        }
        else{
            merge=head2;
            head2=head2->next;
        }
        ListNode *res=merge;
        while(head1!=NULL && head2!=NULL){
            if(head1->val<head2->val){
                merge->next=head1;
                head1=head1->next;
            }
            else{
                merge->next=head2;
                head2=head2->next;
            }
            merge=merge->next;
        }
        while(head1!=NULL){
            merge->next=head1;
            head1=head1->next;
            merge=merge->next;
        }
        while(head2!=NULL)
        {
            merge->next=head2;
            head2=head2->next;
            merge=merge->next;  
        } 
        return res;
        
    }
};
