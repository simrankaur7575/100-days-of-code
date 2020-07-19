/*
QUES - Merge k sorted linked lists and return it as one sorted list.
*/

if (A.empty()) return nullptr;
// build map
map<int, queue<ListNode*>> sorted;
//init map
for (ListNode* root : A)
{
if (root != nullptr)
{
sorted[root->val].push(root);
}
}

ListNode* result = nullptr;
ListNode* current = nullptr;

while (sorted.empty() == false)
{

auto min_iter = sorted.begin();
// start build result
if (result == nullptr)
{
  result = new ListNode(min_iter->first);
  current = result;
}
// update result
else
{
  ListNode* to_add = new ListNode(min_iter->first);
  current->next = to_add;
  current = to_add;
}
queue<ListNode*>& current_q = min_iter->second;
ListNode* current = current_q.front();
if (current_q.size() == 1) //last
{
  sorted.erase(min_iter);
}
// queue has duplicates
else
{
  current_q.pop();
}

if (current->next)
{
  ListNode* to_add = current->next;
  if (sorted.find(to_add->val) == sorted.end())
  {
    sorted[to_add->val] = queue<ListNode*>();
  }
  sorted[to_add->val].push(to_add);
}
}

return result;
}