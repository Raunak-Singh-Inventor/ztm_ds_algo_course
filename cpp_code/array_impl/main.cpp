#include <iostream>
#include <map>

using namespace std;

class MyArray {
private:
    int length = 0;
    map<int,string> data;
public:
    MyArray() {
        this->length = 0;
        this->data = {};
    }

    map<int,string> get(int index) {
        return this->data;
    }

    // lookup
    string lookup(int index) {
        return this->data[index];
    }

    // push
    void push_back(string x) {
        this->data[length] = x;
        length++;
    }

    // pop
    void pop() {
        del(length-1);
        length--;
    }

    // insert
    void insert(int index, string x) {
        for(int i = length-1; i >= index; i--) {
            this->data[i+1] = this->data[i];
        }
        this->data[index] = x;
        length++;
    }

   // delete
   string del(int index) {
        string value = this->data[index];
        for(int i = index; i < length - 1; i++) {
            this->data[i] = this->data[i+1];
        }
        this->data.erase(this->data.find(length-1)); // find returns iterator to where key is found in map
        length--;
        return value;
   }

   void print() {
        for(auto &p: this->data) {
            cout << p.first << ": ";
            cout << p.second << endl;
        }
        cout << endl;
    }
};

int main() {
    MyArray array = MyArray();

    array.push_back("hi");
    array.push_back("you");
    array.push_back("!");
    array.del(0);
    array.push_back("are");
    array.push_back("nice");
    string del_value = array.del(1);
    array.insert(2, del_value);
    array.pop();
    array.print();

    return 0;
}
