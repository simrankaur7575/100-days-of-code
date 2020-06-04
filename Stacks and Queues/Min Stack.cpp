/*
QUES - Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
*/
stack<int> s;
MinStack::MinStack() {
    while (!s.empty())
    s.pop();
}

void MinStack::push(int x) {
    if (s.empty()){
        s.push(x);
        s.push(x);}
    else{
        int y=s.top();
        s.push(x);
        if (y<x){
            s.push(y);
        }
        else{
            s.push(x);
        }
    }
}

void MinStack::pop() {
    if (!s.empty()){
        s.pop();
        s.pop();
    }
}

int MinStack::top() {
    if (s.empty())
    return -1;
    int x=s.top();
    s.pop();
    int y=s.top();
    s.push(x);
    return y;
}

int MinStack::getMin() {
     if (s.empty())
    return -1;
    return s.top();
}