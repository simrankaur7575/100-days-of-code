/*
QUES - Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *curr = A, *prev = NULL, *nex = NULL;
    int cnt =0;
     while(cnt<2 && curr) {
         nex = curr->next;
         curr->next = prev;
         prev = curr;
         curr = nex;
         cnt++;
     }
     if(nex) {
         A->next = swapPairs(nex);
     }
     return prev;
}
