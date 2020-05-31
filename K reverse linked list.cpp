/*
QUES - Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* head, int n) {
    int x=0;
    int y;
    int size=0;
    ListNode *temp=head;
    ListNode * ptr=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        size++;
    }
    
    for(int i=0;i<size;i++)
    {
        temp=head;
        x=i;
        y=x+n-1;
        if(y<size){
        int k=y;
        while(temp!=NULL && x<y)
        {
            int t;
            temp=head;
            int m=k;
            while(m>0)
            {
                temp=temp->next;
                m--;
            }
            k--;
            t=temp->val;
            temp->val=ptr->val;
            ptr->val=t;
            ptr=ptr->next;
            x++;
            y--;
        }
       int s=n/2;
            if(n%2==0){
        while(s>0)
        {
            ptr=ptr->next;
            s--;
        }
            }
            else
            {
                while(s>=0)
        {
            ptr=ptr->next;
            s--;
        }
            }
    }
        else
        {
            int r=size-1;
            temp=head;
            while(temp!=NULL && x<r){
            temp=head;
                int q=r;
            while(q>0){
                temp=temp->next;
                q--;
            }
                r--;
                x++;
            int t=temp->val;
            temp->val=ptr->val;
            ptr->val=t;
            ptr=ptr->next;
            }
        }
        i=i+n-1;
       
    }
    return head;
}
