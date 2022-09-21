#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Raunak Singh Inventor";
    for(int i = 0; i < s.size()/2; i++) {
        char tmp = s[i];
        s[i] = s[s.size()-i-1];
        s[s.size()-i-1] = tmp;
    }
    cout << s << endl;
    return 0;
}
