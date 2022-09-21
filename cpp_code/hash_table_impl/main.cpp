#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashTable {
private:
    struct keyValuePair {
        string key;
        int value;
    };
    vector<vector<keyValuePair>> data;

    inline int _hash(string key) {
        int hash = 0;
        for(int i = 0; i < key.size(); i++) {
            hash = (hash + key[i] * i) % this->data.size();
            // cout << hash << endl;
        }
        return hash;
    } // O(1)
public:
    HashTable(int size) {
        this->data.resize(size);
    }

    void set(string key, int value) {
        int hash = _hash(key);
        data[hash].push_back(keyValuePair {key, value});
    } // O(1)

    int get(string key) {
        int hash = _hash(key);
        vector<keyValuePair> arr = data[hash];
        for(auto pair: arr) {
            if(pair.key==key) {
                return pair.value;
            }
        }
        return -1;
    } // O(1) assuming no collision, if collision it can become O(n)

    vector<string> keys() {
        vector<string> keys;
        for(auto i: data) {
            for(auto pair: i) {
                keys.push_back(pair.key);
            }
        }
        return keys;
    } // O(n*k), two for loops slow
};

int main() {
    HashTable myHashTable = HashTable(50);
    myHashTable.set("grapes", 10000);
    myHashTable.set("apples", 54);
    myHashTable.set("oranges", 2);
    vector<string> keys = myHashTable.keys();
    cout << "myHashTable: " << endl;
    for(auto i: keys) {
        cout << "   \"" << i << "\" : ";
        cout << myHashTable.get(i) << endl;
    }

    return 0;
}
