#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSortedArrays(vector<int> arr1, vector<int> arr2) {
    int min_index = 0;
    for(int i = 0; i < arr1.size(); i++) {
        if(min_index<arr2.size()  && arr1[i]>arr2[min_index]) {
            arr1.insert(arr1.begin()+i, arr2[min_index]);
            min_index++;
        }
    }
    return arr1;
}

int main() {
    vector<int> arr = mergeSortedArrays({0,3,4,31},{4,6,30});
    for(auto i: arr) {
        cout << i << endl;
    }
    return 0;
}
