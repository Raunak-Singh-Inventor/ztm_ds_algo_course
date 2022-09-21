#include <iostream>
#include <vector>
#include <map>

using namespace std;

int getFirstRecurringChar(vector<int> arr) {
    map<int, int> char_map;
    for(auto i: arr) {
        if(!char_map[i]) {
            char_map[i] = 1;
        } else {
            char_map[i]++;
            return i;
        }
    }
    return -1;
}

int main() {
    cout << getFirstRecurringChar({2,5,1,2,3,5,1,2,4}) << endl;
    cout << getFirstRecurringChar({2,1,1,2,3,5,1,2,4}) << endl;
    cout << getFirstRecurringChar({2,3,4,5}) << endl;
    return 0;
}
