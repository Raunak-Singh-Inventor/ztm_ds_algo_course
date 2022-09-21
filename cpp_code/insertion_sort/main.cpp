#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> arr) {
    for(int i = 1; i < arr.size(); i++) {
        int counter = i;
        while(arr[counter-1] > arr[counter] && counter>=0) {
            int tmp = arr[counter];
            arr[counter] = arr[counter-1];
            arr[counter-1] = tmp;
            counter--;
        }
    }
    return arr;
}

int main() {
    vector<int> res = insertionSort({99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0});
    for(auto i: res) {
        cout << i << " ";
    }
    return 0;
}
