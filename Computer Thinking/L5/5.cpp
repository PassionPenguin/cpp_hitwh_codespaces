#include <iostream>
using namespace std;

static bool isInRecursion = false;

/// Requirement: use recursion to calculate sum of 0 to 99.
///
/// Note that the recursion function is not following the C++ standard strictly (overriding [argc] and [argv]). It is not a good practice.

int main(int argc, char *argv[]) {
    /// Code hereby marks the body of the recursion.
    if(isInRecursion){
        /// Base case.
        if(argc == 0) {
            return 0;
        }
        /// Recursive case.
        else {
            return argc + main(argc - 1, {});
        }
    } else {
        isInRecursion = true;
        cout << main(100, {}) << endl;
        return 0;
    }
}