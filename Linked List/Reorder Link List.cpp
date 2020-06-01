/*
QUES - Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
 
ListNode* Solution::reorderList(ListNode* A) {
    ListNode * ptr=A;
    ListNode * ptr1;
    ListNode * ptr2;
    ListNode * temp1;
    ListNode * temp2;
    int n =0;
    while(ptr!=NULL)
    {
        n++;
        ptr=ptr->next;
    }
    if(n==1 || n==2)
    {
        return A;
    }
    int mid=n/2;
    ptr=A;
    for(int i=0;i<mid-1;i++)
    {
        ptr=ptr->next;
    }
    temp1=ptr->next;
    ptr->next=NULL;
    temp1= reverse(temp1);
    temp2=temp1->next;
    ptr1=A;
    ptr2=ptr1->next;
    int flag=1;
    while(ptr1!=NULL && temp1!=NULL)
    {
        if(flag==1)
        {
            ptr1->next=temp1;
            ptr1=ptr2;
            if(ptr2!=NULL){
            ptr2=ptr2->next;
            }
            flag=0;
        }
        else if(flag==0)
        {
            temp1->next=ptr1;
            temp1=temp2;
            if(temp2!=NULL){
            temp2=temp2->next;
            }
            flag=1;
        }
    }
    return A;
}
