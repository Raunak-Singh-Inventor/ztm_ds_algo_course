#include <iostream>
#include<vector>

using namespace std;

vector<int> bubbleSort(vector<int> arr) {
    for(auto counter: arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = tmp;
            }
        }
    }
    return arr;
}

int main() {
    vector<int> res = bubbleSort({99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0});
    for(auto i: res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
