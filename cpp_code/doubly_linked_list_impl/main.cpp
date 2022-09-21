#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    int length = 0;
public:
    LinkedList(int val) {
        head = new Node(val);
        tail = head;
        length++; // to count the head node
    }
    void traverse() {
        Node* curr = head;
        while(curr!=nullptr) {
            cout << curr->val << " --> ";
            curr = curr->next;
        }
        cout << "nullptr" << endl;
        delete curr;
    }

    void prepend(int val) {
        Node* curr = head;
        head = new Node(val);
        head->next = curr;
        curr->prev = head;
        length++;
    }

    void append(int val) {
        Node* curr = tail;
        tail = new Node(val);
        curr->next = tail;
        tail->prev = curr;
        length++;
    }

    int lookup(int val) {
        Node* curr = head;
        int index = 0;
        while(curr!=nullptr && curr->val!=val) {
            curr = curr->next;
            index++;
        }
        if(curr==nullptr) {
            return -1;
        } else {
            return index;
        }
    }

    void insert(int val, int index) {
        if(index==0) {
            prepend(val);
            return;
        }
        Node* curr = head;
        for(int i = 0; i < index-1; i++) {
            if(curr->next!=nullptr) {
                curr = curr->next;
            } else {
                cerr << "index out of range" << endl;
                return;
            }
        }
        // cout << curr->val << endl;
        Node* tmp = curr->next;
        Node* node_to_insert = new Node(val);
        curr->next = node_to_insert;
        node_to_insert->prev = curr;
        node_to_insert->next = tmp;
        if(tmp!=nullptr) {
            tmp->prev = node_to_insert;
        }
        length++;
    }

    void del(int index) {
        Node* curr = head;
        if(index == 0) {
            head = head->next;
            delete curr;
            return;
        }
        for(int i = 0; i < index-1; i++) {
            if(curr->next!=nullptr) {
                curr = curr->next;
            } else {
                cerr << "index out of range" << endl;
                return;
            }
        }
        // cout << curr->val << endl;
        Node* tmp = curr->next->next;
        if(curr->next==tail) {
            tail = curr;
        }
        // delete curr->next;
        curr->next = tmp;
        if(tmp!= nullptr) {
            tmp->prev = curr;
        }
        length--;
    }
};

int main() {
    LinkedList* myList = new LinkedList(10);
    myList->prepend(16);
    myList->append(5);
    int value_to_lookup = 5;
    cout << "value " << value_to_lookup << " was found at index " << myList->lookup(value_to_lookup) << endl;
    myList->insert(7, 2);
    myList->del(3);
    myList->traverse();
    cout << "length = " << myList->length << endl;
    delete myList;

    return 0;
}
