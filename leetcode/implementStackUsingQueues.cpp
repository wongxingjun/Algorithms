class Stack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    // Push element x onto stack.
    void push(int x) {
         q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(q1.back()!=q1.front())
        {
            q2.push(q1.front());
            q1.pop();
        }
        int res=q1.front();
        q1.pop();
        queue<int> tmp;
        tmp=q1;
        q1=q2;
        q2=tmp;
    }

    // Get the top element.
    int top() {
        while(q1.back()!=q1.front())
        {
            q2.push(q1.front());
            q1.pop();
        }
        int res=q1.front();
        q2.push(q1.front());
        q1.pop();
        queue<int> tmp;
        tmp=q1;
        q1=q2;
        q2=tmp;
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};