#include <iostream>

int fibonacciIterative(int n) {
    int num1 = 0;
    int num2 = 1;
    if(n==0) {
        return 0;
    } else if(n==1) {
        return 1;
    }
    int counter = 2;
    while(counter < n) {
        int tmp = num2;
        num2+=num1;
        num1 = tmp;
        counter++;
    }
    return num1+num2;
}

int num1 = 0;
int num2 = 1;
int counter = 2;
int fibonacciRecursive(int n) {
    if(n==0) {
        return 0;
    } else if(n==1) {
        return 1;
    }
    if(counter < n) {
        int tmp = num2;
        num2+=num1;
        num1 = tmp;
        counter++;
        return fibonacciRecursive(n);
    }
    return num1+num2;
}

int main() {
    std::cout << fibonacciIterative(6) << std::endl;
    std::cout << fibonacciRecursive(6) << std::endl;
    return 0;
}
