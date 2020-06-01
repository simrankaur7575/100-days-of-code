/*
QUES - You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
            if(!A)
                return B;
            if(!B)
                return A;
            int carry = (A->val + B->val) / 10;
            ListNode *C = new ListNode((A->val + B->val) % 10);
            ListNode *tail = C;
            A = A->next;
            B = B->next;
            while(A!=NULL && B!=NULL)
            {
                ListNode *x = new ListNode((A->val + B->val + carry) % 10);
                tail->next = x;
                tail = x;
                carry = (A->val + B->val + carry) / 10;
                A = A->next;
                B = B->next;
            }
            if(A==NULL && B==NULL)
            {
                if(carry >0)
                {
                ListNode *x = new ListNode(carry);
                tail->next = x;
                tail = x;
                }
            }
            else if(A==NULL)
            {
                while(B!=NULL){
                ListNode *x = new ListNode((B->val + carry) % 10);
                tail->next = x;
                tail = x;
                carry=(B->val + carry) / 10;
                B=B->next;
                }
                if(carry >0)
                {
                ListNode *x = new ListNode(carry);
                tail->next = x;
                tail = x;
                }
            }
            else
            {
                while(A!=NULL){
                ListNode *x = new ListNode((A->val + carry) % 10);
                tail->next = x;
                tail = x;
                carry=(A->val + carry) / 10;
                A=A->next;
                }
                if(carry >0)
                {
                ListNode *x = new ListNode(carry);
                tail->next = x;
                tail = x;
                }
            }
            return C;
}
