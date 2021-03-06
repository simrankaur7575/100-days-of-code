/*
QUES - Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.
*/

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
ListNode* t1 = A ;
ListNode* t2 = A;
ListNode* p = A ;
while(B--){
t1 = t1->next ;
if(t1 == NULL){
A = A->next ;
return A ;
}
}

while(t1!=NULL){
    p = t2 ;
    t2 = t2->next ;
    t1 = t1->next ;
}
p->next = t2->next ;
delete(t2) ;
return A ;
}