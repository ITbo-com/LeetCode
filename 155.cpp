#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
    stack<int> s1;
    stack<int> ms;
    MinStack() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void push(int value) {
        s1.push(value);
        if(ms.empty() || ms.top() >= value)
            ms.push(value);
    }
    
    void pop() {
        if(s1.top() == ms.top())    
            ms.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return ms.top();
    }
};
