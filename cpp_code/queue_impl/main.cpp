#include <iostream>

using namespace std;

class Node {
public:
    string value;
    Node* next;

    Node(string value) {
        this->value = value;
        this->next = nullptr;
    }
};

class Queue {
private:
    Node* first = nullptr;
    Node* last = nullptr;
    int length = 0;
public:
    Node* peek() {
        return first;
    }

    Node* enqueue(string value) {
        Node* node_to_insert = new Node(value);
        length++;
        if(first == nullptr && last == nullptr) {
            first = node_to_insert;
            last = node_to_insert;
            return node_to_insert;
        }
        Node* tmp = last;
        tmp->next = node_to_insert;
        last = node_to_insert;
        return last;
    }

    Node* dequeue() {
        Node* tmp = first;
        first = first->next;
        length--;
        return tmp;
    }

    bool isEmpty() {
        if(length==0) {
            return true;
        }
        return false;
    }
};

int main() {
    Queue* myQueue = new Queue();
    cout << "Turning on WebServer" << endl;
    cout << "Receiving ping request from " << myQueue->enqueue("Raunak's iPhone 13 Pro")->value << endl;
    cout << "Receiving ping request from " << myQueue->enqueue("Raunak's MacBook Air 2018")->value << endl;
    cout << "Receiving ping request from " << myQueue->enqueue("Raunak's iPad Air")->value << endl;
    cout << "--------------------------------------------------------" << endl;
    while(!myQueue->isEmpty()) {
        cout << "going to ping " << myQueue->peek()->value << endl;
        cout << "pinging " << myQueue->dequeue()->value << endl;
    }
    cout << "Turning off WebServer" << endl;
    return 0;
}
