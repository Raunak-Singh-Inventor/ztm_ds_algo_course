#include <iostream>

using namespace std;

class Node {
public:
    string value;
    Node* next;
public:
    Node(string value) {
        this->value = value;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top = nullptr;
    Node* bottom = nullptr;
    int length = 0;
public:
    Node* peek() {
        return top;
    }

    void push(string value) {
        Node* node_to_insert = new Node(value);
        if(top==nullptr && bottom==nullptr) {
            top = node_to_insert;
            bottom = node_to_insert;
            return;
        }
        Node* tmp = top;
        node_to_insert->next = tmp;
        top = node_to_insert;
    }

    Node* pop() {
        Node* tmp = top;
        top = top->next;
        return tmp;
    }
};

int main() {
    Stack* myStack = new Stack();
    myStack->push("google");
    myStack->push("udemy");
    myStack->push("discord");
    while(myStack->peek() != nullptr) {
        cout << myStack->pop()->value << endl;
    }
    return 0;
}
