/*
QUES - Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
ListNode* Solution::rotateRight(ListNode* A, int B) {
ListNode* t1 = A ;
ListNode* t2 = A;
ListNode* ptr = A;
    int len=1;
    while(ptr->next!=NULL){
        ptr = ptr->next;
        len++;
    }
    B = B%len;
while(B>0){
    if(t1->next!=NULL)
t1 = t1->next ;
if(t1==NULL){
return A ;
}
B--;
}

while(t1->next!=NULL){
    t2 = t2->next ;
    t1 = t1->next ;
}
t1->next=A;
A=t2->next;
t2->next=NULL;
return A ;
}
