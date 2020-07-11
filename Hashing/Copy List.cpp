/*
QUES - A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.
*/
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    
    
    if(A==NULL) return NULL;
    
    unordered_map<RandomListNode*,RandomListNode*> mp;
    
    RandomListNode* B=A;
    while(B!=NULL)
    {
        RandomListNode* temp=new RandomListNode(B->label);
        mp[B]=temp;
        B=B->next;
    }
    mp[NULL]=NULL;
    B=A;
    while(B!=NULL)
    {
        mp[B]->next=mp[B->next];
        mp[B]->random=mp[B->random];
        B=B->next;
    }
    return mp[A];
}