#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    MyQueue() {

    }

    void push(int x) {
        if(stack1.empty()) {
            stack1.push(x);
            return;
        }

        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }

        stack1.push(x);
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int pop() {
        int del_val = stack1.top();
        stack1.pop();
        return del_val;
    }

    int peek() {
        return stack1.top();
    }

    bool empty() {
        if(stack1.size()==0) {
            return true;
        }
        return false;
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    cout << param_2 << ", " << param_3 << ", " << param_4 << endl;
    return 0;
}
