#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> basket = {2,65,34,2,1,7,8};
    sort(basket.begin(), basket.end());
    for(auto i: basket) {
        cout << i << " ";
    }
    return 0;
}
