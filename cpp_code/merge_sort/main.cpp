#include <iostream>
#include <vector>

using namespace std;

/*
 * Steps for Merge Sort algorithm:
 * Break down the array into sub-arrays of the individual elements
 * "Reconstruct" the array by comparing each sub-array
 * example:
 * {6} {5} {3} {1} {8} {7} {2} {4}
 *    {5,6} {1,3} {7,8} {2,4}
 *      {1,3,5,6} {2,4,7,8}
 *       {1,2,3,4,5,6,7,8}    DONE
 */

vector<int> mergeSort(vector<int> arr) {
    if(arr.size()==1) {
        return arr;
    }

    vector<int> arr1 = vector<int>(arr.begin(), arr.end()-arr.size()/2);
    for(auto i: arr1)
    return arr;
}

int main() {
    vector<int> res = mergeSort({6,5,3,1,8,7,2,4});

    return 0;
}
