#include <iostream>

int product = 1;
int findFactorialRecursive(int num) {
    if(num==0) {
        return product;
    }
    product *= num;
    return findFactorialRecursive(num-1);
}

int findFactorialIterative(int num) {
    int product = 1;
    while(num!=0) {
        product*=num;
        num--;
    }
    return product;
}

int main() {
    std::cout << findFactorialIterative(5) << std::endl;
    std::cout << findFactorialRecursive(5) << std::endl;
    return 0;
}
