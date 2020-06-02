/*
QUES - Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
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
    

  int Solution::lPalin(ListNode* head) 
{

    ListNode *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL) 
    {
         slow=slow->next;
        fast=fast->next->next;
       
        
    }
    ListNode *rev=reverse(slow);
    ListNode *org=head;
    
    while(org !=NULL && rev !=NULL )
    {
        if(org->val==rev->val)
        {
            org=org->next;
            rev=rev->next;
        }
            else{
                return false;
            }
        
    }
    return true;
    
}
