#include <iostream>

using namespace std;

/// Requirements: print sum of two integers.

int sum(int a, int b) {
    return a + b;
}

/// [a] could be of any size.
int sum_all(int* a) {
    int sum = 0;
    for (int i = 0; i < sizeof(a); i += 1) {
        sum = sum + a[i];
    }
    return sum;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << sum(a, b);
}