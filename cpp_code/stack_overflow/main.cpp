#include <iostream>

using namespace std;

static int counter = 0;

string inception() {
    cout << "breakpoint" << endl;
    if(counter > 3) {
        return "done!";
    }
    counter++;
    return inception();
}

int main() {
    cout << inception() << endl;
    return 0;
}
