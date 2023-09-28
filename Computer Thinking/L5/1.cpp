#include <iostream>
#include <cstdlib>
#include <cstdio>

/// Requirements: scan one integer, get the square of it, and print it to the console.

int main() {
    // C++-styled:
    int a;
    std::cin >> a;
    std::cout << a * a;

    /// C-styled:
    scanf("%d", &a);
    printf("%d", a * a);

    return 0;
}