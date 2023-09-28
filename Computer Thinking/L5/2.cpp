#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

/// Requirements: scan one integer, print if:
/// 1: Stay at campus
/// 2: Go home
/// 3: Travel

int main() {
    int a;
    srand(time(0));
    a = rand() % 3 + 1;
    if (a == 1) {
        std::cout << "Stay at campus";
    } else if (a == 2) {
        std::cout << "Go home";
    } else if (a == 3) {
        std::cout << "Travel";
    } else {
        std::cout << "Invalid input";
    }

    /// Equivalent to switch statement:

    switch (a) {
        case 1:
            std::cout << "Stay at campus";
            break;
        case 2:
            std::cout << "Go home";
            break;
        case 3:
            std::cout << "Travel";
            break;
        default:
            std::cout << "Invalid input";
            break;
    }

    return 0;
}