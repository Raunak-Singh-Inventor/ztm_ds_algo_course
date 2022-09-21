#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<string> stack;
public:
    void push(string value) {
        stack.push_back(value);
    }

    string peek() {
        return stack[stack.size() - 1];
    }

    string pop() {
        string tmp = stack[stack.size() - 1];
        stack.erase(stack.end()-1);
        return tmp;
    }

    int len() {
        return stack.size();
    }
};

int main() {
    auto* myStack = new Stack();
    myStack->push("google");
    myStack->push("udemy");
    myStack->push("discord");
    while(myStack->len()>0) {
        cout << "popped element: " << myStack->pop() << endl;
        cout << "peek the next element to be popped: " << myStack->peek() << endl;
    }
    return 0;
}
