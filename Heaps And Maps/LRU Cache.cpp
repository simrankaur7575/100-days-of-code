/*
QUES - Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.
*/
#include <list> 
list<int> dq;
map<int,int> m;
int s;

LRUCache::LRUCache(int capacity) {

s = capacity;
dq.clear();
m.clear();

}

int LRUCache::get(int key) {

if(m.find(key)!=m.end())
{
    dq.remove(key);
    dq.push_back(key);
    return m[key];
}

else
{
    return -1;
}
}

void LRUCache::set(int key, int value) {

if(dq.size()==s)
{
    if(m.find(key)!=m.end())
    {
        dq.remove(key);
        dq.push_back(key);
        m[key] = value;
    }
    
    else
    {
        m.erase(dq.front());
        dq.pop_front();
        dq.push_back(key);
        m[key] = value;
    }
}

else
{
    if(m.find(key)!=m.end())
    {
        dq.remove(key);
        dq.push_back(key);
        m[key] = value;
    }
    else
    {
        dq.push_back(key);
        m[key] = value;
        
    }
    
}
}