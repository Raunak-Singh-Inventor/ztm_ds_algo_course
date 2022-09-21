#include <iostream>
#include <vector>

using namespace std;

vector<int> selectionSort(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        int smallest_idx = i;
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[i] > arr[j]) {
                smallest_idx = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[smallest_idx];
        arr[smallest_idx] = tmp;
    }
    return arr;
}

int main() {
    vector<int> res = selectionSort({99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0});
    for(auto i: res) {
        cout << i << " ";
    }
    return 0;
}
