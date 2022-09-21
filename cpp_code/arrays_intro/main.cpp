#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<string> foo) {
    for(int i = 0; i < foo.size(); i++) {
        cout << foo[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<string> foo = {"a","b","c","d"};
    // 4 * 8 =  32 bytes of storage

    cout << foo[2] << endl; // O(1)

    // push
    foo.push_back("e"); // O(1)

    // pop
    foo.pop_back();
    foo.pop_back(); // O(1)

    // push to the front of the array
    foo.insert(foo.begin(), "x"); // O(n)

    // push to middle of the array
    foo.insert(foo.begin()+2, "alien"); // O(n)

    printVector(foo);

    return 0;
}
