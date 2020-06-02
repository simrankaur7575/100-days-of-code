/*
QUES - Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    if(A==NULL || A->next==NULL)
    {
        return A;
    }
    ListNode * temp = A;
    ListNode * head = new ListNode (0);
    ListNode * tail = head;
    while(temp!= NULL && temp->val>=B)
    {
    A=A->next;
    ListNode * x = new ListNode (temp->val);
    tail->next=x;
    tail=tail->next;
    temp=temp->next;
    }
    if(temp==NULL)
    {
        return head->next;
    }
    ListNode * curr = temp->next;
    while(curr!=NULL)
    {
        if(curr->val>=B)
        {
            temp->next=curr->next;
            ListNode * x = new ListNode (curr->val);
            tail->next=x;
            tail=tail->next;
            curr=temp->next;
        }
        else
        {
            temp=temp->next;
            curr=curr->next;
        }
    }
    temp->next=head->next;
    return A;
}
