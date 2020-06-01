/*
QUES - Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode* reverse(ListNode *head)
 {
     if(head->next==NULL || head==NULL)
     {
         return head;
         
     }
     ListNode *temp;
     temp=reverse(head->next);
     head->next->next=head;
     head->next=NULL;
     
     
     return  temp;
     
     
 }
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B==C)
    {
        return A;
    }
    ListNode *prev=NULL;
    ListNode *temp;
    ListNode *head=A;
    ListNode *ptr;
    int x=B;
    if(B==1)
    {
        while(x<C)
    {
        head=head->next;
        x++;
    }
    temp=head->next;
    head->next=NULL;
    A = reverse(A);
    ptr = A;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    return A;
    }
    else{
    while(B>1)
    {
        prev=head;
        head=head->next;
        B--;
    }
    
    while(x<C)
    {
        head=head->next;
        x++;
    }
    temp=head->next;
    head->next=NULL;
    prev->next = reverse(prev->next);
    while(prev->next!=NULL)
    {
        prev=prev->next;
    }
    prev->next=temp;
    return A;
    }
}
