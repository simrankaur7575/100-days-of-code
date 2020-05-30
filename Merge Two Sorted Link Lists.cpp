/*
QUES - Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *head;
    ListNode *curr;
    ListNode *ptr1=A;
    ListNode *ptr2=B;
    if(A->val<B->val)
    {
        head=A;
        ptr1=ptr1->next;
    }
    else
    {
        head=B;
        ptr2=ptr2->next;
    }
    curr=head;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->val<ptr2->val)
        {
            curr->next=ptr1;
            curr=curr->next;
            ptr1=ptr1->next;
        }
        else
        {
            curr->next=ptr2;
            curr=curr->next;
            ptr2=ptr2->next;
        }
    }
    if(ptr1==NULL)
    {
        curr->next=ptr2;
    }
    else
    {
        curr->next=ptr1;
    }
    return head;
}
