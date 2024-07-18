class MyQueue {
private:
    stack<int> s1, s2;

    void shiftStacks() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        shiftStacks();
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        shiftStacks();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};