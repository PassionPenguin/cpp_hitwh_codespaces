#include <iostream>
using namespace std;

static bool isInRecursion = false;

/// Requirement: use recursion to calculate sum of 0 to 99.
///
/// Note that the recursion function overrided [argc] and [argv].
/// Plus according to C++ standard, one should not call the main function 
/// within the program. Thus, the program is not promised to be runnable
/// in all platforms.
///
/// Though, in C, given that no relevant restrction is imposed, the program 
/// shall be a validated one.

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